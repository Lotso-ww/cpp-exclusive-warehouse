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

#include"Stack.h"

int main()
{
	Stack st;
	st.Init();
	return 0;
}