#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
#include<iostream>
using namespace std;

namespace Lotso
{
	void Print(const vector<int>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		for (size_t i = 0; i < v.size(); i++)
		{
			//v[0]++;
			cout << v[i] << " ";
		}
		cout << endl;
	}
	void test_vector1()
	{
		Lotso::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);

		v[0]++;

		Print(v);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		Lotso::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(5);
		Print(v);

		v.insert(v.begin(), 0);
		Print(v);

		auto it = v.begin() + 3;
		// insert以后，it是否失效？
		// it失效了，也就意味着，insert以后，it失效了，it就不能使用了
		v.insert(it, 30);
		Print(v);
	}

	void test_vector3()
	{
		Lotso::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		Print(v);

		v.erase(v.begin());
		Print(v);

		auto it = v.begin() + 2;
		// it是否失效呢？失效，不能访问，访问结果未定义
		v.erase(it);
		Print(v);
	}

	void test_vector4()
	{
		Lotso::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		// Print(v);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		// 删除所有的偶数
		/*auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				v.erase(it);
			}

			++it;
		}*/

		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector5()
	{
		Lotso::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(3);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		// v.resize(20);
		v.resize(20, 5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		Lotso::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		Lotso::vector<int> v2(v1);

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		// Lotso::vector<int> v3({ 10,20,30,40 });
		Lotso::vector<int> v3 = { 10,20,30,40 };
		v1 = v3;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		//Lotso::vector<int> v4(10u, 1);
		Lotso::vector<int> v4(10, 1);
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;

		Lotso::vector<char> v5(10, 'x');
	}

	void test_vector7()
	{
		Lotso::vector<string> v1;
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		v1.push_back("111111111111111111111111");
		for (auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	/*Lotso::test_vector1();
	Lotso::test_vector2();
	Lotso::test_vector3();
	Lotso::test_vector4();*/
	//Lotso::test_vector5();
	//Lotso::test_vector6();
	//Lotso::test_vector7();

	return 0;
}
