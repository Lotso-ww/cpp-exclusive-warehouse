#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void Print(const vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int>::const_iterator it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;
}

void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10,1);
	vector<int> v3(v2.begin(),v2.end());
	string s1("xxxxxxxxxxxxxxxxxxxxxxxxxx");
	//用其它类型的迭代器，这两个类型必须要可以转换
	vector<int> v4(s1.begin(), s1.end());
	vector<int> v5(v3);

	//C++11
	//vector<int> v6({ 1,2,3,4,5 });
	vector<int> v6 = { 1,2,3,4,5 };
	vector<int> v7={ 1,2,3,4,5,1,1,1,1,1};

	//其实是这样
	auto il = { 10,20,30,1,2,2 };
	for (auto e : il)
	{
		cout << e << " ";
	}
	cout << endl;
	
	Print(v2);
	Print(v4);
	Print(v6);
	Print(v7);
}


void test_vector2()
{
	vector<int> v1;
	//const int n=10000000;
	const int n = 100;
	//v1.reserve(n);

	size_t old = v1.capacity();
	//cout << v1.capacity() << endl;
	size_t begin = clock();
	for (size_t i = 0; i < n; i++)
	{
		v1.push_back(i);

		/*if (old != v1.capacity())
		{
			cout << v1.capacity() << endl;
			old = v1.capacity();
		}*/
	}
	size_t end = clock();
	cout << end - begin << endl;

	vector<int> v2;
	v2.resize(100, 1);
	Print(v2);
}

void test_vector3()
{
	vector<int> v1 = { 1,2,3,4,5 };
	v1.push_back(6);
	Print(v1);

	v1.insert(v1.begin(), 0);
	Print(v1);

	v1.insert(v1.begin() + 3, 0);
	Print(v1);

	v1.erase(v1.begin());
	Print(v1);

	v1.erase(v1.begin() + 3);
	Print(v1);
}

//template <class T>
//class vector
//{
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};

struct AA
{
	int _a1 = 1;
	int _a2 = 1;

	AA(int a1 = 1, int a2 = 1)
		:_a1(a1)
		,_a2(a2)
	{ }
};

void test_vector4()
{
	AA aa1 = { 0,0 };
	vector<AA> v = { aa1,{1,1},{2,2},{3,3} };
	auto it = v.begin();
	while (it != v.end())
	{
		cout << it->_a1 << ":" << it->_a2 << endl;
		++it;
	}
	cout << endl;

	v.push_back(aa1);
	v.emplace_back(aa1);

	//推荐这样用
	//但是这两种交替不行
	v.emplace_back(1, 1);
	v.push_back({ 2,2 });

	it = v.begin();
	while (it != v.end())
	{
		cout << it->_a1 << ":" << it->_a2 << endl;
		++it;
	}
	cout << endl;
}
int main()
{
	//test_vector1();
	//test_vector2();
	test_vector3();
	test_vector4();
}