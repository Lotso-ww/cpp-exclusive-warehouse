#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	const int a = 0;
//	///int& b = a;
//	//--这样不行，因为我a被const修饰只能读不能写，那b作为我的别名，反而又可以读又可以写是不合理的
//	//属于权限放大，权限放大是不行的;可以像下面这样写
//	const int& b = a;
//
//	//但是权限缩小是可以的
//	int c = 0;
//	const int& d = c;//我原本可读可写，我d身为c的别名只能读，这是可以的。
//
//	//那这个算是权限放大吗？
//	const int k = 0;
//	int e = k;//不算，这个不是权限放大，而是拷贝赋值
//
//
//	return 0;
//}


////权限的放大和缩小，只存在于const指针和const引用
////我们再来看看指针
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	const int a = 0;
//	const int* p1 = &a;
//	//int& p2 = p1;
//	//这个也属于权限的放大，得写成下面这样
//	const int* p2 = p1;
//
//	//但是权限缩小还是可以的
//	int c = 0;
//	int* p3 = &c;
//	const int* p4 = p3;
//
//	return 0;
//}


////const可以引用常量,作为函数参数时如果不是为了让形参的改变可以影响实参,是可以const修饰引用的，这样传参的时候选择更多
//
//#include<iostream>
//using namespace std;
//void func1(int&x)
//{
//	//…………
//}
//
//void func2(const int& x)
//{
//	//…………
//}
//
//int main()
//{
//	const int& a = 0;
//
//	//两个函数传这个参数都可以，因为就算是第二个函数这里也就是权限缩小了，是可行的
//	int y = 0;
//	func1(y);
//	func2(y);
//
//	const int z = 1;
//	//func1(z);//不行，因为这里这样传的话就相当于权限缩小，是不可取的。
//	func2(z);//可行，因为这个函数的形参部分是const修饰的引用
//
//	//直接传值的话也是跟上面一样的道理
//	//func1(2);//不行
//	func2(2);//可以
//
//	//再看一个比较特殊的例子，这个在下面也会讲到
//	double d = 2.2;
//	//func1(2.2);//这是肯定不行的，具体原因看下面的例子
//	func2(2.2);//这个是可以的，在传参时顺便进行了类型的转换，在一些特定场景下可以用上
//
//	return 0;
//}//


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i = 0;
//	double d = i;//这个是可以通过编译的，涉及隐式类型转换，因为int和double本质上都是关于数据类型大小的。
//
//	//像整型和指针就只能用强制类型转换,如下
//	int p = (int)&i;
//
//	//但是我们再来看看引用里面的使用
//	int j = 1;
//	//double& rd = j;//不行
//	const double& rd = j;//这个就可以了
//
//	//为什么呢?--我们先不急再看一个例子
//	
//	//int& rp = (int)&j;//不行
//	const int& rp = (int)&j;//可以
//
//	//-------------------------具体原因分析(配合图片)------------------------------------
//	//这是因为在引用里面,转换的过程中会产生一个临时对象保存中间值。
//	//所以实际上rb，rp引用的都是中间值，在C++里这个临时对象是具有常性的(即被const修饰)
//	//因此我们这里如果直接转换的话，就会出现权限放大的错误，我们必须使用常引用(即const修饰)
//
//
//	return 0;
//}

//指针和引用的关系



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//inline内联函数，宏的坑很多，C++建议用const,enum,inline替代宏
//宏函数就更坑了，我们使用inline来代替它，宏函数坑在哪里呢？

//我们就拿实现一个ADD函数为例，就能出现各种错误

////错误写法一:
//#define ADD(int a,int b) return a+b;
////这个肯定是错的，而且错的离谱，我们需要牢牢记住宏是一个替换机制,这里写成跟函数完全一样的肯定有问题

////错误写法二：
////#define ADD(a,b) a+b;
////宏定义不要带分号
//#define ADD(a,b) a+b
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int ret1 = ADD(1, 2);
//	//展开之后:int ret1 = 1 + 2;;,会出现两个分号，这里还不会报错，我们再来看看下面的
//	//int ret2 = ADD(1, 2) * 3;//这里就出问题了
//	
//	//我们就算不带分号，上面这个ret2最后的值也是错的
//	int ret2 = ADD(1, 2) * 3;//我们想要得到的是9，但是我们打印出来是7
//	cout << ret2 << '\n';
//    //因为展开之后:1 + 2 * 3 = 7//这里的优先级被影响了
//
//	return 0;
//}



//错误写法三:
//#define ADD(a,b) (a+b)
//#include<iostream>
//using namespace std;
//
//int main()
//{	
//	//这样写ret2打印出来的结果是我们想要的9
//	int ret2 = ADD(1, 2) * 3;
//	cout << ret2 << '\n';
//
//	//但是这种写法还是存在一些问题的
//	int x = 0, y = 1;
//	ADD(x | y, x & y);
//	//展开会变成:(x | y + x & y)
//	//+号的优先级高于 |和& 所以这里先执行y+x,跟我的目的不符合
//
//	return 0;
//}



////正确写法:
//#define ADD(a,b) ( (a) + (b) )
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//这样写ret2打印出来的结果是我们想要的9
//	int ret2 = ADD(1, 2) * 3;
//	cout << ret2 << '\n';
//
//	//这种写法也没问题了
//	int x = 0, y = 1;
//	ADD(x | y, x & y);
//	//展开会变成:( (x | y) + (x & y) ),符合我们的目的
//	
//
//	return 0;
//}

//宏函数这么复杂，容易写出问题，还不能调试
//那我们为什么还要用它呢，它的优势在于什么呢？
//优点:高频调用小函数时，写成宏函数，可以提高效率，预处理阶段宏会替换，提高效率，不建立栈帧


//在C++中我们觉得宏函数太麻烦，使用内联函数的话写法如下
//inline int ADD(int a, int b)
//{
//	return a + b;
//}
////跟函数的写法差不多，但是是不一样的。它编译是直接展开的跟宏一样,不会创建栈帧空间



//#include<iostream>
//using namespace std;
//
////转反汇编看，发现还是有call还是创建了栈帧，这是为什么
//inline int ADD(int a, int b)
//{
//	return a + b;
//}
////因为默认debug版本下，为了方便调试，inline也不展开。
////我们需要设置一下--这里大家可以自己测试看看，最号=好用低版本的vs
//
//int main()
//{
//	int ret2 = ADD(1, 2) * 3;
//	cout << ret2 << '\n';//打印出来也是9，完全没有问题
//
//	return 0;
//}



//inline只是一个建议，展开还是创建空间由编译器说的算，递归和代码多的函数可能就不会展开 ，为什么在博客里面再详细讲把
//#include<iostream>
//using namespace std;
//
//inline int ADD(int a, int b)
//{
//	a += 1;
//	a += 1;
//	a += 1;
//	a += 1;
//	a += 1;
//	a += 1;
//	a += 1;
//	a += 1;
//	a += 1;
//	a += 1;
//	//5个的时候还是可以展开的，10个就不行了
//	return a + b;
//}
//
//int main()
//{
//	int ret2 = ADD(1, 2) * 3;
//	cout << ret2 << '\n';
//
//	return 0;
//}


//为什么只是建议呢？



////inline不建议声明和定义放离到两个文件，分离会导致链接错误。因为inline被展开，就没有函数地址，链接时会出错
//#include"SeqList.h"
//
//int main()
//{
//	SL s;
//	//我实现用的引用所以不用传地址
//	SLInit(s); // call 地址
//
//
//	return 0;
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//nullptr

#include<iostream>
using namespace std;

void f(int x)
{
	cout << "f(int x)" << endl;
}

void f(int* ptr)
{
	cout << "f(int* ptr)" << endl;
}

int main()
{
	f(0);
	f(NULL);
	//f((void*)0);--有个图片
	//用上面的都会执行出来函数1，而不会是函数2

	f(nullptr);//但是用nullptr就很清晰了，可以很好处理这个问题

	int* p1 = NULL;
	char* p2 = NULL;

	//以后我们在C++里面置为空都这样写
	int* p3 = nullptr;
	char* p4 = nullptr;

	return 0;
}