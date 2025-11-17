#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//// 由于引用折叠限定，f1实例化以后总是⼀个左值引用
//template<class T>
//void f1(T& x)
//{
//}
//
//// 由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
//template<class T>
//void f2(T&& x)
//{
//}
//
//int main()
//{
//	typedef int& lref;
//	typedef int&& rref;
//
//	int n = 0;
//	lref& r1 = n; // r1 的类型是 int&
//	lref&& r2 = n; // r2 的类型是 int&
//	rref& r3 = n; // r3 的类型是 int&
//	rref&& r4 = 1; // r4 的类型是 int&&
//
//	// 没有折叠->实例化为void f1(int& x)
//	f1<int>(n);
//	//f1<int>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&>(n);
//	// f1<int&>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&&>(n);
//	// f1<int&&>(0); // 报错
//	
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&>(n);
//	f1<const int&>(0);
//
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&&>(n);
//	f1<const int&&>(0);
//
//	// 没有折叠->实例化为void f2(int&& x)
//	// f2<int>(n); // 报错
//	f2<int>(0);
//
//	// 折叠->实例化为void f2(int& x)
//	f2<int&>(n);
//	// f2<int&>(0); // 报错
//	
//	// 折叠->实例化为void f2(int&& x)
//	// f2<int&&>(n); // 报错
//	f2<int&&>(0);
//
//	return 0;
//}



//// 万能引用-以int类型的为例
//// 传左值时,推导为int&,最后就是左值引用
//// 传左值时,推导为int,最后就是右值引用
//template<class T>
//void Function(T&& t)
//{
//	int a = 0;
//	T x = a;
//	//x++;
//	cout << &a << endl;
//	cout << &x << endl << endl;
//}
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10); // 右值
//
//	int a;
//	// a是左值，推导出T为int&，引⽤折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a)); // 右值
//
//	const int b = 8;
//	// a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const int& t)
//	// 所以Function内部会编译报错，x不能++
//	Function(b); // const 左值
//
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&& t)
//	// 所以Function内部会编译报错，x不能++
//	Function(std::move(b)); // const 右值
//
//	return 0;
//}

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右指引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
////万能引用
//template<class T>
//void Function(T&& t)
//{
//    Fun(forward<T>(t));
//}
//
//int main()
//{
//    // 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//    Function(10); // 右值
//
//    int a;
//    // a是左值，推导出T为int&，引⽤折叠，模板实例化为void Function(int& t)
//    Function(a); // 左值
//
//    // std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//    Function(std::move(a)); // 右值
//
//    const int b = 8;
//    // a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const int&t)
//    Function(b); // const 左值
//
//    // std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&& t)
//    Function(std::move(b)); // const 右值
//
//    return 0;
//}



//template<class ...Args>
//void Print(Args&&... args)
//{
//    cout << sizeof...(args) << endl;
//}


//// 编译器底层原理还是一样，实例化生成对应参数类型和个数的多个函数
//void Print()
//{
//    cout << 0 << endl;
//}
//
//void Print(int&& x)
//{
//    cout << 1 << endl;
//}
//
//void Print(double& d,string&& s)
//{
//    cout << 2 << endl;
//}

//int main()
//{
//    double x = 2.2;
//    Print(); // 包里有0个参数
//    Print(1); // 包里有1个参数
//    Print(x, string("xxxxx")); // 包里有2个参数
//    Print(1.1,string("xxxxx"),x); // 包里有3个参数
//
//    return 0;
//}


//// 编译时递归推导解析参数
//void ShowList()
//{
//    // 编译器时递归的终止条件，参数包是0个时，直接匹配这个函数
//    cout << endl;
//}
//
//template<class T,class ...Args>
//void ShowList(T x, Args... args)
//{
//    cout << x << "";
//
//    // args是N个参数的参数包
//    // 调用ShowList,参数包的第一个传给x，剩下N-1传给第二个参数包
//    ShowList(args...);
//}
//
//template<class ...Args>
//void Print(Args ...args)
//{
//    // 解析参数包,递归推导
//    ShowList(args...);
//}
//
//int main()
//{
//    Print();
//    Print(1);
//    Print(1,string("xxxxx"));
//    Print(1,string("xxxxx"),2.2);
//
//    return 0;
//}


//// 折叠表达式 C++17
//template<class ...Args>
//void Print(Args... args)
//{
//	((cout << args << " "), ...);
//	cout << endl;
//}



//// Print(1,string("xxxxx"),2.2);
//// 实例化为下面的函数
////void Print(int x, string y, double z)
////{
////    // ((cout << args << " "), ...);
////    ((cout << x << " "), (cout << y << " "), (cout << z << " "));
////    cout << endl;
////}
//
//int main()
//{
//	Print();
//	Print(1);
//	Print(1, string("xxxxx"));
//	Print(1, string("xxxxx"), 2.2);
//
//	return 0;
//}

#include<assert.h>
#include<string.h>
#include<algorithm>


namespace Lotso
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;

			reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}

		// 移动构造
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}

		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" << endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;

				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}

			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			//cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
}


#include<list>
//// emplace_back总体而言是更高效，推荐以后使用emplace系列替代insert和push系列
//
//int main()
//{
//	list<Lotso::string> lt;
//
//	// 传左值,跟push_back一样,走拷贝构造
//	Lotso::string s1("1111111111");
//	lt.emplace_back(s1);
//	cout << "************************************" << endl;
//
//	// 右值,跟push_back一样,走移动构造
//	lt.emplace_back(move(s1));
//	cout << "************************************" << endl;
//
//	// 直接把构造string参数包往下传，直接用string参数包构造string
//	// 这里达到的效果是push_back做不到的
//	lt.push_back("1111111111");
//	cout << "************************************" << endl;
//
//	lt.emplace_back("1111111111");
//	cout << "************************************" << endl;
//
//	return 0;
//}


struct Date
{
public:
	Date(int y,int m,int d)
		:_y(y)
		,_m(m)
		,_d(d)
	{}
private:
	int _y = 1;
	int _m = 1;
	int _d = 1;
};

int main()
{
	list<pair<Lotso::string, int>> lt1;


	// 跟push_back一样
	// 构造 pair + 拷贝/移动构造pair到list的节点中data上
	pair<Lotso::string, int> kv("苹果",1);
	lt1.push_back(kv);
	cout << "************************************" << endl;

	// 跟push_back一样
	lt1.emplace_back(move(kv));
	cout << "************************************" << endl;

	// 直接把构造pair参数包往下传，直接用pair参数包构造pair
	// 这里达到的效果是push_back是做不到的
	lt1.emplace_back("苹果", 1);
	// lt1.push_back("苹果", 1); // 错误,要传pair或者{}隐式转换pair的值
	//lt1.push_back({ "苹果",1 });
	cout << "************************************" << endl;

	list<Date> lt;
	// 构造 + 拷贝构造
	Date d1{ 2025,11,18 };
	lt.push_back(d1);
	lt.push_back({ 2025,11,18 });

	// 传构造Dtae的参数，传给形参参数包，参数包往下不断传递，最后直接构造到链表节点上
	// 直接构造
	lt.emplace_back(2025, 11, 18);

	return 0;
}