#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
using namespace std;

//struct Point///
//{
//	int _x;
//	int _y;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Insert(const Date& d)
//{
//
//}
//
//Date func()
//{
//	//Date d(2025, 11, 15);
//	//return d;
//
//	//return { 2025,11,15 };
//
//	//Date d;
//	//return d;
//
//	return {};
//}
//
//int main()
//{
//	// C++98
//	int array1[] = { 1,2,3,4,5 };
//	int array2[5] = { 0 };
//	Point p = { 1,2 };
//
//	// C++11
//	// ⼀切皆可用列表初始化，且可以不加=
//	int x1 = { 2 };
//	// 自定义类型支持
//	// 这里本质是用{2025, 1, 1}构造一个Date临时对象
//	// 临时对象再去拷⻉构造d1，编译器优化后合二为一变成{2025, 1, 1}直接构造初始化d1
//	// 运行一下，我们可以验证上面的理论，发现是没调用拷⻉构造的
//	Date d1 = { 2025, 1, 1 };
//
//	// 这里d2引用的是{ 2024, 7, 25 }构造的临时对象
//	const Date& d2 = { 2024, 7, 25 };
//
//	// 需要注意的是C++98支持单参数时类型转换，也可以不用{}
//	Date d3 = { 2025 };
//	Date d4 = 2025;
//
//	// 可以省略掉=
//	Point p1{ 1, 2 };
//	int x2{ 2 };
//	Date d6{ 2024, 7, 25 };
//	const Date& d7{ 2024, 7, 25 };
//
//	// 不支持，只有{}初始化，才能省略=
//	// Date d8 2025;
//
//	vector<Date> v;
//	v.push_back(d1);
//	v.push_back(Date(2025, 1, 1));
//	// 比起有名对象和匿名对象传参，这里{}更有性价比
//	v.push_back({ 2025, 1, 1 });
//	
//
//	Insert({ 2025,11,15 });
//
//	return 0;
//}
//
//
//int main()
//{
//	vector<int> v1 = { 1,2,3,4 };
//	vector<int> v2 = { 1,2,3,4,5,6,7,7 };
//
//	// 里面的括号是pair列表初始化，外面的是initialize_list
//	map<string, string> dict = { {"sort","排序"},{"string","字符串"} };
//
//	v1 = { 10,20,30 };
//
//	auto il = { 10,20,30 };
//	cout << typeid(il).name() << endl;
//
//	std::initializer_list<int> mylist;
//	mylist = { 10,20,30 };
//	cout << sizeof(mylist) << endl;
//
//	 // 这里begin和end返回的值initializer_list对象中存的两个指针
//	 // 这两个指针的值跟i的地址跟接近，说明数组存在栈上
//	int i = 0;
//	cout << mylist.begin() << endl;
//	cout << mylist.end() << endl;
//	cout << &i << endl;
//	
//	return 0;
//}


//int main()
//{
//	// 左值:可以取地址
//	// 以下的p,b,c,*p,s,s[0]就是常见的左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("11111111111111");
//	s[0] = 'x';
//	cout << &p << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &(*p) << endl;
//	cout << &s << endl;
//	cout << (void*)&s[0] << endl;
//	
//	// 右值：不能取地址
//	double x = 1.1, y = 2.2;
//	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	string("11111");
//		
//	// 编译报错
//	//cout << &10 << endl;
//	//cout << &(x+y) << endl;
//	//cout << &(fmin(x, y)) << endl;
//	//cout << &string("11111") << endl;
//}


//int main()
//{
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("11111111111111");
//	s[0] = 'x';
//	double x = 1.1, y = 2.2;
//	
//	// 左值引用给左值取别名
//	int& r1 = b;
//	int*& r2 = p;
//	int& r3 = *p;
//	string& r4 = s;
//	char& r5 = s[0];
//
//
//	// 右值引用给右值取别名
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	string&& rr4 = string("11111");
//
//	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
//	const int& rx1 = 10;
//	const double& rx2 = x + y;
//	const double& rx3 = fmin(x, y);
//	const string& rx4 = string("11111");
//
//
//	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
//	int&& rrx1 = move(b);
//	int*&& rrx2 = move(p);
//	int&& rrx3 = move(*p);
//	string&& rrx4 = move(s);
//	string&& rrx5 = (string&&)s;
//
//	// b、r1、rr1都是变量表达式，都是左值
//	cout << &b << endl;
//	cout << &r1 << endl;
//	cout << &rr1 << endl;
//
//	// 这里要注意的是，右值引用后rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
//	// 后面还会再讲到的
//	int& r6 = r1;
//	// int&& rrx6 = rr1;
//	int&& rrx6 = move(rr1);
//	return 0;
//}


//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//int main()
//{
//	A aa1;
//
//	// 延长匿名对象的生命周期
//	const A& ref1 = A();// const左值引用，但是这样就不能修改了
//	A&& ref2 = A();// 右值引用
//
//	cout << "main end()" << endl;
//
//	return 0;
//}


//void f(int& x)
//{
//	std::cout << "左值引用重载 f(" << x << ")\n";
//}
//void f(const int& x)
//{
//	std::cout << "到 const 的左值引用重载 f(" << x << ")\n";
//}
//void f(int&& x)
//{
//	std::cout << "右值引用重载 f(" << x << ")\n";
//}
//int main()
//{
//	int i = 1;
//	const int ci = 2;
//	f(i); // 调用 f(int&)
//	f(ci); // 调用 f(const int&)
//	f(3); // 调用 f(int&&)，如果没有 f(int&&) 重载则会调用 f(const int&)
//	f(std::move(i)); // 调用 f(int&&)
//
//
//	 右值引用变量在用于表达式时是左值
//	int&& x = 1;
//	f(x); // 调用 f(int& x)
//	f(std::move(x)); // 调用 f(int&& x)
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//namespace Lotso
//{
//    class string
//    {
//    public:
//        typedef char* iterator;
//        typedef const char* const_iterator;
//
//        iterator begin()
//        {
//            return _str;
//        }
//        iterator end()
//        {
//            return _str + _size;
//        }
//
//        const_iterator begin() const
//        {
//            return _str;
//        }
//
//        const_iterator end() const
//        {
//            return _str + _size;
//        }
//
//        string(const char* str = "")
//            :_size(strlen(str))
//            , _capacity(_size)
//        {
//            cout << "string(char* str)-构造" << endl;
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }
//
//        void swap(string& s)
//        {
//            ::swap(_str, s._str);
//            ::swap(_size, s._size);
//            ::swap(_capacity, s._capacity);
//        }
//
//        // 拷贝构造
//        string(const string& s)
//        {
//            cout << "string(const string& s) -- 拷贝构造" << endl;
//
//            reserve(s._capacity);
//            for (auto ch : s)
//            {
//                push_back(ch);
//            }
//        }
//
//        // 移动构造
//        string(string&& s)
//        {
//            cout << "string(string&& s) -- 移动构造" << endl;
//            swap(s);
//        }
//
//        string& operator=(const string& s)
//        {
//            cout << "string& operator=(const string& s) -- 拷贝赋值" << endl;
//            if (this != &s)
//            {
//                _str[0] = '\0';
//                _size = 0;
//
//                reserve(s._capacity);
//                for (auto ch : s)
//                {
//                    push_back(ch);
//                }
//            }
//
//            return *this;
//        }
//
//        // 移动赋值
//        string& operator=(string&& s)
//        {
//            cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//            swap(s);
//            return *this;
//        }
//
//        ~string()
//        {
//            //cout << "~string() -- 析构" << endl;
//            delete[] _str;
//            _str = nullptr;
//        }
//
//        char& operator[](size_t pos)
//        {
//            assert(pos < _size);
//            return _str[pos];
//        }
//
//        void reserve(size_t n)
//        {
//            if (n > _capacity)
//            {
//                char* tmp = new char[n + 1];
//                if (_str)
//                {
//                    strcpy(tmp, _str);
//                    delete[] _str;
//                }
//                _str = tmp;
//                _capacity = n;
//            }
//        }
//
//        void push_back(char ch)
//        {
//            if (_size >= _capacity)
//            {
//                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//                reserve(newcapacity);
//            }
//
//            _str[_size] = ch;
//            ++_size;
//            _str[_size] = '\0';
//        }
//
//        string& operator+=(char ch)
//        {
//            push_back(ch);
//            return *this;
//        }
//
//        const char* c_str() const
//        {
//            return _str;
//        }
//
//        size_t size() const
//        {
//            return _size;
//        }
//    private:
//        char* _str = nullptr;
//        size_t _size = 0;
//        size_t _capacity = 0;
//    };
//
//    // 传值返回需要拷贝
//    string addStrings(string num1, string num2) {
//        string str;
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        // 进位
//        int next = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//            int ret = val1 + val2 + next;
//            next = ret / 10;
//            ret = ret % 10;
//            str += ('0' + ret);
//        }
//        if (next == 1)
//            str += '1';
//        reverse(str.begin(), str.end());
//        cout << &str << endl;
//
//        return str;
//    }
//}

//// 场景一
//int main()
//{
//    Lotso::string ret = Lotso::addStrings("11111", "2222");
//    cout << ret.c_str() << endl;
//    cout << &ret << endl;
//}
//
//// 场景二：
//int main()
//{
//    Lotso::string ret;
//    // ……
//    ret = Lotso::addStrings("11111", "2222");
//    cout << ret.c_str() << endl;
//    cout << &ret << endl;
//}


//#include "List.h"

//int main()
//{
//    std::list<std::string> lt;
//    cout << "*************************" << endl;
//
//    std::string s1("111111111111111111111");
//    lt.push_back(s1);
//    cout << "*************************" << endl;
//
//    lt.push_back(std::string("22222222222222222222222222222"));
//    cout << "*************************" << endl;
//
//    lt.push_back("3333333333333333333333333333");
//    cout << "*************************" << endl;
//
//    // 左值move本质授予别人转移你数据资源权限，所以要谨慎
//    lt.push_back(move(s1));
//    cout << "*************************" << endl;
//
//    return 0;
//}



// List.h
// 以下代码把跟这里无关的接口都删除了
namespace Lotso
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;
		ListNode(const T& data = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{
		}
		ListNode(T&& data)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(move(data))
		{
		}
	};
	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;
		Node* _node;
		ListIterator(Node* node)
			:_node(node)
		{
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		list()
		{
			empty_init();
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_back(T&& x)
		{
			insert(end(), move(x));
		}
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);
			Node* prev = cur->_prev;
			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		iterator insert(iterator pos, T && x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(move(x));
			Node* prev = cur->_prev;
			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}
	private:
		Node* _head;
	};
}
// Test.cpp
#include"List.h"
int main()
{
	Lotso::list<Lotso::string> lt;
	cout << "*************************" << endl;
	Lotso::string s1("111111111111111111111");
	lt.push_back(s1);
	cout << "*************************" << endl;
	lt.push_back(Lotso::string("22222222222222222222222222222"));
	cout << "*************************" << endl;
	lt.push_back("3333333333333333333333333333");
	cout << "*************************" << endl;
	lt.push_back(move(s1));
	cout << "*************************" << endl;
	return 0;
}