#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
using namespace std;
//
//
////基类/父类
//class Person
//{
//// 公共成员：子类和类外都能访问
//public:
//	//进入校园/图书馆/实验室刷二维码等身份认证
//	void identity()
//	{
//		cout << "void identity():" << _name << endl;
//	}
//	void func()
//	{
//		cout << _age << endl;
//	}
//
//// 保护成员：子类能访问，类外不能访问（专门为继承设计）
//protected:
//	string _name = "赵四";//姓名
//	string _address;//地址
//	string _tel;//电话
//
//// 私有成员：子类和类外都不能直接访问（像“爸爸的私房钱”）
//private:
//	int _age = 18;//年龄
//};
//
//// 子类Student：公有继承Person
////class的话不写默认是私有继承，struct是公有继承
//// class Student:Person
//class Student : public Person
//{
//public:
//	//学习
//	void study()
//	{
//		//……
//		//基类私有成员(爸爸的私房钱)，派生类	中不可见，语法限制上不能直接使用
//		//cout << _age << endl;
//		
//		//父类公有函数能间接访问私有成员
//		func();
//	}
//protected://在继承中保护用的比较多
//	int _stuid;//学号
//};
//
//// 子类Teacher：公有继承Person
//class Teacher : public Person
//{
//public:
//	//授课
//	void teaching()
//	{
//		//…………
//	}
//protected:
//	string title;//职称
//};
//
//// 测试：子类能直接用父类的函数
//int main()
//{
//	Student s;
//	Teacher t;
//	s.identity();// 用父类的identity，输出“赵四”
//	s.study();// 用子类的study，调用父类的func,输出了18
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
//	// 1. 子类对象 → 父类指针/引用（隐式转换，安全）
//	Person* pp = &sobj;// 父类指针指向子类对象的“父类部分”
//	Person& rp = sobj;// 父类引用引用子类对象的“父类部分”
//
//	// 2. 子类对象 → 父类对象（调用父类拷贝构造，只拷贝父类部分）
//	// 派生类对象可以赋值给基类的对象是通过调用后面会讲解的基类的拷⻉构造完成的
//	Person pobj = sobj;
//
//	//3. 父类对象 → 子类对象（编译报错，不安全）
//	//sobj = pobj;//错误：父类没有子类的成员（比如学号）
//	//sobj = (Student)pobj;// 强制转换也不行
//
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 父类的_num：身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		// 同名变量：默认访问子类的_num（学号）
//		// 同名成员构成隐藏，只在乎是否同名，参数什么的都不用管
//		cout << "子类的_num：" << _num << endl;//输出999
//
//		// 想访问父类的_num：必须加“父类::”
//		cout << "父类的_num："<<Person::_num << endl;//输出111
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


//class A
//{
//public:
//	// 父类无参函数
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	// 子类有参函数：函数名和父类相同，构成隐藏
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(10); // 调用子类的fun(int)，输出“func(int i)10”
//	// b.fun(); // 编译报错：父类的fun()被隐藏了，不能直接调用
//	b.A::fun(); // 想调用父类的fun()：加“父类::”，输出“func()”
//	return 0;
//}


class Person
{
public:
	// 父类带参构造（无默认构造）
	Person(const char* name)
		:_name()// 初始化父类的_name
	{
		cout << "Person()" << endl;
	}

	// 父类拷贝构造
	Person(const Person& p)//传的是派生类的话也可以转换，前面讲过
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;//姓名

};


//其实这里和前面学的默认成员函数规则差别也不大，还是想明白下面两点
// 1.我们不写，默认生成的函数行为是什么?是否符合需求
// 2.不符合，我们要自己实现，如何实现？

class Student :public Person
{
public:
	// 子类构造：必须在初始化列表显式调用父类构造
	Student(const char* name = "赵四",int num = 18, const char* address = "西安")
		//这里可以显示写一下(不能直接用_name)，其实就把他当成一个自定义类型成员变量就可以了。基类的成员当成一个整体。
		:Person(name)// 先初始化父类（必须写在前面）
		,_num(num)// 再初始化子类自己的成员
		,_address(address)
	{
		cout << "Student()" << endl;
	}

	//这里其实只用显示写一下构造就行，拷贝，赋值重载，析构这里因为不涉及资源需要深拷贝和手动释放，默认生成的就行
	//但是我们还是写出来感受一下

	// 子类拷贝构造
	Student(const Student& s)
		:Person(s)// 调用父类拷贝构造，拷贝父类部分（s是子类，能隐式转父类）
		,_num(s._num)// 拷贝子类自己的学号
		,_address(s._address)// 拷贝子类自己的地址
	{
		// 如果有深拷贝资源（比如int*），这里就要手动处理了。
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)// 防止自己赋值自己
		{
			// 先赋值父类部分
			Person::operator=(s);
			// 再赋值子类自己的成员
			_num = s._num;
			_address = s._address;

			// 如果有深拷贝资源在这里处理
		}

		return *this;
	}
	~Student()
	{
		//不用显示调用基类析构，编译器会在派生类析构结束后自动调用析构
		//Person::~Person();//前面也需要Person::~Person，有一定历史原因，有提过
		// 再就是这里如果显示调用无法保证析构先子后父的原则，构造是先父后子
		// 先父后子：我们联想一下之前初始化列表按声明顺序来的原理
		// 先子后父：我们可以想一下如果先析构父类，那么子类的成员如果需要访问父类就出问题了
		//………………
		// 先执行子类析构逻辑（比如释放子类的资源）
		cout << "~Student()" << endl;
		// 编译器自动调用父类析构：~Person()
	}
protected:
	int _num;		 // 学号
	string _address; // 地址
	// int* _ptr;
};
//
////构造
////继承的基成员变量(整体对象)+自己的成员变量(遵循普通的规则，跟类和对象部分一样)
////默认生成的构造，派生类自己的成员，内置类型不确定，自定义类型调用默认构造，基类部分调用默认构造
//
////本质可以把派生类当做一个自定义成员变量(基类)的普通类总，跟普通类原则基本一样
//
////派生类一般要自己实现构造，不需要显示写析构，构造函数，赋值重载，除法派生类有深拷贝的资源需要处理
//
int main()
{
 	// 构造顺序：先Person(),再Student()
	// 先父后子：我们联想一下之前初始化列表按声明顺序来的原理
	// 析构顺序：先~Student()，再~Person()
	// 先子后父：我们可以想一下如果先析构父类，那么子类的成员如果需要访问父类就出问题了
	Student s1;
	//Student s2("小明",10);
	//Student s3(s2);

	////可以直接这样用
	//s1 = s3;
	//Person p = s1;//可以直接这样用

	return 0;
}

//int main()
//{
//	
//	// 构造顺序：先调用Person(name)，再调用Student()
//	Student s1("张三", 20, "北京");
//	return 0;
//}