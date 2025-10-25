#include"BinarySearchTree.h"

int main()
{
	int a[] = { 8, 3, 1, 10, 1, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto& e : a)
	{
		t.Insert(e);
	}

	t.InOrder();

	t.Erase(3);
	t.Erase(8);
	t.InOrder();

	t.Erase(1);
	t.InOrder();

	t.Erase(10);
	t.InOrder();

	for (auto& e : a)
	{
		t.Erase(e);
	}

	return 0;
}

//int main()
//{
//
//}