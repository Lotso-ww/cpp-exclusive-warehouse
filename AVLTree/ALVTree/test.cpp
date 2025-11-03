#define _CRT_SECURE_NO_WARNINGS 1
#include"AVLTree.h"

// 测试AVL树插入与平衡性
void TestAVL()
{
    // 测试用例1：包含双旋场景（如4,2,6,1,3,5,15,7,16,14）
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
    AVLTree<int, int> t;
    for (auto e : a)
    {
        t.Insert({ e, e });
    }

    // 验证1：中序遍历（应递增）
    cout << "中序遍历结果：";
    t.InOrder(); // 输出：1 2 3 4 5 6 7 14 15 16

    // 验证2：平衡性（应返回true）
    if (t.IsBalanceTree())
    {
        cout << "AVL树平衡验证通过！" << endl;
    }
    else
    {
        cout << "AVL树平衡验证失败！" << endl;
    }
}

int main()
{
    TestAVL();
    return 0;
}