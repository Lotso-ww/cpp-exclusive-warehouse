#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

<<<<<<< HEAD
//// 前置声明：告诉编译器Student类存在
=======

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



////实现⼀个不能被继承的类//
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


>>>>>>> 9a50878a5b4b4012c36637143e69e6ae11178c51
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
//	cout << p._name << endl;//访问基类成员
//	cout << s._stuNum << endl;//访问派生类成员
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
//	// 公有的情况下，父类派生类指定类域都可以访问静态成员
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	cout << endl;
//	
//	return 0;
//}

//菱形继承
//// 顶层基类
//class Person {
//public:
//    string _name;  // 会被继承两次
//};
//
//// 中间基类1
//class Student : public Person {};
//
//// 中间基类2
//class Teacher : public Person {};
//
//// 最终派生类（菱形继承）
//class Assistant : public Student, public Teacher {};
//
//int main() {
//    Assistant a;
//    // a._name = "张三";  
//    // 编译报错：二义性（Student::_name还是Teacher::_name？）
//    // 只能显式指定，但数据冗余仍存在，没有解决
//    a.Student::_name = "李四";
//    a.Teacher::_name = "王五";
//    cout << a.Student::_name << endl;  // 输出李四
//    cout << a.Teacher::_name << endl;  // 输出王五
//    return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;

////顶层基类
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
//// 中间基类1：虚继承Person（添加virtual）
////virtual，谁导致的就在继承谁时加
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)// 虚继承下，中间基类暂时不初始化顶层基类
//		, _num(num)
//	{}
//protected:
//	int _num; //学号
//};
//
//// 中间基2：虚继承Person（添加virtual）
////virtual，谁导致的就在继承谁时加
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id)
//		:Person(name)// 虚继承下，中间基类暂时不初始化顶层基类
//		, _id(id)
//	{}
//protected:
//	int _id; // 职工编号
//};
//
//// 最终派生类：菱形继承（Person成员仅一份）
//class Assistant : public Student, public Teacher
//{
//public:
//  // 关键：虚继承下，顶层基类的构造由最终派生类显式调用
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name1)// 直接初始化顶层基类
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
//	// 思考一下这里a对象中_name是"张三", "李四", "王五"中的哪一个？
//	Assistant a("张三", "李四", "王五");
//	//上面有三次Person(name)，但其实就只有在Assistant里一次，其它两次会跳过。
//	//所以是张三
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
template<class CharT, class Traits = std::char_traits<CharT>>
class basic_ostream : virtual public std::basic_ios<CharT, Traits>
{
};

template<class CharT, class Traits = std::char_traits<CharT>>
class basic_istream : virtual public std::basic_ios<CharT, Traits>
{
};


// Tire(轮胎)和Car(⻋)更符合has-a的关系
class Tire {
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺⼨
};
class Car {
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // ⻋牌号
	Tire _t1; // 轮胎
	Tire _t2; // 轮胎
	Tire _t3; // 轮胎
	Tire _t4; // 轮胎
};


// Car和BMW/Benz更符合is-a的关系
class BMW : public Car {
public:
	void Drive() { cout << "好开-操控" << endl; }
};

class Benz : public Car {
public:
	void Drive() { cout << "好坐-舒适" << endl; }
};


// stack和vector的关系，既符合is-a，也符合has-a
template<class T>
class vector
{};
// 继承：is-a,白盒，耦合度高
template<class T>
class stack :public vector<T>
{};
//组合 has-a，黑盒，耦合度低
template<class T>
class stack
{
	vector<T> _v;
};
//能多用组合就用组合