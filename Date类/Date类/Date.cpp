#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

// 全缺省的构造函数
Date::Date(int year, int month, int day)
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

//日期+=天数
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	//this出了作用域还在，所以可以用引用返回，减少拷贝
	return *this;
}
//
//// 日期+天数
//Date Date::operator+(int day)
//{
//	//加天数需要原来的不改变
//	Date tmp(*this);
//	//剩余逻辑和+=类似
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		++tmp._month;
//		if (tmp._month == 13)
//		{
//			++tmp._year;
//			tmp._month = 1;
//		}
//	}
//	return tmp;
//}

//我们上面实现的+和+=可以互相复用
//+复用+=
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

////+=复用+
//Date& Date::operator+=(int day)
//{
//	*this = *this + day;
//	return *this;
//}

//最后我们可以得出用拷贝多的复用拷贝少的更好，也就是+复用+=

// 日期-=天数
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

// 日期-天数
//直接复用
Date Date::operator-(int day)
{
	//-的话原来的不改变
	Date tmp(*this);
	tmp -= day;
	return tmp;
}




// 前置++
Date& Date::operator++()
{
	//前置++先++后赋值,所以返回值是运算之后的
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	//后置++先赋值后++，所以返回值是运算之前的。
	//我们先把原来的保存下来
	Date tmp(*this);
	*this += 1;
	return tmp;
}

// 前置--
Date& Date::operator--()
{
	//前置--先--后赋值,所以返回值是运算之后的
	*this -= 1;
	return *this;
}

// 后置--
Date Date::operator--(int)
{
	//后置--先赋值后--，所以返回值是运算之前的。
	//我们先把原来的保存下来
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	//if (_year > d._year)
	//{
	//	return true;
	//}
	//else if (_year == d._year)
	//{
	//	if (_month > d._month)
	//	{
	//		return true;
	//	}
	//	else if (_month == d._month)
	//	{
	//		return _day > d._day;
	//	}
	//	else {
	//		return false;
	//	}
	//}
	//else {
	//	return false;
	//}

	//简化
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day > d._day;
		}
	}
		return false;
}


// >=运算符重载
bool Date::operator >= (const Date& d)
{
	return (*this == d) || (*this > d);
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this >= d);//>=的逻辑取反
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return !(*this > d);//>的逻辑取反
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);//==的逻辑取反
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int ans = 1;//符号
	int n = 0;

	if (*this < d)
	{
		max = d;
		min = *this;
		ans = -1;
	}

	while (min != max)
	{
		++min;
		++n;
	}
	return n * ans;
}


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
