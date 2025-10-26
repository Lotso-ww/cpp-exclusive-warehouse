#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;



////必须要有，不然影响后面的协变
//class A {};
//class B:public A {};
//
//////多态
//class Person
//{
//public:
//	//协变(了解)
//	//派生类重写基类虚函数时，与基类虚函数返回值类型不同。即基类虚函数返回基类对象的指针或者引用
//	//派生类虚函数返回派⽣类对象的指针或者引用时，称为协变。
//	virtual A* BuyTicket() { cout << "买票-全价" << endl; return nullptr;
//	}
//};
//
////虚函数的重写/覆盖：派生类中有⼀个跟基类完全相同的虚函数(即派⽣类虚函数与基类虚函数的返回值类型、函数名字、参数列表完全相同)，称派生类的虚函数重写了基类的虚函数。
////注意：在重写基类虚函数时，派⽣类的虚函数在不加virtual关键字时
////虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性)
////但是该种写法不是很规范，不建议这样使⽤，不过在考试选择题中，经常会故意埋这个坑，让你判断是否构成多态。
//
//class Student :public Person
//{
//public:
//	//virtual B*BuyTicket() { cout << "买票-打折" << endl; }
//	//可以不带virtual
//	B* BuyTicket() { cout << "买票-打折" << endl; return nullptr; }
//};
//
//void Func(Person* ptr)//基类的指针
//{
//	//多态调用:看的是指针指向的对象
//	//这里可以看到虽然都是Person指针Ptr在调⽤BuyTicket
//	//但是跟ptr没关系，⽽是由ptr指向的对象决定的。
//	ptr->BuyTicket();//基类的指针调用
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}

//// 基类：Person
//class Person 
//{
//public:
//    // 虚函数：标记为需要参与多态
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//// 派生类：Student（继承Person）
//class Student : public Person 
//{
//public:
//    // 重写基类虚函数：函数名、参数、返回值完全一致
//    //派生类中virtual也可以省略
//    virtual void BuyTicket() { cout << "买票-打折" << endl; }
//};
//
//// 派生类：Soldier（继承Person）
//class Soldier : public Person 
//{
//public:
//    // 重写基类虚函数
//    // 派生类中virtual也可以省略
//    virtual void BuyTicket() { cout << "买票-优先" << endl; }
//};
//
//// 关键：用基类指针调用虚函数（满足多态条件1）
////这里也可以用基类引用
//void Func(Person* ptr) {
//    // 运行时根据ptr指向的对象类型，调用对应类的BuyTicket
//    //Person* ptr
//    ptr->BuyTicket();
//    //如果是基类引用 Person& ptr
//    //ptr.BuyTicket();
//}
//
//int main() {
//    Person ps;    // 基类对象
//    Student st;   // 派生类对象（学生）
//    Soldier sr;   // 派生类对象（军人）
//
//    Func(&ps);  // 指向基类对象 → 调用Person::BuyTicket → 输出“买票-全价”
//    Func(&st);  // 指向学生对象 → 调用Student::BuyTicket → 输出“买票-打折”
//    Func(&sr);  // 指向军人对象 → 调用Soldier::BuyTicket → 输出“买票-优先”
//    return 0;
//}

//class Animal
//{
//public:
//	//但是这里必须带virtual
//	virtual void talk() const
//	{
//		std::cout << "吱吱" << std::endl;
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	// 重写实现
//	// 注意是实现部分哈，这里很重要
//	void talk() const
//	{
//		std::cout << "汪汪" << std::endl;
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "(>^ω^<)喵" << std::endl;
//	}
//};
//
//void letsHear(Animal& animal)
//{
//	animal.talk();
//}
//
//int main()
//{
//	Cat cat;
//	Dog dog;
//	letsHear(cat);
//	letsHear(dog);
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//
//	B* q = new B;
//	q->func();
//
//	return 0;
//}

//class A {
//public:
//    // 基类析构函数加virtual，支持重写
//    virtual ~A() {
//        cout << "~A()" << endl;
//    }
//};
//
//class B : public A {
//public:
//    // 派生类析构函数：自动构成重写（加不加virtual都可以）
//    ~B() {
//        cout << "~B()->delete:" << _p << endl;
//        delete _p; // 释放派生类动态申请的资源
//    }
//protected:
//    int* _p = new int[10]; // 派生类动态申请的数组
//};
//
//void test()
//{
//    cout << "--------额外测试结果--------" << endl;
//    //额外测试1
//    //析构顺序：~B(),~A(),~A()
//    //其中第一个~A()是因为子类B析构完后调用基类的,后面一个是a对象析构
//    A a;
//    B b;
//}
//// 基类只要保障了析构函数是虚函数，下面场景就不会存在内存泄漏
//int main() {
//    // 基类指针指向派生类对象
//    A* ptr1 = new B;
//    delete ptr1; // 多态调用：先调用~B()，再调用~A()，无内存泄漏
//
//    // 基类指针指向基类对象
//    A* ptr2 = new A;
//    delete ptr2; // 调用~A()
//
//    test();
//    return 0;
//}


//class Car {
//public:
//	//virtual void Dirve()
//	virtual void Drive() //final
//		//final是不让重写
//	{}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//	//override是用来在派生类中检查时否构成重写
//};
//
//int main()
//{
//	return 0;
//}


//class Car {
//public:
//    // 基类虚函数：Drive（注意拼写是Drive，不是Dirve）
//    virtual void Drive() {
//        cout << "Car-行驶" << endl;
//    }
//};
//
//class Benz : public Car {
//public:
//    // 错误示例：函数名写成Dirve，加override后编译报错
//    // virtual void Dirve() override { cout << "Benz-舒适" << endl; }
//
//    // 正确示例：函数名正确，override检测通过
//    virtual void Drive() override {
//        cout << "Benz-舒适" << endl;
//    }
//};
//
//int main() 
//{
//    Car* p = new Benz;
//    p->Drive(); // 多态调用：输出“Benz-舒适”
//    return 0;
//}

//class Car 
//{
//public:
//    // 基类虚函数加final：禁止派生类重写
//    virtual void Drive() final 
//    {
//        cout << "Car-行驶" << endl;
//    }
//};
//
//class Benz : public Car 
//{
//public:
//    // 错误：Drive()被final修饰，无法重写，编译报错
//    // virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//
//int main() 
//{
//    return 0;
//}


//class Base
//{
//public:
//    // 1. 重载：同一作用域，函数名相同，参数不同
//    void func(int a) { cout << "Base::func(int)" << endl; }
//    void func(double b) { cout << "Base::func(double)" << endl; }
//
//    // 虚函数：用于重写
//    virtual void show() { cout << "Base::show()" << endl; }
//};
//
//class Derive : public Base
//{
//public:
//    // 2. 重写：基类与派生类，虚函数+函数名/参数/返回值相同
//    virtual void show() override { cout << "Derive::show()" << endl; }
//
//    // 3. 隐藏：基类与派生类，函数名相同但不构成重写
//    void func(int a, int b) { cout << "Derive::func(int,int)" << endl; }
//};
//
//int main()
//{
//    Derive d;
//    d.func(1, 2);    // 调用Derive::func（隐藏基类func）
//    // d.func(3);    // 编译报错：基类func(int)被隐藏，需显式调用Base::func(3)
//
//    Base* p = &d;
//    p->show();       // 多态调用：Derive::show（重写）
//    return 0;
//}