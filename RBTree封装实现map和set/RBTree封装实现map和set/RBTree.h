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
template<class T>
struct RBTreeNode
{
	T _data;				 //存储实际数据（K或pair<const K, V>）
	RBTreeNode<T>* _parent;  // 左子节点指针
	RBTreeNode<T>* _left;    // 右子节点指针
	RBTreeNode<T>* _right;   // 父节点指针（回溯平衡需用到）
	Colour _col;			 // 节点颜色

	RBTreeNode(const T& data)
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _data(data)
		, _col(Red) // 非空树插入时设为红色，避免破坏规则4
	{}
};


template<class T,class Ref,class Ptr>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	RBTreeIterator(Node* node)
		:_node(node)
	{}

	Self& operator++()
	{
		if (_node->_right)
		{
			Node* minRight = _node->_right;
			while (minRight->_left)
			{
				minRight = minRight->_left;
			}
			_node = minRight;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Ref operator* ()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator-(const Self& s) const
	{
		return _node == s._node;
	}
};

// RBTree<K, pair<K, V>> _t;-> // map
// RBTree<K, K> _t;->		   // set

template<class K, class T,class KeyofT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;
	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}

	void Destory(Node* root)
	{
		if (root == nullptr)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	Iterator Begin()
	{
		Node* minLeft = _root;
		while (minLeft && minLeft->_left)
		{
			minLeft = minLeft->_left;
		}
		return Iterator(minLeft);
	}

	Iterator End()
	{
		return Iterator(nullptr);
	}

	ConstIterator Begin() const
	{
		Node* minLeft = _root;
		while (minLeft && minLeft->_left)
		{
			minLeft = minLeft->_left;
		}
		return ConstIterator(minLeft);
	}

	ConstIterator End() const
	{
		return ConstIterator(nullptr);
	}

	pair<Iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = Black;
			return { Iterator(_root),true };
		}

		KeyofT kot;
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			//else if (kot(cur->_data) > kot(data))
			else if (kot(data) < kot(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return {Iterator(cur),false};
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = Red;
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == Red)
		{
			Node* grandparent = parent->_parent;
			if (grandparent->_left == parent)
			{
				Node* uncle = grandparent->_right;
				// uncle存在且为红色
				if (uncle && uncle->_col == Red)
				{
					// 变色+继续向上处理
					parent->_col = Black;
					uncle->_col = Black;
					grandparent->_col = Red;

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
						//   g
						// p   u
						//  c
						RotateL(parent);
						RotateR(grandparent);

						cur->_col = Black;
						grandparent->_col = Red;
					}
					break;
				}
			}

			else
			{
				Node* uncle = grandparent->_left;
				if (uncle && uncle->_col == Red)
				{
					// 变色+继续向上处理
					uncle->_col = Black;
					parent->_col = Black;
					grandparent->_col = Red;

					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_right == cur) // 单旋+变色
					{
						//   g
						// u   p
						//      c
						RotateL(grandparent);

						parent->_col = Black;
						grandparent->_col = Red;
					}
					else // 双旋+变色
					{
						//   g
						// u   p
						//   c

						RotateR(parent);
						RotateL(grandparent);

						cur->_col = Black;
						grandparent->_col = Red;
					}

					break;
				}
			}
		}
		// 确保根节点始终为黑色（防止回溯时根被设为红色）
		_root->_col = Black;

		return {Iterator(newnode),true};
	}

	Iterator* Find(const K& key) 
	{
		KeyofT kot;
		Node* cur = _root;
		while (cur) {
			if (kot(cur->_data) < key) {
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key) {
				cur = cur->_left;
			}
			else {
				return Iterator(cur);  // 找到，返回节点指针
			}
		}
		return End();  // 未找到
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
public:
	bool IsBalanceTree()
	{
		if (_root && _root->_col == Red)
			return false;

		// 最左路径黑色节点的数量做参考值去比较其它路径
		int left_bn = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == Black)
				left_bn++;

			cur = cur->_left;
		}

		return _Checkcolour(_root, 0, left_bn);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int Height()
	{
		return _Height(_root);
	}

	int Size()
	{
		return _Size(_root);
	}
private:
	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		//cout << root->_kv.first << ":" << root->_kv.second << endl;
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	// root_cur_bn 根到当前节点路径上黑色节点的数量
	// 前序递归
	bool _Checkcolour(Node* root, int root_cur_bn, const int left_bn)
	{
		if (root == nullptr)
		{
			// 检查每条路径的黑色节点数量
			if (root_cur_bn != left_bn)
			{
				cout << "黑色节点的数量不相等" << endl;
				return false;
			}

			return true;
		}

		if (root->_col == Black)
		{
			root_cur_bn++;
		}

		// 检查连续的红色节点
		if (root->_col == Red && root->_parent && root->_parent->_col == Red)
		{
			cout << root->_kv.first << "存在连续红色节点" << endl;
			return false;
		}

		return _Checkcolour(root->_left, root_cur_bn, left_bn)
			&& _Checkcolour(root->_right, root_cur_bn, left_bn);
	}
private:
	Node* _root = nullptr;
};