#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	// 需要parent指针，后续更新平衡因子可以看到
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	int _bf;// 平衡因子

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	bool Insert(const pair<K,V>& kv)
	{
		// 情况1：树为空，直接创建根节点
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		// 情况2：树非空，遍历找插入位置
		Node* parent = nullptr;// 记录cur的父节点（用于后续链接新节点）
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right; // 比当前节点大，向右走
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;// 比当前节点小，向左走

			}
			else return false;// 值已存在，不支持插入，返回false
		}

		// 创建新节点，并链接到parent的左/右孩子
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;// 插入值比parent大，作为右孩子
		}
		else {
			parent->_left = cur; // 插入值比parent小，作为左孩子
		}

		cur->_parent = parent;

		// 更新平衡因子（从新节点的父节点开始向上）
		while (parent)
		{
			// 更新当前父节点的平衡因子
			if (cur == parent->_left)
			{
				// 新节点在父节点的左子树 → 左子树高度+1 → 平衡因子-1
				parent->_bf--;
			}
			else
			{
				// 新节点在父节点的右子树 → 右子树高度+1 → 平衡因子+1
				parent->_bf++;
			}

			// 根据平衡因子判断是否继续更新或旋转
			if (parent->_bf == 0)
			{
				// parent所在的子树高度不变，不会再影响上一层，更新结束
				// 平衡因子变为0 → 父节点子树高度不变（插入前左 / 右高1，插入后平衡）
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// parent 所在的子树高度变了，会再影响上一层，继续往上面更新
				// 平衡因子变为1 / -1 → 父节点子树高度 + 1（插入前平衡，插入后单侧高1）
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// parent 所在的子树已经不平衡了，需要旋转处理
				// 平衡因子变为2 / -1 → 父节点子树失衡，需旋转恢复平衡
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					// 父节点BF=-2（左子树高），当前节点BF=-1（左子树高）→ 右单旋
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					// 父节点BF=2（右子树高），当前节点BF=1（右子树高）→ 左单旋
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					// 父节点BF=-2（左子树高），当前节点BF=1（右子树高）→ 左右双旋
					RotateLR(parent);
				}
				else
				{
					// 父节点BF=2（右子树高），当前节点BF=-1（左子树高）→ 右左双旋
					RotateRL(parent);
				}
				// 旋转后，失衡子树高度恢复到插入前，不会影响上层，更新结束
				break;
			}
			else
			{
				// 异常情况：平衡因子为其他值（如3、-3)
				assert(false);
			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left; // parent的左子树（即将成为新根）
		Node* subLR = subL->_right; // subL的右子树（需转移给parent）

		// 步骤1：将subLR作为parent的左子树
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* grandparent = parent->_parent; // parent的父节点（祖父节点）

		// 步骤2：将parent作为subL的右子树
		subL->_right = parent;
		parent->_parent = subL;

		// 步骤3：链接subL与祖父节点（或更新根节点）
		if (parent == _root)
		{
			// parent是根节点，则subL成为新根
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			// parent是祖父节点的左/右孩子，对应链接subL
			if (grandparent->_left == parent)
				grandparent->_left = subL;
			else
				grandparent->_right = subL;

			subL->_parent = grandparent;
		}

		// 步骤4：重置平衡因子（旋转后子树平衡，BF均为0）
		parent->_bf = subL->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right; // parent的右子树（即将成为新根）
		Node* subRL = subR->_left;  // subR的左子树（需转移给parent）
		
		// 步骤1：将subRL作为parent的右子树
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* grandparent = parent->_parent; // parent的父节点

		// 步骤2：将parent作为subR的左子树
		subR->_left = parent;
		parent->_parent = subR;

		// 步骤3：链接subR与祖父节点（或更新根节点）
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

		// 步骤4：重置平衡因子
		parent->_bf = subR->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;  // parent的左子树
		Node* subLR = subL->_right;  // subL的右子树（关键节点，决定平衡因子重置）
		int bf = subLR->_bf;         // 记录subLR的原始BF（用于后续重置）

		// 步骤1：先对subL执行左单旋（修正左子树的失衡）
		RotateL(parent->_left);
		// 步骤2：再对parent执行右单旋（修正父节点的失衡）
		RotateR(parent);

		// 步骤3：根据subLR的原始BF，重置三个节点的平衡因子
		if (bf == 0)
		{
			// 场景3：subLR是新插入节点（BF=0）→ 旋转后三者BF均为0
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			// 场景2：subLR的右子树高（BF=1）→ parent的左子树高，subL的右子树高
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if(bf==-1)
		{
			// 场景1：subLR的左子树高（BF=-1）→ parent的右子树高，subL的左子树高
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
		Node* subR = parent->_right; // parent的右子树
		Node* subRL = subR->_left;   // subR的左子树（关键节点）
		int bf = subRL->_bf;         // 记录subRL的原始BF

		// 步骤1：先对subR执行右单旋（修正右子树的失衡）
		RotateR(parent->_right);
		// 步骤2：再对parent执行左单旋（修正父节点的失衡）
		RotateL(parent);

		// 步骤3：根据subRL的原始BF，重置三个节点的平衡因子
		if (bf == 0)
		{
			// 场景3：subRL是新插入节点 → 三者BF均为0
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}

		else if (bf == 1)
		{
			// 场景2：subRL的右子树高（BF=1）→ parent的左子树高，subR的左子树高
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			// 场景1：subRL的左子树高（BF=-1）→ parent的右子树高，subR的右子树高
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			// 异常情况
			assert(false);
		}
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
private:
	// 辅助接口：计算节点子树高度
	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);
		// 子树高度 = max(左子树高, 右子树高) + 1（当前节点）
		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	// 辅助接口：递归验证AVL树平衡性
	bool _IsBalance(Node* root)
	{
		// 空树是AVL树
		if (root == nullptr)
			return true;

		// 1. 计算当前节点的实际平衡因子（右高-左高）
		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);
		int realBF = rightH - leftH;

		// 2. 检查当前节点平衡因子是否异常（与存储的BF不一致，或绝对值>1）
		if (realBF != root->_bf || abs(realBF) > 1)
		{
			cout << "节点键：" << root->_kv.first
				<< "，存储BF：" << root->_bf
				<< "，实际BF：" << realBF << " → 失衡！" << endl;
			return false;
		}

		// 3. 递归验证左右子树
		return _IsBalance(root->_left) && _IsBalance(root->_right);
	}

public:
	// 对外接口：验证AVL树
	bool IsBalanceTree()
	{
		return _IsBalance(_root);
	}

	// 对外接口：中序遍历（验证二叉搜索树特性：中序递增）
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};