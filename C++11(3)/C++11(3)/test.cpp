#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
#include<assert.h>
#include<string.h>
#include<algorithm>
using namespace std;

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


//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{
//	}
//	/*Person(const Person& p)
//	:_name(p._name)
//	,_age(p._age)
//	{}*/
//	/*Person& operator=(const Person& p)
//	{
//	if(this != &p)
//	{
//	_name = p._name;
//	_age = p._age;
//	}
//	return *this;
//	}*/
//	/*~Person()
//{}*/
//private:
//	Lotso::string _name;
//	int _age;
//};
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	Person s4;
//	s4 = std::move(s2);
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "张三yyyyyyyyyyyy",int age = 18)
//		:_name(_name)
//		,_age(age)
//	{}
//
//	// C++11
//	// delete之后就不会自动生成默认拷贝构造函数了,库里面的ostream就用到了
//	// Person(const Person& p) = delete;
//	// default之后让编译器强制生成移动构造函数
//	/*Person(const Person& p) = default;
//	Person(Person&& p) = default;*/
//
//	~Person()
//	{}
//
//private:
//	// C++98
//	/*Person(const Person& p);*/
//
//	string _name;
//	int _age;
//};

//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//
//	//Person s4("************************", 1);
//	//s4 = std::move(s2);
//	return 0;
//}



//class Example
//{
//public:
//	Example(int a, int b)
//		:_x(a)
//		, _y(b)
//	{
//		cout << "目标构造函数\n";
//	}
//
//	Example(int a)
//		:Example(a, 0)
//	{
//		cout << "委托构造函数\n";
//	}
//
//	int _x;
//	int _y;
//};
//
//class Time
//{
//public:
//	Time(int h,int m)
//		:_hour(h)
//		,_minute(m)
//	{}
//	 //error C3511: “Time”: 对委托构造函数的调用应仅为成员初始值设定项,被委托函数必须已经实现了全部成员变量的初始化
//    // error C2437 : “_second”: 已初始化
//    Time(int h, int m, int s)
//        :Time(h, m)
//     // , _second(s)
//    {}
//
//private:
//    int _hour;
//    int _minute;
//    int _second = 0;
//};
//
//
//int main()
//{
//	Example(1, 2);
//	Example(1);
//
//	return 0;
//}


//class Base
//{
//public:
//	Base(int x,double d)
//		:_x(x)
//		,_d(d)
//	{}
//
//	Base(int x)
//		:_x(x)
//	{}
//
//	Base(double d)
//		: _x(d)
//	{}
//
//protected:
//	int _x = 0;
//	double _d = 0;
//};
//
//// 传统的派生类实现构造,很麻烦复杂
////class Derived : public Base {
////public:
////    Derived(int x) : Base(x) {}
////    Derived(double d) : Base(d) {}
////    Derived(int x, double d) : Base(x, d) {}
////};
//
//// C++11继承基类的所有构造函数
//class Derived : public Base {
//public:
//    using Base::Base;
//
//	// 这里需要注意的是这样的继承构造仅仅适合子类没有变量需要构造的,或者通过缺省值就可以了的。
//    /*protected:
//        int _i = 0;
//        string _s;*/
//};
//
//
//int main()
//{
//    Derived d1(1);
//    Derived d2(1.1);
//    Derived d3(2, 2.2);
//
//    return 0;
//}




//// 关于返回值后置的
//// std::map<std::string, std::pair<std::string, std::string>>::iterator func();
//// auto func()->std::map<std::string, std::pair<std::string, std::string>>::iterator;
//
//
//int main()
//{
//	// 一个简单的lamba表达式
//	// 这里可以只靠auto推导返回值类型,但是还是建议写出来的
//	/*auto add1 = [](int x, int y){return x + y; };*/
//	auto add1 = [](int x, int y)->int {return x + y; };
//	cout << add1(1, 2) << endl;
//
//	// 关于那些东西可以省略，哪些不可以
//	// 1. 就算捕捉为空也是不可以省略的
//	// 2. 参数为空可以直接省,()都不用了
//	// 3. 返回值可以省略,可以通过返回对象自动推导
//	// 4. 函数体不可以省略
//	auto func1 = []
//	{
//		cout << "hello Lotso" << endl;
//		return 0;
//	};//分号不要掉哈
//	func1();
//
//
//	int a = 0, b = 1;
//	auto swap1 = [](int& x, int& y)
//	{
//		int temp = x;
//		x = y;
//		y = temp;
//	};
//	swap1(a, b);
//	cout << a << ":" << b << endl;
//
//	return 0;
//}

//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 平价
//
//	// ...
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{
//	}
//};


//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//
//struct CompareEvaluateLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._evaluate < gr._evaluate;
//	}
//};
//
//struct CompareEvaluateGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._evaluate > gr._evaluate;
//	}
//};



//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3}, { "菠萝", 1.5, 4 } };
//
//	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了
//	//sort(v.begin(), v.end(), ComparePriceLess());
//	//sort(v.begin(), v.end(), ComparePriceGreater());
//	//sort(v.begin(), v.end(), CompareEvaluateLess());
//	//sort(v.begin(), v.end(), CompareEvaluateGreater());
//
//	//auto priceLess = [](const Goods& gl, const Goods& gr)
//	//{
//	//	return gl._price < gr._price;
//	//};
//
//	//sort(v.begin(), v.end(), priceLess);
//
//
//	// 这样写更简单,但是调试查看的时候需要将断点打到下一个sort或下一个语句上
//	// 因为如果打到当前sort,他即算打到sort又算打到lambda
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr){
//			return gl._price < gr._price;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {
//		return gl._price > gr._price;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {
//		return gl._evaluate < gr._evaluate;
//		});
//
//	sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {
//		return gl._evaluate > gr._evaluate;
//		});
//
//	return 0;
//}

//int x = 0;
//// 这里捕捉列表必须为空,因为全局变量不用捕捉就可以用,没有可以被捕捉的变量(静态成员变量也是同样的道理)
//auto func1 = []()
//	{
//		x++;
//	};
//
//
//int main()
//{
//	// 只能用当前 lambda 局部域捕捉到的对象和全局对象
//	// 捕获列表的意义,本质是更方便的使用当前局部域的对象
//	int a = 0, b = 1, c = 2, d = 3;
//	// 加了这个mutable之后值捕捉也可以修改a了,这里()就不可以省了就算没参数
//	// 传值捕捉本质是⼀种拷⻉,并且被const修饰了
//	// mutable相当于去掉const属性，可以修改了
//	// 但是修改了不会影响外⾯被捕捉的值，因为是⼀种拷⻉
//	/*auto func1 = [a,&b]() mutable*/
//	auto func1 = [a, &b]
//		{
//			// 值捕捉的变量不可以修改,引用捕捉的可以修改
//			//a++;
//			b++;
//			int ret = a + b;
//			x++;//全局变量
//			return ret;
//		};
//	cout << func1() << endl;
//
//	// 隐式值捕捉
//	// 用了哪些变量就捕捉哪些变量
//	auto func2 = [=]
//		{
//			int ret = a + b;
//			return ret;
//		};
//	cout << func2() << endl;
//
//
//	// 隐式引用捕捉
//	// 用了哪些变量就捕捉哪些变量
//	auto func3 = [&]
//		{
//			a++;
//			c++;
//			d++;
//		};
//	func3();
//	cout << a << " " << b << " " << c << " " << d << endl;
//
//	cout << "*********************" << endl;
//
//	// 混合捕捉的=或&一定是最前面的,而且如果前面是=后面必须是引用捕捉,前面是&后面必须是值捕捉
//
//	// 混合捕捉1
//	auto func4 = [&, a, b]
//		{
//			//a++;
//			//b++;
//			c++;
//			d++;
//			int ret = a + b + c + d;
//			return ret;
//		};
//	cout << func4() << endl;
//	cout << a << " " << b << " " << c << " " << d << endl;
//
//	// 混合捕捉2
//	auto func5 = [=, &a, &b]
//		{
//			a++;
//			b++;
//			/*c++;
//			d++;*/
//			return a + b + c + d;
//		};
//	func5();
//	cout << a << " " << b << " " << c << " " << d << endl;
//
//	// 局部的静态和全局变量不能捕捉，也不需要捕捉
//	static int m = 0;
//	auto func6 = []
//	{
//		int ret = x + m;
//		return ret;
//	};
//
//	// 传值捕捉本质是⼀种拷⻉,并且被const修饰了
//	// mutable相当于去掉const属性，可以修改了
//    // 但是修改了不会影响外⾯被捕捉的值，因为是⼀种拷⻉
//	auto func7 = [=]()mutable
//	{
//		a++;
//		b++;
//		c++;
//			d++;
//		return a + b + c + d;
//	};
//	cout << func7() << endl;
//	cout << a << " " << b << " " << c << " " << d << endl;
//}


//class A
//{
//public:
//	void func()
//	{
//		int x = 0, y = 1;
//		
//		auto f1 = [=]
//		{
//			// 为什么是值捕捉,但是成员变量还可以++呢,因为这里实际上捕捉的是他的this指针
//			_a1++;
//			return x + y + _a1 + _a2;
//		};
//
//		cout << f1() << endl;
//
//		auto f2 = [&]
//		{
//			x++;
//			_a1++;
//			return x + y + _a1 + _a2;
//		};
//
//		cout << f2() << endl;
//
//		// 捕捉this指针的本质就是为了可以访问成员变量
//		auto f3 = [x,this]
//		{
//			_a1++;
//			return x + _a1 + _a2;
//		};
//
//		cout << f3() << endl;
//	}
//private:
//	int _a1 = 0;
//	int _a2 = 1;
//};
//
//int main()
//{
//	A a;
//	a.func();
//	return 0;
//}

int x = 0;
// lambda参数/返回类型 / 函数体就是仿函数operator()的参数 / 返回类型 / 函数体
// lambda 的捕捉列表本质是生成的仿函数类的成员变量，也就是说捕捉列表的变量都是 lambda 类构造函数的实参
int main()
{
	int a = 0, b = 1, c = 2, d = 3;
	//class lambada5(const int& a_, int& b_) //也行，但是int没必要
	//class lambada5
	//{
	//public:
	//	lambada5(int a_, int& b_)
	//		:a(a_)
	//		,b(b_)
	//	{}

	//	int operator()(int x)
	//	{
	//		//a++;
	//		++b;
	//		return a + b + x;
	//	}
	//private:
	//	const int a;//对应值捕捉
	//	int& b;// 对应引用捕捉
	//};

	// 可以看看汇编层
	auto func = [a, &b](int x)
	{
		//a++;
		++b;
		return a + b + x;
	};
	cout << func(1) << endl;

	// 等价于
	/*lambada5 func(a, b);*/

	return 0;
}