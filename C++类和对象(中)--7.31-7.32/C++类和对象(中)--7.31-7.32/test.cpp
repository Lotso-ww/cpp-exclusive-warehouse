#define _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//using namespace std;
//
//class Date 
//{
//public:
////如果这里不自己显示构造函数，编译器会自动生成一个无参的默认构造函数
////默认构造函数：无参构造函数，全缺省构造函数，编译器默认生成的构造函数
////三种默认构造函数只能同时存在一个(第三个的原因不用多说，前两个是因为构成重载但传参啥都不传时会歧义)
//
//    //1.自己实现的无参数的构造函数(默认构造函数的一种)
//	Date()//函数名和类名相同，无返回值
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//	
//	//2.带参构造函数(可以和1同时存在)(不能和3同时存在,函数签名相同，构成了重定义)(不属于默认构造函数)
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	////3.全缺省构造函数(很好用，结合了1,2的功能)(但是不能和1或者2同时存在)(默认构造函数的一种)
//	//Date(int year = 1, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	//总结:两种使用方案：1+2或者直接用3
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << '\n';
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1; //会自动初始化，调用1或者3，不能同时存在(我上面给3注释掉了,因为2和3也不能同时存在)
//	Date d2(2025, 7, 31);//会调用3，不会有歧义
//
//	//Date d3();//这种写法是错误的
//	// 参考一下 Data func();你觉得它是对象还是函数呢？
//	//注意:如果通过无参构造函数创建对象时，对象后面不用跟括号。
//	//否则编译器无法区分这里是函数声明还是实例化对象
//
//	d1.Print();//1,1,1
//	d2.Print();//2025,7,31
//
//	return 0;
//}
//
////我们不写，编译器默认生成的构造对内置类型初始化没要求
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//如果这里不自己显示构造函数，编译器会自动生成一个无参的默认构造函数
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << '\n';
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();//打印出来结果是随机值
//
//	return 0;
//}

//可能会让很多人怀疑这里是不是默认生成了构造函数

////我们不写，编译器默认生成的构造，对于自定义类型成员变量，要求调用这个成员变量的默认构造函数初始化
////比如之前我们写过的两个栈实现队列
//#include<iostream>
//using namespace std;
//class Stack 
//{
//public:
//	Stack(int n=4)//在这里还是要自己实现一个的，不然会出跟上面一样的问题,我们来定义一个全缺省的
//	{
//		_a = (int*)malloc(n * sizeof(int));
//		if (_a == nullptr)
//		{
//			perror("malloc fail!");
//			exit(1);
//		}
//		_top = 0;
//		_capacity = n;
//	}
//private:
// //内置类型
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的构造函数调用了Stack的构造函数，完成了两个成员的初始化
//private:
//	//自定义类型
//	Stack _pushst;
//	Stack _popst;
//	//内置类型，但很奇怪，混在这里它却能处理，这里大家可以自己去试试
//	//int size = 0;
//};
//
//int main()
//{
//	MyQueue q;
//	return 0;
//}



///////////////////////////////////////////////////////////////////////////////////////////
//析构函数:
//#include<iostream>
//using namespace std;
//class Stack 
//{
//public:
//	Stack(int n=4)//在这里还是要自己实现一个的，不然会出跟上面一样的问题,我们来定义一个全缺省的
//	{
//		_a = (int*)malloc(n * sizeof(int));
//		if (_a == nullptr)
//		{
//			perror("malloc fail!");
//			exit(1);
//		}
//		_top = 0;
//		_capacity = n;
//	}
//	//析构函数(跟构造函数写法类似，前面加个~)
//	//在这里也需要自己定义,不然他也不处理内置类型,会造成内存泄漏
//	~Stack()
//	{
//		if (_a)
//		{
//			free(_a);
//			_a = nullptr;
//		}
//		_top = 0;
//		_capacity = 0;
//	}
//private:
//	//内置类型
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的构造函数调用了Stack的构造函数，完成了两个成员的初始化
//	
//	//编译器默认生成MyQueue的析构函数调用了Stack的析构函数，释放的Stack内部的资源
//	//显示写析构，也会自动调用Stack的析构
//	/*~MyQueue()
//	   {}*/
//
//private:
//	//自定义类型
//	Stack _pushst;
//	Stack _popst;
//	//内置类型，但很奇怪，混在这里它却能处理，这里大家可以自己去试试
//	//int size = 0;
//};
//
//int main()
//{
//	Stack s;
//
//	MyQueue q;
//
//	//析构不用显示写出来，对象生命周期结束时自动调用
//	//后定义的先析构，所以这里先析构q,再析构s.可以调试观察
//	return 0;
//}



//对比一下用C++和C实现的Stack解决之前括号匹配问题isValid，
//我们发现有了构造函数和析构函数确实方便了很多，不会再忘记调用Init和Destory函数了，也方便了不少。

////以前用C语言实现的
//bool isValid(char* s) {
//    ST st;
//    STInit(&st);
//    char* pi = s;
//    while (*pi != '\0')
//    {
//        if (*pi == '(' || *pi == '[' || *pi == '{')
//        {
//            STPush(&st, *pi);
//        }
//        else {
//            //右括号取栈顶元素进行匹配
//            //栈不为空才能取
//            if (STEmpty(&st))
//            {
//                STDestory(&st);
//                return false;
//            }
//            char top = STTop(&st);
//            if ((top == '(' && *pi != ')')
//                || (top == '[' && *pi != ']')
//                || (top == '{' && *pi != '}'))
//            {
//                STDestory(&st);
//                return false;
//            }
//            //本次匹配就出栈
//            STPop(&st);
//        }
//        pi++;
//    }
//    //为空有效，非空无效
//    bool ret = STEmpty(&st) ? true : false;
//    STDestory(&st);
//    return ret;
//}


////用最新加了构造和析构的C++版本Stack实现
//bool isValid(char* s) {
//    Stack st;
//    char* pi = s;
//
//    while (*pi != '\0')
//    {
//        if (*pi == '(' || *pi == '[' || *pi == '{')
//        {
//            st.Push(&st, *pi);
//        }
//        else {
//            //右括号取栈顶元素进行匹配
//            //栈不为空才能取
//            if (st.Empty(&st))
//            {
//                return false;
//            }
//            char top = st.Top(&st);
//            if ((top == '(' && *pi != ')')
//                || (top == '[' && *pi != ']')
//                || (top == '{' && *pi != '}'))
//            {
//                return false;
//            }
//            //本次匹配就出栈
//            st.Pop(&st);
//        }
//        pi++;
//    }
//    //栈为空，返回真，说明数量都匹配 左括号多，右括号少匹配问题
//    return st.Empty();
//}