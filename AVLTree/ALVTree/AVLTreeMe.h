#pragma once
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class K, class V>
struct ALVTreeNode
{
	// 需要parent指针，后续更新平衡因子可以看到
	pair<K, V> _kv;
	ALVTreeNode<K, V>* _parent;
	ALVTreeNode<K, V>* _left;
	ALVTreeNode<K, V>* _right;
	int _bf;// 平衡因子

	ALVTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _bf(0)
	{
	}
};

template<class K, class V>
class ALVTree
{
	typedef ALVTreeNode<K, V> Node;
public:
	
	bool Insert(const pair<K, V>& kv)
	{
		// 树为空，直接创建根节点
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// 树非空，按BST规则找插入位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else return false;
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;// 插入值比parent大，作为右孩子
		}
		else {
			parent->_left = cur; // 插入值比parent小，作为左孩子
		}
		cur->_parent = parent;

		// 更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				// parent所在的子树高度不变，不会再影响上一层，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent -> _bf == -1)
			{
				// parent 所在的子树高度变了，会再影响上一层，继续往上面更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// parent 所在的子树已经不平衡了，需要旋转处理
				// 右单旋
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				// 左单旋
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				//左右双旋
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				//右左双旋
				else
				{
					RotateRL(parent);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* grandparent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;
	
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			if (grandparent->_left == parent)
				grandparent->_left = subL;
			else
				grandparent->_right = subL;

			subL->_parent = grandparent;
		}
		parent->_bf = subL->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* grandparent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (grandparent->_left == parent)
				grandparent->_left = subR;
			else
				grandparent->_right = subR;

			subR->_parent = grandparent;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}

		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}

		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		
		RotateR(parent->_right);
		RotateL(parent);
		
		if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}

		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}

		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
	}
private:
	Node* _root;
};