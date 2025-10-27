#include<iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;  // 左子树指针
	BSTreeNode<K>* _right; // 右子树指针
	K _key;                // 节点键值

	// 构造函数：初始化指针为空，键值为传入值
	BSTreeNode(const K& key)
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

// 不允许相等的值插入
template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		// 情况1：树为空，直接创建根节点
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		// 情况2：树非空，遍历找插入位置
		Node* parent = nullptr;// 记录cur的父节点（用于后续链接新节点）
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right; // 比当前节点大，向右走
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;// 比当前节点小，向左走

			}
			else return false;// 值已存在，不支持插入，返回false
		}

		// 创建新节点，并链接到parent的左/右孩子
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;// 插入值比parent大，作为右孩子
		}
		else {
			parent->_left = cur; // 插入值比parent小，作为左孩子
		}

		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;// 目标值大，向右找
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;// 目标值小，向左找
			}
			else return true;// 找到目标值，返回true
		}
		// 遍历到空，未找到
		return false;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		// 第一步：找到要删除的节点cur
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
			else {
				//删除操作
				// 第二步：找到节点，按子节点情况处理删除
				// 情况2：左子树为空，右子树非空
				if (cur->_left == nullptr)
				{
					// 若cur是根节点，直接让根指向右子树
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else 
					{
						// 判断cur是parent的左/右孩子，链接对应子树
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else {
							parent->_right = cur->_right;
						}
					}
					delete cur;// 释放节点内存
					return true;
				}
				// 情况3：右子树为空，左子树非空
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else {
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else {
							parent->_right = cur->_left;
						}
					}
					delete cur;
					return true;
				}
				// 情况4：左右子树均非空（替换法删除）
				else {
					// 找cur右子树的最小节点（最左节点）作为替换节点
					// 还可以找左子树的最大节点(最右节点)
					// 这里是找右子树最左节点
					Node* replaceparent = cur;// 替换节点的父节点
					Node* replace = cur->_right;
					while (replace->_left)// 一直向左走，直到左子树为空
					{
						replaceparent = replace;
						replace = replace->_left;
					}

					// 替换：将replace的键值赋给cur（值替换，指针不变）
					cur->_key = replace->_key;

					// 删除replace节点（replace的左子树为空，符合情况2）
					if (replaceparent->_left == replace)
						replaceparent->_left = replace->_right;
					else
						replaceparent->_right = replace->_right;

					delete replace;
					return true;
				}
			}
		}

		// 未找到要删除的节点
		return false;
	}

	// 中序遍历：验证BST的有序性
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
		_InOrder(root->_left); // 遍历左子树
		cout << root->_key <<" ";// 访问当前节点
		_InOrder(root->_right);// 遍历右子树
	}
	Node* _root = nullptr;// 树的根节点，初始为空
};

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

//template<class k>
//class BSTree
//{
//	typedef BSTreeNode<k> Node;
//public:
//	bool Insert(const k& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
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
//			parent->_right = cur;
//		else
//			parent->_left = cur;
//
//		return true;
//	}
//
//	bool Find(const k& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//				cur = cur->_right;
//			else if (cur->_key > key)
//				cur = cur->_left;
//			else return true;
//		}
//		return false;
//	}
//
//	bool Erase(const k& key)
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
//			else
//			{
//				//删除逻辑
//				if (cur->_left == nullptr)
//				{
//					if (cur == _root) _root = cur->_right;
//					else {
//						if (parent->_left == cur)
//							parent->_left = cur->_right;
//						else
//							parent->_right = cur->_right;
//					}
//					delete cur;
//					return true;
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (cur == _root)
//						_root = cur->_left;
//					else {
//						if (parent->_left == cur)
//							parent->_left = cur->_left;
//						else
//							parent->_right = cur->_left;
//					}
//					delete cur;
//					return true;
//				}
//				else {
//					//左右孩子都存在
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
//		return false;
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
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//
//	Node* _root = nullptr;
//
//};