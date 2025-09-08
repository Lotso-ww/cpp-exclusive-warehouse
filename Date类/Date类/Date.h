#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
	//友元函数声明
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in,  Date& d);
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int MonthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		else {
			return MonthDayArray[month];
		}
	}
	//判断是否合法
	bool CheckDate()
	{
		if (_month < 1 || _month > 12
			|| _day < 1 || _day > GetMonthDay(_year, _month))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	// 拷贝构造函数
    // d2(d1)--this
	//Date(const Date& d);

	// 赋值运算符重载--其实也可以不写
    // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		{
			if (this != &d)
			{
				_year = d._year;
				_month = d._month;
				_day = d._day;
			}

			return *this;
		}
	}

	// 析构函数
	/*~Date();*/

	// 日期+=天数
	Date& operator+=(int day);

	// 日期+天数
	Date operator+(int day);

	// 日期-天数
	Date operator-(int day);

	// 日期-=天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);

	// 后置--
	Date operator--(int);

	// 前置--
	Date& operator--();

	// >运算符重载
	bool operator>(const Date& d);

	// ==运算符重载
	bool operator==(const Date& d);

	// >=运算符重载
	bool operator >= (const Date& d);
	
	// <运算符重载
	bool operator < (const Date& d);

	// <=运算符重载
	bool operator <= (const Date& d);

	// !=运算符重载
	bool operator != (const Date& d);

	// 日期-日期 返回天数
	int operator-(const Date& d);

	//打印
	void Print();

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in,  Date& d);