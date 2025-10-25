#include<iostream>
using namespace std;

////抽象类
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//
//class Benz :public Car
//{
//public:
//	//这里如果没有重写实现的话，也会是抽象类
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMV-操控" << endl;
//	}
//};
//
//int main()
//{
//	//Car car;//抽象类无法实例化出对象
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
//
//class Base
//{
//public:
//	
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//protected:
//	int _b = 1;
//	char _ch = 'x';
//};
//int main()
//{
//	Base b;
//	//除了我们能看到的_b和_ch，其实有虚函数的类就会有一个虚函数表指针(32位下4字节,64位下8字节)
//	//因为⼀个类所有虚函数的地址要被放到这个类对象的虚函数表中，虚函数表也简称虚表。
//	cout << sizeof(b) << endl;//32位：4+4+1->12
//	return 0;
//}



//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//private:
//	string _name;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-打折" << endl; }
//private:
//	string _id;
//};
//
//void Func(Person ptr)
//{
//	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//	// 但是跟ptr没关系，而是由ptr指向的对象决定的。
//	ptr.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	//这三个的虚函数表是一样的，同类型的对象共用一虚表
//	Person p1;
//	Person p2;
//	Person p3;
//
//	return 0;
//}


//class Base {
//	public:
//		virtual void func1() { cout << "Base::func1" << endl; }
//		virtual void func2() { cout << "Base::func2" << endl; }
//		void func5() { cout << "Base::func5" << endl; }
//	protected:
//		int a = 1;
//	};
//	
//	class Derive : public Base
//	{
//	public:
//		// 重写基类的func1
//		virtual void func1() { cout << "Derive::func1" << endl; }
//		virtual void func3() { cout << "Derive::func1" << endl; }
//		void func4() { cout << "Derive::func4" << endl; }
//	protected:
//		int b = 2;
//	};
//
//	int main()
//	{
//		Base b;
//		Derive d;
//	
//		return 0;
//	}
	


	//int main()
	//{
	//	int i = 0;
	//	static int j = 1;
	//	int* p1 = new int;
	//	const char* p2 = "xxxxxxxx";
	//	printf("栈:%p\n", &i);
	//	printf("静态区:%p\n", &j);
	//	printf("堆:%p\n", p1);
	//	printf("常量区:%p\n", p2);
	//
	//	Base b;
	//	Derive d;
	//
	//	printf("Base虚函数表地址:%p\n", *((int*)&b));
	//	printf("Derive虚函数表地址:%p\n", *((int*)&d));
	//
	//	printf("虚函数地址:%p\n", &Base::func1);
	//	printf("普通函数地址:%p\n", &Base::func5);
	//}