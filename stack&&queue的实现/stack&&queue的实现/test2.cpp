#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//priority_queue,实现部分测试
#include "priority_queue.h"

void test_pq1()
{
	//Lotso::priority_queue<int> pq;
	int a[] = { 30,4,2,66,3 };
	//Lotso::priority_queue<int> pq(a, a + 5);
	Lotso::priority_queue<int, vector<int>, Lotso::Greater<int>> pq(a, a + 5);
	pq.push(3);
	pq.push(1);
	pq.push(5);
	pq.push(7);
	pq.push(2);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
	}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

struct PDateless
{
	bool operator()(const Date* p1, const Date* p2)
	{
		return *p1 < *p2;
	}
};

void test_pq2()
{
	//如果我们使用的是Date*而不是Date
	//Lotso::priority_queue<Date*> q1;//这样写打印出来既不是大堆也不是小堆
	//是因为我们如果这样写就相当于在比较指针，
	//所以我们这里可以先定义一个仿函数来实现比较(后面在模板的进阶那里还会讲解别的方法)

	Lotso::priority_queue < Date*, vector<Date*>, PDateless> q1;//这样就可以了
	q1.push(new Date(2025, 10, 18));
	q1.push(new Date(2025, 10, 19));
	q1.push(new Date(2025, 10, 20));

	while (!q1.empty())
	{
		cout << *q1.top() << endl;
		q1.pop();
	}
	cout << endl;
}


//那么仿函数=也有一些对应的其它使用场景
void test1()
{
	vector<int> v1 = { 7,6,8,9,5,7,10 };
	//默认其实里面也有个仿函数less <:升序
	//替换成greater<>() >:降序
	sort(v1.begin(), v1.end());
	for (auto& x : v1)
	{
		cout << x << " ";
	}
	cout << endl;
	//大家有没有发现这里的greater使用的时候比优先队列多个()，我们看看下面的图片。
	sort(v1.begin(), v1.end(), greater<int>());
	for (auto& x : v1)
	{
		cout << x << " ";
	}
	cout << endl;
}

struct Option
{
	bool operator()(int x)
	{
		return x % 2 == 0;
	}
};
void test2()
{
	vector<int> v2 = { 1,2,3,4,5,6,7,8 };
	//查找第一个偶数
	auto it = find_if(v2.begin(), v2.end(), Option());
	cout << *it << endl;

	list<int> l1 = { 1,2,5,6,7,9,10 };

	//删除偶数
	l1.remove_if(Option());

	for (auto& x : l1)
	{
		cout << x << " ";
	}
	cout << endl;
}
int main()
{
	//test_pq1();
	//test_pq2();
	test1();
	//test2();
	return 0;
}