#define _CRT_SECURE_NO_WARNINGS 1
#include"B.h"


//int main()
//{
//	//简单字典
//	key_value::BSTree<string, string> dict;
//	dict.Insert("sort", "排序");
//	dict.Insert("string", "字符串");
//	dict.Insert("insert", "插入");
//	dict.Insert("erase", "删除");
//	dict.Insert("move", "移动");
//	dict.Insert("tree", "树");
//	dict.Insert("tree", "树*****");//插入失败，可以看看插入的逻辑，主要是key判断
//
//	// 内置类型转换成类类型 -> 构造函数
//	// 类类型转换成内置类型 -> operator 内置类型
//	string str;
//	int i = 0;
//	//while ((cin >> str).operator bool())
//	while(cin>>str)
//	{
//		auto* node = dict.Find(str);
//		if (node)
//		{
//			cout << "->" << node->_value << endl;
//		}
//		else
//		{
//			cout << "无此单词，请重新输入" << endl;
//		}
//	}
//
//	return 0;
//}


int main()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	key_value::BSTree<string, int> CountTree;
	for (auto& str : arr)
	{
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = CountTree.Find(str);
		// 第一次出现，插入<水果, 1>
		if (ret == nullptr)
		{
			CountTree.Insert(str, 1);
		}
		else
		{
			// 已出现，次数+1
			ret->_value++;
		}
	}
	// 中序遍历：按水果名称升序输出次数
	CountTree.InOrder();
	return 0;
}
