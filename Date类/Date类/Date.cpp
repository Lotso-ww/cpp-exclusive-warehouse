#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

// 全缺省的构造函数
Date::Date(int year = 1900, int month = 1, int day = 1)
{
	_year = year;
	_month = month;
	_day = day;
}

//// 拷贝构造函数--可以不写
//// d2(d1)--this
//Date::Date(const Date& d)
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
//打印
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//// 析构函数--可以不写
//Date::~Date()
//{
//	_year = 0;
//	_month = 0;
//	_day = 0;
//}
