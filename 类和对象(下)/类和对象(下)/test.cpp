#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
// //这里初始化列表的使用规范大家也应该注意一下
//	Date(int& x, int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _t(12)
//		, _ref(x)
//		, _n(1)
//	{
//		// error C2512: “Time”: 没有合适的默认构造函数可用
//		// error C2530 : “Date::_ref” : 必须初始化引用
//		// error C2789 : “Date::_n” : 必须初始化常量限定类型的对象
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	//我们可以这样理解:必须初始化的都需要在初始化列表初始化，要么就给缺省值。
//	//不给就会上面的那些错误
//	Time _t; // 没有默认构造
//	int& _ref; // 引用
//	const int _n; // const
//};
//int main()
//{
//	int a = 0;
//	//对象整体定义,再传参给引用
//	Date d1(a);
//	d1.Print();
//	return 0;
//} 

////通过上面的初始化列表，我们之前MyQueue类的一些问题也可以得到解决
////这里就大概实现一部分，仅作为演示使用
//#include<iostream>
//using namespace std;
//class Stack
//{
//public:
//	Stack(int n)//这里给的不是默认构造
//	{
//		cout << "Stack(int n)" << '\n';
//	}
//};
//
//class MyQueue
//{
//public:
//	//MyQueue(int n = 4)
//	//{
//	//	//这里如果直接这样写会去调用Stack的默认构造函数
//	//	//但是没有，所以这里会报错。
//	//}
//
//	//我们可以利用初始化列表有效解决这个问题
//	MyQueue(int n = 4)
//		:_st1(n)
//		, _st2(n)
//	{
//
//	}
//private:
//	Stack _st1;
//	Stack _st2;
//};
//
//int main()
//{
//	MyQueue q1;
//
//	return 0;
//}

////其实除了初始化列表以外，我们还可以这样玩
//#include<iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date()
//		:_year(100)
//	{
//
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	//注意:这里不是初始化，而是给的缺省值，这个缺省值是给初始化列表的
//	//每个成员变量都会走初始化列表，如果未显示在初始化列表，则会按缺省值初始化
//	//如果都没有，那内置类型可能就是随机值，之前提到过的那三种就是直接报错
//	int _year=1;
//	int _month=1;
//	int _day;
//
//	Time _t = 1;// 没有默认构造
//	const int _n=1; // const
//	int* _ptr = (int*)malloc(40);
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	return 0;
//}

//那为什么都使用了初始化列表了，还需要那个括号呢
//我们来看看下面这个场景
//#include<iostream>
//using namespace std;
//class A 
//{
//public:
//	A(int n = 10)
//		:_a((int*)malloc(sizeof(int)* n))
//		, _size(0)
//	{
//		//上面的_a的空间是否开辟成功是不是需要在这里检查
//		//以及给空间初始化是不是也得在这里实现
//		if (_a == nullptr)
//		{
//			perror("malloc fail!");
//			exit(1);
//		}
//		memset(_a, 0, sizeof(int) * n);
//	}
//private:
//	int* _a;
//	int _size;
//};
//int main()
//{
//	A aa;
//
//	return 0;
//}

////我们最后再来看个题
////注意_a1,_a2谁先初始化，以及最后结果是什么
//#include<iostream>
//using namespace std;
//class A
//{
//	//初始化顺序跟出现在初始化列表的顺序无关，所以这里其实是_a2先初始化，_a1再初始化
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{
//		//_a2先初始化，此时_a1还没初始化，所以是随机值，最后_a2也就是随机值了
//		//_a1再初始化,缺省值和初始化列表显示出现符合，按初始化列表的来，也就是1。
//	}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	//初始化列表按照成员变量在类中的声明顺序初始化
//	//这里我们发现_a2先声明
//	int _a2 = 2;
//	int _a1 = 2;
//};
//int main()
//{
//	A aa(1);
//	aa.Print();//1 随机值
//}


//——————————————————————————————————————————————————————————————————————————————————-----
////类型转换
//#include<iostream>
//using namespace std;
//class A 
//{
//public:
//	//构造函数explict就不再支持隐式类型转换了
//	//explict A(int a1)
//	//这里的构造函数参数有相关内置类型
//	A(int a1)
//		:_a1(a1)
//	{}
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//void func(const A& aa=1)
//{
//
//}
//
//class Stack 
//{
//public:
//	void Push(const A& a)
//	{
//
//	}
//
//};
//
//int main()
//{
//	//1.内置类型之间的隐式类型转换
//	int i = 1;
//	double d = i;
//
//	const double& ref1 = i;//这个我们之前也讲过，中间的临时对象具有常性
//
//	//2.内置类型和类类型之间的隐式转换
//	//需要有相关内置类型为参数的构造函数
//
//	//这样写是直接构造
//	A a1(1);
//	//这个才涉及到隐式类型转换
//	A a2 = 1;
//
//	const A& ref2 = a1;
//	const A& ref3 = 1;
//
//	//三种都可以，因为上面的函数参数是用过const修饰的(所以第二种也ok)
//	func(a1);
//	func(1);
//	func();
//
//	//我们再来看看别的使用场景
//	Stack s1;
//	//这样写有点麻烦了
//	A a3(3);
//	s1.Push(a3);
//	//我们可以直接这样,方便了很多
//	s1.Push(3);
//
//	return 0;
//}


////再来看看多参数转化以及类和类之间的隐式类型转换
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	// 构造函数explicit就不再支持隐式类型转换
//	// explicit A(int a1)
//	A(int a1)
//		:_a1(a1)
//	{
//		cout << "A(int a1)" << '\n';
//	}
//
//	A(const A& aa)
//	{
//		cout << "A(const A& aa)" << '\n';
//	}
//
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	int Get() const
//	{
//		return _a1 + _a2;
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//public:
//	//类和类之间的隐式类型转换，就需要参数是类类型相关了
//	B(const A& a)
//		:_b(a.Get())
//	{}
//private:
//	int _b = 0;
//};
//
//int main()
//{
//	//再来跟大家展示一个优化，上面没提到
//	// 构造
//	A a1(1);
//
//	// 这里的隐式类型转换其实就是，2为参数构造临时对象，临时对象拷贝构造a2 -> 优化为直接构造
//	A a2 = 2;
//
//	const A& ref1 = 3;
//
//	//C++11之后才支持多参数构造
//	A a3(1, 1);
//	A a4 = { 1, 1 };
//	const A& ref2 = { 1, 1 };
//
//	//Stack st1;
//	//st1.Push(a4);
//	//st1.Push({2,2});
//
//	//类和类之间的隐式类型转换，跟上面原理类似
//	B b1 = a3;
//	const B& ref3 = a3;
//
//	return 0;
//}

//------------------------------------------------------------------------------------
//static成员
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	//非静态的成员函数，可以访问任意静态成员变量以及非静态的成员变量
//	A(int a = 0)
//		:_a1(a)
//		,_a2(a)
//	{
//		++_count;
//	}
//
//	A(const A& t)
//	{
//		++_count;
//	}
//
//	static int GetCount()
//	{
//		// _a1++; 不能访问非静态成员，因为static成员函数没有this
//		return _count;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 1;
////public:
//	// 在类里面声明，且这里不可以用缺省值
//	static int _count;
//};
//
////必须在类外面初始化
//int A::_count = 0;
//
//int main()
//{
//	//静态成员不存在对象之中
//	A aa1;
//	cout << sizeof(aa1) << endl;
//	A* ptr = nullptr;
//
//	A aa2 = 1;
//	/*cout << ptr->_count<< endl;
//	cout << aa1._count << endl;
//	cout << A::_count << endl;*/
//
//	//变成私有的话，需要使用一下函数来获取了
//
//	cout << A::GetCount() << endl;
//	cout << aa2.GetCount() << endl;
//	cout << ptr->GetCount() << endl;
//
//	return 0;
//}


////练习题：1+2+3+……+n
////初始
//class Sum {
//public:
//    Sum()
//    {
//        _ret += _i;
//        _i++;
//    }
//    static int Get_Sum()
//    {
//        return _ret;
//    }
//private:
//    static int _ret;
//    static int _i;
//};
//
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        Sum arr[n];//变长数组
//        return Sum::Get_Sum();
//    }
//};


//再来看个练习
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    A()
//    {
//        cout << " A()" << endl;
//    }
//
//    ~A()
//    {
//        cout << " ~A()" << endl;
//    }
//};
//
//class B
//{
//public:
//    B()
//    {
//        cout << " B()" << endl;
//    }
//
//    ~B()
//    {
//        cout << " ~B()" << endl;
//    }
//};
//
//class C
//{
//public:
//    C()
//    {
//        cout << " C()" << endl;
//    }
//
//    ~C()
//    {
//        cout << " ~C()" << endl;
//    }
//};
//
//class D
//{
//public:
//    D()
//    {
//        cout << " D()" << endl;
//    }
//
//    ~D()
//    {
//        cout << " ~D()" << endl;
//    }
//};
//
//
////构造顺序
////析构顺序
//C c;
//int main()
//{
//    A a;
//    B b;
//    static D d;
//
//    return 0;
//}


//----------------------------------------------------------------------------------
//友元

////友元函数
//#include<iostream>
//using namespace std;
//
////前置声明，否则A的友元函数声明那里编译器不认识B
//class B;
//
//class A
//{
//	// 友元声明
//	friend void func(const A & aa, const B & bb);
//	private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//
//	return 0;
//}

//
////友元类，声明和定义需要分离，不然就算前置声明也解决不了问题，因为找不到类里面的成员
//#include<iostream>
//using namespace std;
//// xxx.h
//class C
//{
//	// 友元声明
//	friend class D;
//public:
//	void func1(const D& dd);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class D
//{
//	friend class C;
//public:
//	void func1(const C& aa);
//	void func2(const C& aa);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//// xxx.cpp
//void C::func1(const D& dd)
//{
//	cout << dd._b1 << endl;
//}
//
//void D::func1(const C& aa)
//{
//	cout << aa._a1 << endl;
//	cout << _b1 << endl;
//}
//
//void D::func2(const C& aa)
//{
//	cout << aa._a2 << endl;
//	cout << _b2 << endl;
//}
//
//int main()
//{
//	C cc;
//	D dd;
//	dd.func1(cc);
//	dd.func2(cc);
//
//	return 0;
//}


//-----------------------------------------------------------------------------------
////内部类
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	//内部类
//	class B //B默认是A的友元类
//	{
//	public:
//		void fun(const A& a)
//		{
//			cout << _k << '\n';//ok
//			cout << a._h << '\n';//ok
//		}
//	private:
//		int _b1;
//	};
//private:
//	static int _k;
//	int _h = 1;
//};
//
//int A::_k = 1;
//int main()
//{
//	//静态成员变量和内部类都不算
//	cout << sizeof(A) << '\n';//4
//
//	//受外部类类域限制和访问限定符限制
//	A::B b;
//
//	A aa;
//	b.fun(aa);
//
//	return 0;
//}

//那么学习完这个之后，我们上面的那个1+2+3……+n可以用内部类优化一下
//设计成内部类
//class Solution {
//	class Sum {
//	public:
//		Sum() {
//			_ret += _i;
//			_i++;
//		}
//	};
//
//public:
//	int Sum_Solution(int n) {
//		Sum arr[n];//要变长数组
//		return _ret;
//	}
//private:
//	static int _ret;
//	static int _i;
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;

//---------------------------------------------------------------------------------------
//匿名对象
//先拿上面的为例
//#include<iostream>
//using namespace std;
//class Solution {
//	class Sum {
//	public:
//		Sum() {
//			_ret += _i;
//			_i++;
//		}
//	};
//
//public:
//	int Sum_Solution(int n) {
//		//Sum arr[n];//要变长数组，vs不支持
//		return _ret;
//	}
//
//	//加个clear和析构
//	void clear()
//	{
//		_i = 1;
//		_ret = 0;
//	}
//
//	~Solution()
//	{
//		cout << "~Solution()" << '\n';
//	}
//
//private:
//	static int _ret;
//	static int _i;
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;
//
//void fun(const Solution& s=Solution(),int i=1)//缺省值直接给匿名对象
//{
//
//}
//int main()
//{
//	Solution s;//有名对象
//	cout << s.Sum_Solution(10) << '\n';
//	s.clear();
//	
//	//匿名对象的生命周期只在当前行
//	//Solution(); //匿名对象
//	//const 引用会延长匿名对象的生命周期，生命周期跟const 引用一样
//    //const Solution& ref = Solution();
//	cout << Solution().Sum_Solution(10) << '\n';//这样就可以直接一行搞定了
//
//	fun(Solution());
//	fun(s);
//	fun();
//
//	return 0;
//}

//--------------------------------------------------------------------------------------
//编译器优化
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a1 = 1;
//};
//
//void f1(A aa)
//{}
//
//int main()
//{
//	// 构造+拷贝构造 优化-> 构造
//	A aa1 = 1;
//	cout << "==================" << endl;
//
//	f1(aa1);
//	cout << "==================" << endl;
//
//	f1(1);
//	cout << "==================" << endl;
//
//	f1(A(1));
//	cout << "==================" << endl;
//
//
//	return 0;
//}


//// https://en.cppreference.com/w/cpp/language/copy_elision.html
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a1 = 1;
//};
//A f2()
//{
//	// NRVO
//	/*A aa;
//	cout << &aa << endl;
//	return aa;*/
//	
//	// URVO
//	return A(1);
//}
//
//int main()
//{
//	A aa1 = f2();
//	cout << &aa1 << endl;
//
//	return 0;
//}
//
//A f2()
//{
//	// NRVO
//	A aa;
//	cout << &aa << endl;
//	return aa;
//
//	// URVO
//	// return A(1);
//}
//
//int main()
//{
//	//不推荐，破坏了编译器的优化
//	A aa1;
//	aa1 = f2();
//	cout << &aa1 << endl;
//
//	// 推荐
//	A aa2 = f2();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//void main()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//
//	*char2 += 1;
//	//(*(char*)pChar3) += 1;
//
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//
//	const int i = 10;
//	int j = 1;
//	cout << &i << endl;
//	cout << &j << endl;
//	cout << (void*)pChar3 << endl;
//}
//

//#include<iostream>
//using namespace std;
//int main()
//{
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 50);
//	cout << p2 << endl;
//	cout << p3 << endl;
//
//	// 这里需要free(p2)吗？
//	free(p3);
//
//	int* p5 = new int;	    // 单个对象
//	int* p6 = new int[10];  // 数组
//
//	int* p7 = new int(5);	    // 单个对象
//	int* p8 = new int[10]{1,2,3,10};  // 数组
//
//	delete p5;
//	delete[] p6;
//	delete p7;
//	delete[] p8;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//struct ListNode
//{
//	ListNode* _next;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _val(val)
//	{
//	}
//};
//
//int main()
//{
//	// 只开空间，不调用构造初始化
//	A* p1 = (A*)malloc(sizeof(A));
//
//	A* p2 = new A;
//	A* p3 = new A(10);
//
//	delete p2;
//	delete p3;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//
//
//	return 0;
//}