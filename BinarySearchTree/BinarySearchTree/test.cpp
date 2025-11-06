#include"BinarySearchTree.h"

//int main()
//{
//    // 测试数据：插入序列
//    int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//    BSTree<int> t;
//
//    // 1. 插入所有元素
//    for (auto& e : a)
//    {
//        t.Insert(e);
//    }
//    cout << "插入后中序遍历（应有序）：";
//    t.InOrder(); // 输出：1 3 4 6 7 8 10 13 14
//
//    // 2. 删除测试：逐步删除节点，验证有序性
//    t.Erase(3);   // 删除左子树非空、右子树非空的节点（情况4）
//    cout << "删除3后中序遍历：";
//    t.InOrder(); // 输出：1 4 6 7 8 10 13 14
//
//    t.Erase(8);   // 删除根节点（左右子树非空，情况4）
//    cout << "删除8后中序遍历：";
//    t.InOrder(); // 输出：1 4 6 7 10 13 14
//
//    t.Erase(1);   // 删除叶子节点（左右子树为空，情况1）
//    cout << "删除1后中序遍历：";
//    t.InOrder(); // 输出：4 6 7 10 13 14
//
//    t.Erase(10);  // 删除右子树非空、左子树非空的节点（情况4）
//    cout << "删除10后中序遍历：";
//    t.InOrder(); // 输出：4 6 7 13 14
//
//    // 3. 清空树（删除所有元素）
//    for (auto& e : a)
//    {
//        t.Erase(e);
//    }
//    cout << "清空后中序遍历（空行）：";
//    t.InOrder(); // 输出空行
//
//    return 0;//
//}

int main()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西⽠", "苹果", "苹果", "西⽠", "苹果", "⾹蕉", "苹果", "⾹蕉" };
	key_value::BSTree<string, s> CountTree;
	for (auto& str : arr)
	{
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			CountTree.insert()
		}
	}
	return 0;
}	
