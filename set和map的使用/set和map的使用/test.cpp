#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using namespace std;

// 测试set的插入与遍历（去重+自动排序）
void test_set1()
{
	set<int> s;

	// 方式1：单个元素插入
	//s.insert(3);
	//s.insert(1);
	//s.insert(2);
	//s.insert(5);
	//s.insert(3);
	//s.insert(5);
	//s.insert(6);

	// 方式2：初始化列表批量插入
	s.insert({ 3,1,2,5,3,5,6 });

	// 遍历方式1：迭代器遍历（注意：*it不可修改）
	// 遍历结果: 去重+有序
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it1 = 1;//不能修改
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 遍历方式2：范围for循环
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

// 测试set的查找与删除
void test_set2()
{
	set<int> s;
	s.insert({ 3,1,2,5,3,5,6 });// 去重后：1 2 3 5 6

	int x = 0;
	cin >> x;
	cout << s.erase(x) << endl;//删掉了几个就是几，在set里就是1，没删掉就是0
	
	//查找元素：find返回迭代器，未找到则返回s.end()
	//auto pos = s.find(x);
	//if (pos != s.end())
	//{
	//	s.erase(pos);//找到后删除
	//}

	// 统计元素个数：set中仅返回0或1（判断存在性）
	if (s.count(x))
	{

	}

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

// 测试set的区间操作
void test_set3()
{
	set<int> s;
	s.insert({ 3,1,2,5,3,5,6,7,9});

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 需求：删除[3, 8]区间的元素（即>=3且<=8）
	// lower_bound(val)：返回第一个>=val的迭代器（此处指向3）
	auto it1 = s.lower_bound(3);
	// upper_bound(val)：返回第一个>val的迭代器（此处指向9）
	auto it2 = s.upper_bound(8);
	// 按迭代器区间删除：删除[it1, it2)内的元素
	s.erase(it1, it2);

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

// 测试multiset（支持重复key）
void test_multiset()
{
	multiset<int> s;
	// 插入重复元素（不会去重）
	s.insert({ 3,1,2,5,3,5,6,3,3 });

	// 1. 遍历：有序但保留重复元素
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;//不能修改
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 2. 查找：返回中序遍历的第一个目标元素
	auto pos = s.find(3);
	//打印所有3
	while (pos != s.end() && *pos == 3)
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;

	
	// 3.查找有3的区间，左闭右开,【)
	//std::pair<multiset<int>::iterator, multiset<int>::iterator> ret = s.equal_range(3);
	auto ret = s.equal_range(3);

	// 4. 统计：返回元素实际个数
	cout << s.count(3) << endl;//有几个3

	// 5.删除：按key删除所有匹配元素
	cout << s.erase(3) << endl;//删掉所有的3，并返回删掉的3的个数
	s.erase(5);//删掉所有的5

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_set1();
	//test_set2();
	//test_set3();
	test_multiset();
}