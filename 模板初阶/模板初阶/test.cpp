#define _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//using namespace std;
//
////我们使用之前学过的函数重载，但是也还是比较麻烦
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//
////template<typename T>
//template<class T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int i = 1, j = 2;
//	Swap(i, j);
//
//	char c1 = 'z', c2 = 'y';
//	Swap(c1, c2);
//
//	//Swap(i, c2);//类型不匹配
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.1;
//
//	//隐式实例化(实参类型，推导模板参数类型)
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	/*该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
//一个T，编译器无法确定此处到底该将T确定为int 或者 double类型而报错黑锅
//             Add(a1, d1);
//*/
//
//// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化,这个后面再讲
//	cout << Add((double)a1, d2) << endl;
//	cout << Add(a1, (int)d2) << endl;
//}

//
//#include<iostream>
//using namespace std;
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
////这样使用也是可以的，但是必须显示实例化
//template<class T>
//void Func(size_t n)
//{
//	T* ptr = new T[n];
//	cout << ptr << '\n';
//	//……
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.1;
//	//显示实例化
//	//先解决一下上面提到过的那个问题
//	cout << Add<int>(a1, d2) << endl;
//	cout << Add<double>(a1, d2) << endl;
//
//	Func<int>(10);
//	Func<double>(10);
//	
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return (left + right)*10;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.1;
//
//	cout << Add(a1, a2) << endl;//与非模板函数匹配，编译器不需要特化
//	cout << Add<int>(a1, a2) << endl;//调用编译器特化的Add版本
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}
//


//// 函数模板
//// 类模板
//#include<iostream>
//using namespace std;
//
//typedef int T;
//
//template<class T>
//class Stack
//{
//public:
//	Stack(size_t n = 4)
//		:_a(new T[n])
//		,_top(0)
//		,_capacity(n)
//	{}
//private:
//	T* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()
//{
//	//这里必须显示实例化，指明对象
//	Stack<int> st1;  // 存int
//	Stack<double> st2;  // 存double
//
//	return 0;///

 //泛型编程
 //模板不支持声明和定义分离定义.h 和 .cpp
template<class T>
class Stack
{
public:
	//Stack(size_t n = 4)
	//	:_a(new T[n])
	//	, _top(0)
	//	, _capacity(n)
	//{}

	//void Push(const T& x)
	//{
	//	// 扩容
	//	// ...
	//	_a[_top++] = x;
	//}

	Stack(size_t n = 4);
	void Push(const T& x);

private:
	T* _a;
	size_t _top;
	size_t _capacity;
};

template<class T>
Stack<T>::Stack(size_t n)
	:_a(new T[n])
	, _top(0)
	, _capacity(n)
{
}

template<class T>
void Stack<T>::Push(const T& x)
{
	// 扩容
	// ...
	_a[_top++] = x;
}

// #include<stack>

template<class T = int>
class A
{
public:
	T x1;
	T x2;
};

template<class T1, class T2 = int>
class B
{
public:
	T1 x1;
	T2 x2;
};

int main()
{
	// 显示实例化
	Stack<int> st1;		// 存int
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);

	Stack<double> st2;  // 存double
	st2.Push(1.1);
	st2.Push(2.1);
	st2.Push(3.1);

	// stack<int> st;

	A<> aa1;
	A<double> aa2;

	B<double> bb1;
	B<double, double> bb2;

	return 0;
}