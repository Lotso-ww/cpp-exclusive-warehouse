#include<iostream>
#include<vector>
using namespace std;


//#include<functional>
//
//int f(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//
class Plus
{
public:
	Plus(int n = 10)
		:_n(n)
	{}

	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return (a + b) * _n;
	}
private:
	int _n;
};
////
////
//int main()
//{
//	// 类型擦除
//	function<int(int, int)>f1 = f;
//	function<int(int, int)>f2 = Functor();
//	function<int(int, int)>f3 = [](int a, int b) {return a + b; };
//	cout << f1(1, 1) << endl;
//	cout << f2(1, 1) << endl;
//	cout << f3(1, 1) << endl;
//
//	vector<function<int(int, int)>> v;
//	v.push_back(f);
//	v.push_back(Functor());
//	v.push_back([](int a, int b) {return a + b; });
//	for (auto& f : v)
//	{
//		cout << f(1, 1) << endl;
//	}
//
//
//	// 静态成员函数,下面两种写法都可以,用第二种可以统一规范
//	// function<int(int, int)> f4 = Plus::plusi;
//	 function<int(int, int)> f4 = &Plus::plusi;
//	 cout << f4(1, 1) << endl;
//
//	 // 成员函数,必须带&,并且不要忘了this指针的存在,所以下面实际是三个参数,但是写法很多
//	 function<double(Plus*, double, double)>  f5 = &Plus::plusd;
//	 Plus ps;
//	 cout << f5(&ps, 1.1, 1.1) << endl;
//
//	 function<double(Plus, double, double)>  f6 = &Plus::plusd;
//	 // Plus ps;
//	 cout << f6(ps, 1.1, 1.1) << endl;
//
//	 function<double(Plus, double, double)>  f7 = &Plus::plusd;
//	 cout << f7(Plus(), 1.1, 1.1) << endl;
//
//	 function<double(Plus&&, double, double)>  f8 = &Plus::plusd;
//	 cout << f8(Plus(), 1.1, 1.1) << endl;
//
//
//	 auto pf1 = &Plus::plusd;
//	 Plus* ptr = &ps;
//	 cout << (ps.*pf1)(1.1, 1.1) << endl;
//	 cout << (ptr->*pf1)(1.1, 1.1) << endl;
//
//	return 0;
//}


//#include<functional>
//
//using placeholders::_1;
//using placeholders::_2; 
//using placeholders::_3;
//
//int Sub(int a, int b)
//{
//	return (a - b) * 10;
//}
//
//int SubX(int a, int b, int c)
//{
//	return (a - b - c) * 10;
//}

//
//int main()
//{
//	// bind 本质返回一个仿函数对象
//	// 调整参数顺序(不常用)
//	// _1 代表第一个实参
//	// _2 代表第二个实参
//	// …………
//	auto f1 = bind(Sub, _1, _2);
//	auto f2 = bind(Sub, _2, _1);
//
//	// _1 代表第一个实参
//	// _2 代表第二个实参
//	cout << f1(10, 5) << endl;
//	cout << f2(10, 5) << endl;
//
//	// 调整参数个数
//	auto f3 = bind(SubX, 10, _1, _2);
//	cout << f3(15, 5) << endl;
//	// _1 代表第一个实参
//	// _2 代表第二个实参
//	// 底层operator(),调整SubX,第一个参数10,15,5
//
//	auto f4 = bind(SubX, _1, 10, _2);
//	cout << f4(15, 5) << endl;
//	// 底层operator(),调整SubX,第一个参数15,10,5
//
//	auto f5 = bind(SubX, _1, _2, 10);
//	cout << f5(15, 5) << endl;
//	// 底层operator(),调用SubX,第一个参数15,5,10
//
//	// 利用bind改进
//	function<double(Plus, double, double)>f7 = &Plus::plusd;
//	cout << f7(Plus(), 1.1, 1.1) << endl;
//	cout << f7(Plus(), 2.2, 1.1) << endl;
//	cout << f7(Plus(), 3.3, 1.1) << endl;
//
//	// 绑定成员函数（需传入this指针或对象）
//	function<double(double, double)>f8 = bind(&Plus::plusd, Plus(), _1, _2);
//	cout << f8(1.1, 1.1) << endl;
//	cout << f8(2.2, 1.1) << endl;
//	cout << f8(3.3, 1.1) << endl;
//
//	return 0;
//}

#include<functional>

using placeholders::_1;
using placeholders::_2;
using placeholders::_3;

int main()
{
	// 计算复利的 lambda
	auto func1 = [](double rate, double money, int year)->double {
		double ret = money;
		for (int i = 0; i < year; i++)
		{
			ret += ret * rate;
		}

		return ret - money;
		};

	function<double(double)>func_r1_5_y3 = bind(func1, 0.015, _1, 3);
	function<double(double)>func_r1_5_y5 = bind(func1, 0.015, _1, 5);
	function<double(double)>func_r1_5_y20 = bind(func1, 0.015, _1, 20);

	cout << func_r1_5_y3(100000) << endl;
	cout << func_r1_5_y5(100000) << endl;
	cout << func_r1_5_y20(100000) << endl;

	cout << "*****************************" << endl;

	function<double(double)>func_r10_y3 = bind(func1, 0.1, _1, 3);
	function<double(double)>func_r10_y5 = bind(func1, 0.1, _1, 5);
	function<double(double)>func_r10_y20 = bind(func1, 0.1, _1, 20);

	cout << func_r10_y3(100000) << endl;
	cout << func_r10_y5(100000) << endl;
	cout << func_r10_y20(100000) << endl;

}