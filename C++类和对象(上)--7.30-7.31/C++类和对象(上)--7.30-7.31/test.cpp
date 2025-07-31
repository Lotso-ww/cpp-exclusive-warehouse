#define _CRT_SECURE_NO_WARNINGS 1

//// C++中数据和方法封装放到了一起，都在类里面
//// 封装的本质体现了更严格的规范管理
////我们直接大概定义一个看一看
//#include<iostream>
//using namespace std;
//
//class Stack 
//{
//	//访问限定符，class中没给的话里面默认是私有
//public://公有，一般是把成员函数公有，在类外也可以直接访问
//	//成员函数
//	void Init(int capacity = 4)//可以不用像之前一样前面加个类似ST的区分
//	{
//		_arr = nullptr;//这里实际上是要malloc的
//		_top = 0;
//		_capacity = 0;
//	}
//	void Push(int x)
//	{
//
//	}
////public这个访问限定符到这里结束
//private://私有，一般是把成员变量私有，在类外不能直接访问，更规范。
//	//成员变量
//	int* _arr;
//	int _top;
//	int _capacity;
//
//};//分号不能掉
////private后面没有访问限定符了，到}这里结束
//
////以前C语言中只能向上找，类中向上向下都可以。
////所以我们前面先实现公有的成员函数，再定义的私有里面的成员变量也是可以的
//
//int main()
//{
//	Stack s1;
//	s1.Init();
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//
//	//像之前C语言中这样不规范的写发，我们通过C++的访问限定符规范了
//	//s1.top++;//私有成员，类外无法直接访问
//
//	return 0;
//}

//C++中两种比较规范的写法
//驼峰法:
//      StackInit   函数 ，开头单词首字母大写开头+后续每个单词首字母都大写
//      initCpacity 变量 ，开头单词首字母小写开头+后续每个单词首字母大写
//Google C++风格:
//       stack_init    函数       init_capacity 变量
//都是单词之间用下划线分隔

////兼容C中struct的用法，升级成了类，就算不typedef也可以不用带前面的struct了
//typedef struct A
//{
//	void func()
//	{}
//
//	int a1;
//	int a2;
//}AA;
//
//// 升级成了类
//struct B
//{
//	void Init()
//	{}
//
//private:
//	int b1;
//	int b2;
//};
//
//int main()
//{
//	//struct A aa1;//不需要这样写了
//	AA aa2;
//
//	B bb1;
//	bb1.Init();
//}
//
//
////一般情况下我们更喜欢用class,但是像链表定义节点这种还是比较喜欢用struct的(默认公有)
//struct ListNode
//{
//	//访问限定符，struct中没给的话里面默认是公有
//public://所以这里其实给不给这个公有都行
//	int data;
//	//struct ListNode* next;//不需要这样写了
//	ListNode* next;
//};

//#include"Stack.h"
//
//int main()
//{
//	Stack st;
//	st.Init();
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////
//实例化

//#include<iostream>
//using namespace std;
//
//class Stack 
//{
//public:
//	//成员函数
//	void Init(int capacity = 4)
//	{
//		_arr = nullptr;
//		_top = 0;
//		_capacity = 0;
//	}
//	void Push(int x)
//	{
//
//	}
//private:
//	//成员变量，这里是声明，不开空间
//	int* _arr;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	//类实例化出对象s1，s2,这时才分配了空间
//	Stack s1;
//	Stack s2;
//
//	//成员函数不存在对象里面，而是在代码段里，通过调地址访问，这个在下面还会详细解释
//	s1.Init();//call 地址
//	s1.Init(100);
//
//	//但是成员变量是存在对象里面的
//
//	//就像s1._top和s2._top肯定不是同一个，但是s1.Init和s2.Init调的是同一个
//
//	//可以传对象也可以传类型，遵守内存对齐规则
//	cout << sizeof(s1) << '\n';
//	cout << sizeof(Stack) << '\n';
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//// 计算⼀下A/B/C实例化的对象是多大？
//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int _i;
//};
//class B
//{
//public:
//	void Print()
//	{
//		//...
//	}
//};
//class C
//{
//};
//int main()
//{
//	A a;
//	B b;
//	C c;
//	cout << sizeof(a) << endl;
//	//a的这个不用多说，根据内存对齐规则就可以算出来
//
//	//因为函数不存在对象里，所以b,c都是空类
//	//空类的大小为1,开1byte是为例占位，不存在实际数据，只是为了表示对象存在过
//	cout << sizeof(b) << endl;
//	cout << sizeof(c) << endl;
//
//	//大家可以想一下不开空间怎么表示对象存在过呢，不开地址怎么给呢？
//	//所以肯定是会给的
//
//	return 0;
//}


////////////////////////////////////////////////////////////////////////
//this指针

//#include<iostream>
//using namespace std;
//
//class Data 
//{
//public:
//	//成员函数
//	//所以这里应该是这样的
//	//void Init(Data* const this,int year,int month,int day)--也不能这样写出来
//	void Init(int year,int month,int day)
//	{
//		//但是这里的this是可以写的
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << '\n';
//	}
//private:
//	//成员变量,这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d1;
//	Data d2;
//
//	//函数体中没有关于不同对象的区分，那当d1调用Init和Print函数时，
//	//该函数是如何知道应该访问的是d1对象还是d2对象呢？
//	//其实这里就涉及到了this指针,它在函数实参和形参的位置是不可以显式出现的
//	//但是在函数体内可以出现
//
//	//d1.Init(&d1,2025,7,31);--但是这里不能这样写出来
//	d1.Init(2025, 7, 31);
//	//d2.Init(&d2,2025,9,1);--也不能写出来
//	d2.Init(2025, 7, 9);
//
//	//和Init同理
//	d1.Print();
//	d2.Print();
//
//	return 0;
//}



//看几个题目
//题目1--C.正常运行
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << this << endl;
//		cout << "A::Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();//call 地址
//	//因为这里的函数地址并不存在对象之中(而是直接通过地址调用的),this传过去也没影响
//	//所以这里不存在空指针的解引用
//
//	//如果改成这样呢
//	(*p).Print();
//	//也是一样的可以正常运行，这里转成反汇编看比较好，实际上是直接调用函数的
//	//注意:不要只看语法的表象。
//
//	return 0;
//}

//题目2--B.运行崩溃
#include<iostream>
using namespace std;
class A
{
public:
	void Print()
	{
		cout << this << endl;
		cout << "A::Print()" << endl;
		cout << _a << endl;//调用函数执行到这里时就有问题了
		//_a是成员变量，是存在对象里的，所以会出现问题。
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	p->Print();
	return 0;
}



//题目3--
//this是存在栈里面的，就是个形参一样。类似于局部变量。
//但是this还是很有可能存在寄存器里的


//C和C++实现Stack的对比

////C实现Stack
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//void STInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	ps->capacity = 0;
//}
//void STDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->top = ps->capacity = 0;
//}
//void STPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	// 满了， 扩容
//	if (ps->top == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//bool STEmpty(ST* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//void STPop(ST* ps)
//{
//	assert(ps);
//	assert(!STEmpty(ps));
//	ps->top--;
//}
//STDataType STTop(ST* ps)
//{
//	assert(ps);
//	assert(!STEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//int STSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//int main()
//{
//	ST s;
//	STInit(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//	STPush(&s, 3);
//	STPush(&s, 4);
//	while (!STEmpty(&s))
//	{
//		printf("%d\n", STTop(&s));
//		STPop(&s);
//	}
//	STDestroy(&s);
//	return 0;
//}

//
//C++实现Stack
#include<iostream>
using namespace std;
typedef int STDataType;
class Stack
{
public:
	// 成员函数
	void Init(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = n;
		_top = 0;
	}
	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;
	}
	void Pop()
	{
		assert(_top > 0);
		--_top;
	}
	bool Empty()
	{
		return _top == 0;
	}
	int Top()
	{
		assert(_top > 0);
		return _a[_top - 1];
	}
	void Destroy()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	// 成员变量
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};

int main()
{
	Stack s;
	s.Init();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	while (!s.Empty())
	{
		printf("%d\n", s.Top());
		s.Pop();
	}
	s.Destroy();
	return 0;
}