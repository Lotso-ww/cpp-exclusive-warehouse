#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;


void test_list1()
{
	//展示其中两个，其实使用起来跟前面的vector差不多
	list<int> lt1;//无参构造
	list<int> lt2 = {1,2,3,4,5};
	list<int>::iterator it2 = lt2.begin();
	while (it2 != lt2.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt1;//无参构造
	list<int> lt2 = { 1,2,3,4,5 };
	auto pos = find(lt2.begin(),lt2.end(),3);
	if (pos != lt2.end())
	{
		lt2.insert(pos, 30);//pos没有失效，因为没有扩容
		lt2.erase(pos);//pos失效了
		//cout << *pos << endl;
	}

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list3()
{
	list<int> lt2 = { 1,2,4,3,5 };
	//sort(lt2.begin(), lt2.end());//不支持
	lt2.sort();

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list4()
{
	list<int> lt3 = { 1,2,2,3,3,2,3,4,5 };
	for (auto e : lt3)
	{
		cout << e << " ";
	}
	cout << endl;
	lt3.sort();
	lt3.unique();//去重
	for (auto e : lt3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list5()
{
	//将4这个节点挪到头位置
	list<int>lt4 = { 1,2,3,4,5 };
	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;
	auto pos = find(lt4.begin(), lt4.end(),4);
	lt4.splice(lt4.begin(), lt4, pos);
	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;

}

int main()
{
	//test_list1();
	//test_list2 ();
	//test_list3();
	//test_list4();
	test_list5();
}