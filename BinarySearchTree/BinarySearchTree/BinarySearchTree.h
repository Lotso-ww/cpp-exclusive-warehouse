#include<iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

// 不允许相等的值插入
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else return false;
//		}
//		cur = new Node(key);
//		if (parent->_key < key)
//		{
//			parent->_right = cur;
//		}
//		else {
//			parent->_left = cur;
//		}
//
//		return true;
//	}
//
//	bool Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else return true;
//		}
//		return false;
//	}
//
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else {
//				//删除操作
//				if (cur->_left == nullptr)
//				{
//					if (cur == _root)
//					{
//						_root = cur->_right;
//					}
//					else 
//					{
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_right;
//						}
//						else {
//							parent->_right = cur->_right;
//						}
//					}
//					delete cur;
//					return true;
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (cur == _root)
//					{
//						_root = cur->_left;
//					}
//					else {
//						if (cur == parent->_left)
//						{
//							parent->_left = cur->_left;
//						}
//						else {
//							parent->_right = cur->_left;
//						}
//					}
//					delete cur;
//					return true;
//				}
//				else {
//					//左右孩子都不为空
//					//右孩子最小的
//					Node* replaceparent = cur;
//					Node* replace = cur->_right;
//					while (replace->_left)
//					{
//						replaceparent = replace;
//						replace = replace->_left;
//					}
//					cur->_key = replace->_key;
//					if (replaceparent->_left == replace)
//						replaceparent->_left = replace->_right;
//					else
//						replaceparent->_right = replace->_right;
//
//					delete replace;
//					return true;
//				}
//			}
//		}
//
//		return true;
//	}
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//private:
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		_InOrder(root->_left);
//		cout << root->_key <<" ";
//		_InOrder(root->_right);
//	}
//	Node* _root = nullptr;
//};

//template<class k>
//struct BSTreeNode
//{
//	BSTreeNode<k>* _left;
//	BSTreeNode<k>* _right;
//	k _key;
//
//	BSTreeNode(const k& key)
//		:_left(nullptr)
//		,_right(nullptr)
//		,_key(key)
//	{}
//};
//
template<class k>
class BSTree
{
	typedef BSTreeNode<k> Node;
public:
	bool Insert(const k& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else return false;
		}
		cur = new Node(key);
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;

		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	Node* _root = nullptr;

};