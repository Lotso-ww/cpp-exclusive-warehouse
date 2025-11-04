#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


// 枚举结点颜色
enum Colour
{
	Red,  // 红色结点
	Black // 黑色结点
};

// 红黑树结构
template<class K,class V>
struct RBTreeNode
{
	pair<K, V> _kv;				// 存储键值对（Key-Value）
	RBTreeNode<K, V>* _parent;  // 左子节点指针
	RBTreeNode<K, V>* _left;    // 右子节点指针
	RBTreeNode<K, V>* _right;   // 父节点指针（回溯平衡需用到）
	Colour _col;				// 节点颜色

	RBTreeNode(const pair<K, V>& kv)
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		,_kv(kv)
		, _col(Red) // 非空树插入时设为红色，避免破坏规则4
	{}
};

// 红黑树类
template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = Black;
			return true;
		}
		
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
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = Red;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent->_col == Red)
		{
			Node* grandparent = parent->_parent;
			if (grandparent->_left == parent)
			{
				//   g
				// p   u
				//c
				Node* uncle = grandparent->_right;
				// uncle存在且为红色
				if (uncle && uncle->_col == Red)
				{
					// 变色+继续向上处理
					parent->_col = Black;
					uncle->_col = Black;

					cur = grandparent;
					parent = cur->_parent;
				}
				else //uncle不存在或者存在且为黑色 
				{
					if (cur == parent->_left) // 单旋+变色
					{
						//   g
						// p   u
						//c
						RotateR(grandparent);
						parent->_col = Black;
						grandparent->_col = Red;
					}
					else // 双旋+变色
					{

					}
				}
			}
		}
	}
private:
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

		if (_root == parent)
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
	}

	//void RotateLR(Node* parent)
	//{
	//	Node* subL = parent->_left;
	//	Node* subLR = subL->_right;

	//	RotateL(subL);
	//	RotateR(parent);

	//}

	//void RotateRL(Node* parent)
	//{
	//	Node* subR = parent->_right;
	//	Node* subRL = subR->_left;
	//	
	//	RotateR(subR);
	//	RotateL(parent);
	//}
private:
	Node* _root = nullptr;
};