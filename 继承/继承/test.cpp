#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
using namespace std;


//基类/父类
class Person
{
// 都可以用
public:
	//进入校园/图书馆/实验室刷二维码等身份认证
	void identity()
	{
		cout << "void identity():" << _name << endl;
	}
	void func()
	{
		cout << _age << endl;
	}

//基类的保护成员可以直接在派生类中使用，但不能在类外使用
protected:
	string _name = "赵四";//姓名
	string _address;//地址
	string _tel;//电话

//基类的私有成员无法在派生类中直接使用
private:
	int _age = 18;//年龄
};

//class类的话不写默认是私有继承，struct是公有继承
// class Student:Person
class Student : public Person
{
public:
	//学习
	void study()
	{
		//……
		//基类私有成员(爸爸的私房钱)，派生类	中不可见，语法限制上不能直接使用
		//cout << _age << endl;
		
		//但是可以间接使用
		func();
	}
protected://在继承中保护用的比较多
	int _stuid;//学号
};
class Teacher : public Person
{
public:
	//授课
	void teaching()
	{
		//…………
	}
protected:
	string title;//职称
};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.identity();
//	s.study();
//
//	return 0;
//}

//namespace Lotso
//{
//	template<class T>
//	class stack : public vector<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// 基类是类模板时，需要指定⼀下类域，
//			// 否则编译报错:error C3861: “push_back”: 找不到标识符
//			// 因为stack<int>实例化时，也实例化vector<int>了
//			// 但是模版是按需实例化，调用了那个成员函数就实例化那个，push_back等成员函数未实例化，所以找不到
//			vector<T>::push_back(x);
//		}
//
//		void pop()
//		{
//			vector<T>::pop_back();
//		}
//
//		const T& top()
//		{
//			return vector<T>::back();
//		}
//
//		bool empty()
//		{
//			return vector<T>::empty();
//		}
//	};
//}
//
//int main()
//{
//	Lotso::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//
//	// 但是模版是按需实例化，调用了哪个成员函数，就实例化哪个
//	// 构造/析构/push_back， 其他成员函数就不会实例化
//	//vector<int> v;
//	//v.push_back(1);
//
//	return 0;
//}



//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	int i = 1;
//	double d = i;
//	const double& rd = i;
//
//	string s1 = "1111";
//	const string& rs = "111111";
//	//上面的转换在之前类和对象以及其它的一些地方都讲到过，这里就不说了,主要是对比
//
//	Student sobj;
//	// 1.派生类对象可以赋值给基类的指针/引用，这里跟前面不太一样
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	// 派生类对象可以赋值给基类的对象是通过调用后面会讲解的基类的拷⻉构造完成的
//	Person pobj = sobj;
//	//2.基类对象不能赋值给派生类对象，这里会编译报错
//	//sobj = pobj;
//	//sobj = (Student)pobj;//这样也不行
//
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		//同名成员构成隐藏，只在乎是否同名，参数什么的都不用管
//		cout << _num << endl;//999
//		cout << Person::_num << endl;//可以类名::_num
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s;
//	s.Print();
//}
//

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	//有同名成员构成隐藏，不管参数
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(10);
//	//b.fun();//这样不行，因为A里面那个无参的func被隐藏了，所以这里如果不带参数的话也调用不了b里面的。
//	//b.A::fun();//可以这样写。
//
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name)
//		:_name()
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)//传的是派生类的话也可以转换，前面讲过
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;//姓名
//
//};


//其实这里和前面学的默认成员函数规则差别也不大，还是想明白下面两点
// 1.我们不写，默认生成的函数行为是什么?是否符合需求
// 2.不符合，我们要自己实现，如何实现？

//class Student :public Person
//{
//public:
//	Student(const char* name = "赵四",int num = 18, const char* address = "西安")
//		:Person(name)//这里可以显示写一下(不能直接用_name)，其实就把他当成一个自定义类型成员变量就可以了。基类的成员当成一个整体。
//		,_num(num)
//		,_address(address)
//	{
//		cout << "Student()" << endl;
//	}
//
//	//这里其实只用显示写一下构造就行，拷贝，赋值重载，析构这里因为不涉及资源需要深拷贝和手动释放，默认生成的就行
//	//但是我们还是写出来感受一下
//
//	Student(const Student& s)
//		:Person(s)//和上面构造一样，这里传s到Person的拷贝构造也是可以的，之前讲过
//		,_num(s._num)
//		,_address(s._address)
//	{
//		//涉及深拷贝的话就需要自己手动处理了
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_num = s._num;
//			_address = s._address;
//		}
//
//		//涉及深拷贝，需要自己实现
//		return *this;
//	}
//	~Student()
//	{
//		//不用显示调用基类析构，编译器会在派生类析构结束后自动调用析构
//		//Person::~Person();//前面也需要Person::~Person，有一定历史原因，有提过
//		// 再就是这里如果显示调用无法保证析构先子后父的原则，构造是先父后子
//		// 先父后子：我们联想一下之前初始化列表按声明顺序来的原理
//		// 先子后父：我们可以想一下如果先析构父类，那么子类的成员如果需要访问父类就出问题了
//		//………………
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num;		 // 学号
//	string _address; // 地址
//	// int* _ptr;
//};
//
////构造
////继承的基成员变量(整体对象)+自己的成员变量(遵循普通的规则，跟类和对象部分一样)
////默认生成的构造，派生类自己的成员，内置类型不确定，自定义类型调用默认构造，基类部分调用默认构造
//
////本质可以把派生类当做一个自定义成员变量(基类)的普通类总，跟普通类原则基本一样
//
////派生类一般要自己实现构造，不需要显示写析构，构造函数，赋值重载，除法派生类有深拷贝的资源需要处理
//
//int main()
//{
//	Student s1;
//	//Student s2("小明",10);
//	//Student s3(s2);
//
//	////可以直接这样用
//	//s1 = s3;
//	//Person p = s1;//可以直接这样用
//
//	return 0;
//}