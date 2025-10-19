#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<queue>
using namespace std;

////#define N 10
//#define N 1000
////模板进阶
//template<class T>
//class Stack
//{
//private:
//	T _a[N];
//	int _top;
//};
//
//int main()
//{
//	Stack<int> st1;//10
//	Stack<int> st2;//1000,那是不是就不够，只能改上面的定义，但是改的之后上面的st1就很浪费
//
//	return 0;
//}

////非类型模板参数--很好的解决了上面的问题
//template<class T,size_t N>
//class Stack
//{
//private:
//	T _a[N];
//	int _top;
//};
//
////C++20才开始支持这些类型
////template<double N，int * ptr>
////class AA
////{};
//
////std::string 不是非类型模板参数 str 的有效的类型
////template<string str>
////class BB
////{ };
//
//int main()
//{
//	Stack<int,10> st1;//10
//	Stack<int,1000> st2;//1000
//
//	return 0;
//}


//#include<array>
//
//void func(int* a)
//{
//	////不能使用范围for
//	//for (auto e : a)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//}

//void func(array<int, 10>& a)
//{
//	//能使用范围for
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
////静态数组array就使用了这个非类型模板参数
//int main()
//{
//	//但是这里内置类型默认是不会初始化的
//	array<int, 10> a1;
//	a1.fill(0);
//	a1[3] = 3;
//	a1[9] = 9;
//	for (auto e : a1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << sizeof(a1) << endl;
//
//	//那么array和我这样定义有啥区别呢
//	int a2[10];
//	a2[3] = 3;
//	a2[9] = 9;
//	for (auto e : a2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//区别：再去做其容器类型，或者传参，array都有普通数组达不到的优势
//	list<array<int, 10>> lt;
//	func(a1);//不能使用范围for，因为我们的这种静态数组作为形参会退化成指针
//	func(a2);//可以使用范围for
//
//	//还有个越界的检查问题
//	//数组只能检查越界写，并且是抽查
//	//a2[10]=1  //可以查出来
//	//a2[15] = 1;//不能查出来
//	//cout << a2[10] << endl;//越界读那是一点办法都没有
//
//	//上面那些对于array都不是问题，都可以检查出来，因为他是运算符重载调用，内存严格检查
//	/*a1[15] = 1;
//	cout << a1[10] << endl;*/
//}


////函数模板的特化
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//template<class T>
//bool Less(const T& left, const T& right)
//{
//	return left < right;
//}

 //const 在*的左边都是修饰指针指向对象不能修改
 //const 在*的右边都是修饰指针本身

//函数模板特化版本形参结构必须和原模板保持一致，比如说原模板是const的形参，特化版本也必须是
//对上述函数模板实现一个特化版本
//特化:针对某些类型进行特殊化处理
//template<>
////bool Less<Date*>(const Date*& left, const Date*& right)//这样写就错了，这里const修饰的指向的对象，而不是本身
//bool Less<Date*>(Date* const& left, Date* const& right)
//{
//	return *left < *right;
//}
//
//int main()
//{
//	cout << Less(1, 2) << endl;
//
//	Date* p1 = new Date(2025, 1, 1);
//	Date* p2 = new Date(2025, 1, 3);
//	cout << Less(p1, p2) << endl;//不使用特化版本的话比较就会结果错误
//
//	return 0;
//}

////但是这样特化起来有时候涉及到指针啥的很麻烦，所以我们直接写成函数
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//int main()
//{
//	cout << Less(1, 2) << endl;
//
//	Date* p1 = new Date(2025, 1, 1);
//	Date* p2 = new Date(2025, 1, 3);
//	cout << Less(p1, p2) << endl;//不使用特化版本的话比较就会结果错误
//
//	return 0;
//}

////类模板的特化

// 通用类模板（两个类型参数）
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//
////类模板的特化，对内部成员没有要求，也就是说原模板定义的，特化版本可以不定义，也可以新增
////全特化
//template<>
//class Data<int,double>
//{
//public:
//	Data() { cout << "Data<int,double> 全特化" << endl; }
//	void func() {}
//};
//
////偏特化/半特化
////部分特化
//template<class T1>
//class Data<T1, double>
//{
//public:
//	Data(){ cout << "Data<T1,double> 偏特化" << endl; }
//};

//偏特化
//参数更进一步限制
//两个参数偏特化为指针类型
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*,T2*> 偏特化--参数更进一步限制" << endl; }
	void func()
	{
		cout << typeid(T1).name() << endl;//T1
		cout << typeid(T2).name() << endl;//T2
	}
};

//两个参数偏特化为引用类型
template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data() { cout << "Data<T1&,T2&> 偏特化--参数更进一步限制" << endl; }
	void func()
	{
		cout << typeid(T1).name() << endl;//T1
		cout << typeid(T2).name() << endl;//T2
	}
};

template<class T1>
class Data<T1*, int>
{
public:
	Data() { cout << "Data<T1*,int> 偏特化--参数更进一步限制" << endl; }
	void func()
	{
		cout << typeid(T1).name() << endl;//T1
	}
};
//
int main()
{
	Data<int, int> d1;
	//d1.func();//d1不行，因为没有
	cout << endl;

	//Data<int, double> d2;
	//d2.func();//d2新增的可以使用
	//cout << endl;


	//Data<char, double> d3;
	//cout << endl;


	Data<char*, double*> d4;
	d4.func();
	cout << endl;


	Data<char&, double&> d5;
	d5.func();
	cout << endl;


	Data<char*, int> d6;
	d6.func();
	cout << endl;


	return 0;
}


//特化版本
//template <>
//struct less<Date*>
//{
//	//大堆
//	//bool operator() (const Date* const& x, const Date* const& y) const 
//	bool operator() (const Date* x, const Date* y) const//这样也可以，因为不要求类模板的特化版本和原模板一样
//	{ return *x < *y; }
//};
//
//template <>
//struct greater<Date*>
//{
//	//小堆
//	bool operator() (const Date* const& x, const Date* const& y) const { return *x > *y; }
//};
//
////还可以用偏特化让所有指针都按照指向的内容去比较
//template <class T>
//struct less<T*>
//{
//	bool operator() (const T* x, const T* y) const
//	{
//		return *x < *y;
//	}
//};
//
//int main()
//{
//	//priority_queue < Date*> q1;//这样就可以了
//	priority_queue < Date*,vector<Date*>,greater<Date*>> q1;
//	q1.push(new Date(2025, 10, 18));
//	q1.push(new Date(2025, 10, 19));
//	q1.push(new Date(2025, 10, 20));
//
//	while (!q1.empty())
//	{
//		cout << *q1.top() << endl;
//		q1.pop();
//	}
//	cout << endl;
//
//	return 0;
//}

