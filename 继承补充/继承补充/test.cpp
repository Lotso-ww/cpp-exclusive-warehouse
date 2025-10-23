#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


////实现⼀个不能被继承的类
//// 方法1：C++98
//class Base 
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//private:
//	//C++98的方法：构造函数私有的类不能被继承
//	Base()
//	{}
//};
//
//class Derive : Base
//{};
//
//int main()
//{
//	//Base b;
//	//Derive d;
//
//	return 0;
//}



////实现⼀个不能被继承的类
//// 方法2：C++11：新增了⼀个final关键字，final修改基类，派⽣类就不能继承了。
//class Base final
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//};
//
//class Derive : Base
//{
//};
//
//int main()
//{
//	//Base b;
//	//Derive d;
//
//	return 0;
//}


//class Student;
//
//class Person
//{
//	//友元函数不能被子类继承
//	friend void Display(const Person& p, const Student& s);
//public:
//protected:
//	string _name="张三";//姓名
//};
//
//class Student :public Person
//{
//	//在子类里面也声明一下
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum=1301984;//学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	// 编译报错：error C2248: “Student::_stuNum”: 无法访问 protected 成员
//	// 解决方案：Display也变成Student 的友元即可
//
//	Display(p, s);
//
//	return 0;
//}

//
//class Person
//{
//public:
//	string _name;
//	static int _count;
//};
//
//int Person::_count = 0;
//
//class Student :public Person
//{
//protected:
//	int _stuNum;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	// 这里的运行结果可以看到非静态成员_name的地址是不一样的
//	// 说明派生类继承下来了，父派生类对象各有一份
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//	cout << endl;
//	
//	// 这里的运行结果可以看到静态成员_count的地址是一样的
//	// 说明派生类和基类共用同一份静态成员
//	cout << &p._count << endl;
//	cout << &s._count << endl;
//	cout << endl;
//	
//	// 公有的情况下，父派生类指定类域都可以访问静态成员
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	cout << endl;
//	
//	return 0;
//}


////菱形继承,虚继承等
//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{}
//public:
//	string _name; // 姓名
//	/*int _age;
//	int _tel;
//	string _address;*/
//};
//
////class Student : public Person
////virtual，谁导致的就在继承时加
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{}
//protected:
//	int _num; //学号
//};
//
////class Teacher : public Person
////virtual，谁导致的就在继承时加
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{}
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name1)
//		,Student(name2, 1)
//		,Teacher(name3, 2)
//		, _majorCourse("计算机")
//	{}
//
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//
//	//这里菱形继承会有一些问题，数据冗余以及二义性
//	// 编译报错：error C2385: 对“_name”的访问不明确
//	//Assistant a;
//	//a._name = "peter";
//
//	//可以指定着这样写，要么就使用虚继承
//	//a.Student::_name = "xxxx";
//	//a.Teacher::_name = "yyyy";
//
//	// 思考一下这里a对象中_name是"张三", "李四", "王五"中的哪一个？
//	Assistant a("张三", "李四", "王五");
//	//上面有三次Person(name)，但其实就只有在Assistant里一次，其它两次会跳过。
//	//所以是张三
//	cout  << endl;
//
//
//	return 0;
//}



////多继承中指针偏移问题？下⾯说法正确的是( )
//// A.p1== p2 == p3 B：p1 < p2 < p3 C：p1 == p3 != p2 D：p1 != p2 != p3
//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}

////IO库中的菱形虚拟继承
//template<class CharT, class Traits = std::char_traits<CharT>>
//class basic_ostream : virtual public std::basic_ios<CharT, Traits>
//{
//};
//
//template<class CharT, class Traits = std::char_traits<CharT>>
//class basic_istream : virtual public std::basic_ios<CharT, Traits>
//{
//};
// 

//// 继承：is-a,白盒，耦合度高
//class stack :public vector
//{
//
//};
////组合 has-a，黑盒，耦合度低
//class stack
//{
//	vector _v;
//};
//能多用组合就用组合