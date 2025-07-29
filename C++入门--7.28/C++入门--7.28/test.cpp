#define _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//取消同步流
//	//在io需求比较高的地方，比如需要大量输入的竞赛题中，加上以下3行代码,可以提高效率
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//}


//#include<iostream>
//using namespace std;
//
//void func(int a = 0)
//{
//	cout << a << '\n'<<'\n';
//}
//
////全缺省
//void func1(int a = 10,int b = 20,int c = 30)
//{
//	cout << "a= " << a << '\n';
//	cout << "b= " << b << '\n';
//	cout << "c= " << c << '\n'<<'\n';
//}
//
////半缺省
////从右至左依次缺省才可以，中间不能跳跃缺省，不能出现 int a=10,int b=20,int c或int a=10,int b,int c=30等这种情况
//void func2(int a , int b , int c=30)//如果非要a缺省的话，我们可以把a和c的位置换一下
//{
//	cout << "a= " << a << '\n';
//	cout << "b= " << b << '\n';
//	cout << "c= " << c << '\n'<<'\n';
//}
//
//int main()
//{
//	func(1);//1
//	func();//没有传参会打印缺省值
//
//	//以下4种都可以
//	func1(1, 2, 3);
//	func1(1, 2);
//	func1(1);
//	func1();
//	//这种不行，不能跳跃传参
//	/*func1(1, , 3);*/
//
//	func2(1, 2, 3);
//	func2(1,2);
//	return 0;
//}



//#include<iostream>
//#include"SeqList.h"
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	SL s;
//	SLInit(&s, n);//已经知道n的大小
//	//如果没有输入操作这里n就是不知道的，就会使用缺省的n=4
//
//	//为啥要定义这么一个n呢
//	//比如我要尾插1000个数据，那么不用这个的话，就要不停的扩容，会有消耗
//	for (int i=0;i<n;i++)
//	{
//		SLPushBack(&s, i);
//	}
//
//	//Find
//	//原来的find无法实现找顺序表中所有需要找的元素(重复的只会返回第一个)
//	//改了之后，通过下述操作可以找到所有的
//	//  5 4 6 3 4 7 4
//	// // 查找出所有的4
//	int x = SLFind(&s, 4);
//	while (x != -1)
//	{
//		x = SLFind(&s, 4, x + 1);
//	}
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//函数重载

//C语言不支持同名函数出现
//#include<stdio.h>
//int Add(int left, int right)
//{
//	//cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	//cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//
//int main()
//{
//	return 0;
//}

//1.函数参数类型不同
//#include<iostream>
//using namespace std;
//
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//
//int main()
//{
//	cout << Add(1, 2) << '\n';
//	cout << Add(1.1, 2.2) << '\n';
//	//自动识别函数传的参数类型，调用不同的函数；
//	return 0;
//}


////2.函数参数个数不同
//#include<iostream>
//using namespace std;
//
//void f1()
//{
//	cout << "f1()" << '\n';
//}
//
//void f1(int a)
//{
//	cout << "f1(int a)" << '\n';
//}
//
//int main()
//{
//	f1();
//	f1(1);
//	//根据传参的个数，自动识别调用对应函数
//	return 0;
//}

////3.函数类型顺序不同--本质上还是对应的函数参数类型不同
//#include<iostream>
//using namespace std;
//
//void f1(double a,int b)
//{
//	cout << "f1(double a,int b)" << '\n';
//}
//
//void f1(int a,double b)
//{
//	cout << "f1(int a,double b)" << '\n';
//}
//
//int main()
//{
//	f1(2.3,1);
//	f1(1,2.3);
//	//根据传参的顺序来调用对应函数
//	
//	return 0;
//}

//还有两种特殊情况，一个不能构成函数重载，一个构成了但是存在调用的歧义
////1.无法构成重载
//#include<iostream>
//using namespace std;
//
//void fork()
//{
//}
//
//int fork()//这里的问题可以点击红线截图查看
//{
//	return 1;
//}
//
//int main()
//{
//	//调用时无法确定调用那个
//	fork();
//	int x = fork();
//	return 0;
//}

////2.可以构成重载
////但是一些情况下调用存在歧义
//#include<iostream>
//using namespace std;
//
//void f1()
//{
//	cout << "f()" << endl;
//}
//
//void f1(int a = 10)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	f1(1);//这个可以
//	f1();//这样调用就不行了，不确定调用那一个
//	return 0;
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//引用

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i = 1;
//	int& j = i;//j是i的别名
//
//	//一个变量可以有多个别名，引用。别名也可以有它的别名
//	int& k = j;
//	k++;//k的变化会影响i和j
//
//	cout << &i << '\n';
//	cout << &j << '\n';
//	cout << &k << '\n';
//	//打印发现地址一样
//
//	//引用时必须先初始化
//	//int& x;//看报错
//	//x = i;
//
//	// 引用一旦引用一个实体，再不能引用其他实体,引用也不能改变指向
//	//所以这里的操作是赋值而不是引用
//	int m = 20;
//	k = m;
//
//	return 0;
//}

//指针，引用
//大部分情况下引用都可以替代指针，除了一些特殊情况，比如链表的树的节点的定义只能使用指针

//#include<iostream>
//using namespace std;
//
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	//swap函数交换值
//	int a = 1; int b = 7;
//	cout << a << " " << b << '\n';
//	swap(&a, &b);//用指针
//	cout << a << " " << b << '\n';
//	swap(a, b);//用引用
//	cout << a << " " << b << '\n';
//
//
//	return 0;
//}

//顺序表里面的引用使用，这里就不再提供具体操作和结构了
////void SLInit(SL* psl, int n = 4)
//void SLInit(SL& psl, int n = 4)

//int main()
//{
//	//SL s;
//	//	SLInit(&s);
//	//  SLInit(s);//不需要传地址了
//}


//替代二级指针使用
//#include<iostream>
//using namespace std;
//
//void swap(int**x, int** y)
//{
//	int*tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void swap(int*& x, int*& y)
//{
//	int*tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	//swap函数交换指针
//	int a = 1; int b = 7;
//	int* pa = &a; int* pb = &b;
//	cout <<*pa << " " <<*pb << '\n';
//	swap(&pa, &pb);//用指针
//	cout << *pa << " " << *pb << '\n';
//	swap(pa, pb);//用引用
//	cout << *pa << " " << *pb << '\n';
//
//
//	return 0;
//}

////在链表中的使用
//#include<iostream>
//using namespace std;
//
//typedef struct SListNode
//{
//	struct SListNode* next;
//	int val;
//}SLTNode;//, //*PSLTNode;
//
////typedef struct SListNode SLTNode;
////typedef struct SListNode* PSLTNode;
//
//
////void SLTPushBack(SLTNode** pphead, int x)
////{
////	SLTNode* newnode; // = malloc
////
////	if (*pphead == NULL)
////	{
////		*pphead = newnode;
////	}
////	else
////	{
////		// 找到尾结点，newnode链接到尾结点
////	}
////}
//
////void SLTPushBack(PSLTNode& phead, int x)//这个在书上有时候会用
//void SLTPushBack(SLTNode*& phead, int x)
//{
//	SLTNode* newnode = NULL; // = malloc，这里省掉过程
//
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//		// 找到尾结点，newnode链接到尾结点
//	}
//}
//
//
//int main()
//{
//	//用二级指针
//	SLTNode* plist = NULL;
//	//SLTPushBack(&plist, 1);
//	//SLTPushBack(&plist, 2);
//	//SLTPushBack(&plist, 3);
//	//SLTPushBack(&plist, 4);
//
//	//用引用
//	//PSLTNode plist = NULL;
//	SLTNode* plist = NULL;
//	SLTPushBack(plist, 1);
//	SLTPushBack(plist, 2);
//	SLTPushBack(plist, 3);
//	SLTPushBack(plist, 4);
//
//	return 0;
//}




//传值返回，传引用返回
//传值返回
//#include<iostream>
//using namespace std;
//int fun()
//{
//	int ret = 0;
//
//	return ret;
//}
//
//int main()
//{
//	int x = fun();//x接受的其实是ret的拷贝值，在fun函数销毁时ret就没了，通过临时变量带出
//	fun() += 1;//所以这里就无法直接修改
//	return 0;
//}

////传引用返回
//#include<iostream>
//using namespace std;
//
//int& fun()
//{
//	int ret = 0;
//
//	return ret;
//}
//
//int main()
//{
//	int&x = fun();
//	cout << x << '\n';//这里可能会是随机值，具体原因看图需要分析
//
//
//	int a[10];
//	 //数组是越界抽查
//	/*a[10] = 1;
//	a[11] = 1;
//	a[15] = 1;*/
//	//越界不一定报错，越界了的被修改和使用可能会报错
//
//	return 0;
//}


//如果需要使用这样是可以的
//#include<iostream>
//using namespace std;
//
//int& fun()
//{
//	static int ret = 0;
//
//	return ret;
//}
//
//int main()
//{
//	int&x = fun();
//	cout << x << '\n';
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int& func1()
//{
//	int ret = 0;
//	// ...
//	return ret;
//}
//
//int& func2()
//{
//	int y = 456;
//	// ...
//	return y;
//}
//
//int main()
//{
//	int& x = func1();
//	cout << x << endl;
//	func2();//明明没有修改x，但x的值还是会为y，这是因为fun1函数栈帧销毁后还给了操作系统，但是func2又使用了这块空间
//	//具体的需要画图分析
//	cout << x << endl;
//
//	return 0;
//}


//那我们什么时候可以使用到这个传引用返回呢
//我们拿顺序表这个数据结构为例子，当然栈也可以

//#include"SeqList.h"
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	SL s;
//	SLInit(s, 10);
//	for (size_t i = 0; i < 10; i++)
//	{
//		SLPushBack(s, i);
//	}
//
//	for (size_t i = 0; i < 10; i++)
//	{
//		cout << SLat(s, i) << " ";
//	}
//	cout << endl;
//
//	// 把顺序表第i个位置的值修改为x
//	int i = 0;
//	int x = 0;
//	cin >> i;
//	cin >> x;
//
//	//SLModify(&s, i, x);//不好用
//	SLat(s, i) = x;//用了返回引用这里就可以直接修改赋值了
//
//	for (size_t i = 0; i < 10; i++)
//	{
//		cout << SLat(s, i) << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i = 0;
//	//语法层面上引用不开空间，指针开空间
//	int& j = i;
//	int* p = &i;
//
//	j++;
//	(*p)++;
//
//	//但是我们转到反汇编，可以看出其实引用的底层就是指针，两个指令的反汇编代码都差不多，这个需要仔细观察一下
//
//	return 0;
//}