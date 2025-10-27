#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
using namespace std;

void test_set1()
{
	set<int> s;
	//s.insert(3);
	//s.insert(1);
	//s.insert(2);
	//s.insert(5);
	//s.insert(3);
	//s.insert(5);
	//s.insert(6);
	s.insert({ 3,1,2,5,3,5,6 });
	// 遍历结果: 去重+有序
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it1 = 1;//不能修改
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	set<int> s;
	s.insert({ 3,1,2,5,3,5,6 });
	int x = 0;
	cin >> x;
	cout << s.erase(x) << endl;//删掉了几个就是几，在set里就是1，没删掉就是0
	//auto pos = s.find(x);
	//if (pos != s.end())
	//{
	//	s.erase(pos);
	//}

	//单纯判断存不存在
	if (s.count(x))
	{

	}

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	set<int> s;
	s.insert({ 3,1,2,5,3,5,6,7,9});

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//删除[3，8]区间的值
	// >=3
	auto it1 = s.lower_bound(3);
	// >8
	auto it2 = s.upper_bound(8);
	s.erase(it1, it2);
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_multiset()
{
	multiset<int> s;
	s.insert({ 3,1,2,5,3,5,6,3,3 });
	//遍历结果：有序
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;//不能修改
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//查找中序第一个3
	auto pos = s.find(3);
	//打印所有3
	while (pos != s.end() && *pos == 3)
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;

	//【)
	//查找有3的区间，左闭右开
	//std::pair<multiset<int>::iterator, multiset<int>::iterator> ret = s.equal_range(3);
	auto ret = s.equal_range(3);

	cout << s.count(3) << endl;//有几个3
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