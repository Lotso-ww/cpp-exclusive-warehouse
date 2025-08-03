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
//}/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////拷贝构造函数
//#include<iostream>
//using namespace std;
//
//class Date 
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//拷贝构造函数
//	//Date(Date d),这种写法不行，我们可以拿个func的例子看看，会发现传值要先调用拷贝函数，下面有提到
//	// 但是拷贝函数本身再一直调用拷贝函数本身的话，会出现无限递归的问题,所以要使用传引用传参
//	//加个const可以让下面传实参的选择更多，避免出现权限扩大等问题
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//其实这里用默认生成的也会处理内置类型，进行浅拷贝，在这里是没问题的。这也是和构造和析构的一个区别
//
//	//用指针实现拷贝，但是这里并不算拷贝函数
//	/*Date(Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}*/
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
////自定义类型传值传参和传值返回都会调用拷贝构造完成
////传值传参会调用拷贝函数
//void func(Date d)
//{
//
//}
//
////传值返回也会调用拷贝函数，但是传引用就不会(后续会用Stack继续来讲)，这里就不过多介绍了
////Date& func2()
//Date func2()
//{
//	Date d(2025,7,31);
//	return d;
//}
//
//
//int main()
//{
//	Date d1(2025,8,1); 
//	Date d2(d1);
//
//	//func(d1);//我们调试发现，他会先去调用Date里面的拷贝函数再去func
//
//	//传值返回可以，传引用返回不行，这里不细讲
//	Date ret = func2();
//	//Date ret = (func2());,这样写也是可以的
//
//	//由这个我们还可以看出，那其实之前的拷贝也可以写出这样
//	//Date d2 = d1;
//
//
//	// 这里可以完成拷⻉，但是不是拷⻉构造，只是⼀个普通的构造
//	//Date d2(&d1);
//
//	d1.Print();
//	d2.Print();
//
//	return 0;
//}



#include<iostream>
using namespace std;
typedef int STDataType;

class Stack 
{
public:
	Stack(int n=4)
	{
		_a = (STDataType*)malloc(n * sizeof(STDataType));
		if (nullptr==_a)
		{
			perror("malloc fail!");
			exit(1);
		}
		_top = 0;
		_capacity = n;
	}
	//这样写是错的，因为这里的数组如果像这样写仅仅是浅拷贝，后续析构函数释放空间会释放同一块空间
	// 画图理解，调试也会报错
	/*Stack(const Stack& s)
	{
		_a = s._a;
		_capacity = s._capacity;
		_top = s._top;
	}*/

	//所以我们需要这样写
	Stack(const Stack& s)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * s._capacity);//申请一块同样大小的空间
		if (_a == NULL)
		{
			perror("ralloc fail!");
			return;
		}
		//把值再拷贝过去
		memcpy(_a, s._a, s._top * sizeof(STDataType));
		//这两个直接这样就可以了
		_capacity = s._capacity;
		_top = s._top;
	}
	//补充一点，这里也不能不写，用编译器自动生成的默认的拷贝构造函数，因为这个函数虽然会处理内置类型
	//但是只会是浅拷贝/值拷贝,像Stack这样需要有深拷贝的就不行了
	//可以这样说，如果一个类必须显示实现析构函数(需要释放资源),那么他就一点也要显示写拷贝构造函数

	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				exit(1);
			}
			_a = tmp;
			_capacity = newcapacity;
		}
		_a[_top++] = x;
	}

	~Stack()
	{
		cout<<"~Stack()"<<'\n';
			free(_a);
			_a = nullptr;

		_top = 0;
		_capacity = 0;
	}
private:
	//内置类型
	STDataType* _a;
	size_t _top;
	size_t _capacity;
};
//
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//
//	Stack s2(s1);
//
//	return 0;
//}
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的构造函数调用了Stack的构造函数，完成了两个成员的初始化
//	//编译器默认生成MyQueue的拷贝构造函数调用了Stack的拷贝构造函数，完成了拷贝
//	//编译器默认生成MyQueue的析构函数调用了Stack的析构函数，释放的Stack内部的资源
//private:
//	//自定义类型
//	Stack _pushst;
//	Stack _popst;
//	//内置类型，但很奇怪，混在这里它却能处理，这里大家可以自己去试试
//	//int size = 0;
//};

//借助上面的类，给大家对比看看传引用返回在这里的弊端,同时也是在说第6个特点
int& func1()
{
	int x = 1;
	return x;
}

//自定义类型传值返回是会调用拷贝函数的，但是传引用返回不会，画图分析。
//它没调拷贝函数的话，在后面函数栈帧销毁，st析构掉了之后。你再通过别名来找，就出问题了,画图
//Stack func2()
Stack& func2()
{
	Stack st;
	return st;
}

int main()
{
	int ret1 = func1();
	cout << ret1 << '\n';//可能是1也可能是随机值，我们之前判断过

	//但是这个栈就很明显了，我们调试看看
	Stack ret2 = func2();//这里其实也是拷贝

	return 0;
}

////再来看看默认生成的拷贝构造函数对自定义类型的处理
//#include<iostream>
//using namespace std;
//typedef int STDataType;
//
//class Stack
//{
//public:
//	Stack(int n = 4)
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
//	Stack(const Stack& s)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * s._capacity);//申请一块同样大小的空间
//		if (_a == nullptr)
//		{
//			perror("malloc fail!");
//			exit(1);
//		}
//		//把值再拷贝过去
//		memcpy(_a, s._a, s._top * sizeof(STDataType));
//		//这两个直接这样就可以了
//		_capacity = s._capacity;
//		_top = s._top;
//	}
//	//补充一点，这里也不能不写，用编译器自动生成的默认的拷贝构造函数，因为这个函数虽然会处理内置类型
//	//但是只会是浅拷贝/值拷贝,像Stack这样需要有深拷贝的就不行了
//	//可以这样说，如果一个类必须显示实现析构函数(需要释放资源),那么他就一点也要显示写拷贝构造函数
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity * sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				exit(1);
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << '\n';
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
//	STDataType* _a;
//	int _top;
//	int _capacity;
//};
//
//class MyQueue
//{
//public:
//	//编译器默认生成MyQueue的构造函数调用了Stack的构造函数，完成了两个成员的初始化
//	//编译器默认生成MyQueue的拷贝构造函数调用了Stack的拷贝构造函数，完成了拷贝
//	//编译器默认生成MyQueue的析构函数调用了Stack的析构函数，释放的Stack内部的资源
//private:
//	//自定义类型
//	Stack _pushst;
//	Stack _popst;
//	//内置类型，但很奇怪，混在这里它却能处理，这里大家可以自己去试试
//	//int size = 0;
//};
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	// Stack如果不显示实现拷⻉构造，用自动生成的拷⻉构造完成浅拷⻉
//	// 会导致st1和st2里面的_a指针指向同⼀块资源，析构时会析构两次，程序崩溃
//	Stack st2 = st1;
//	MyQueue mq1;
//	// MyQueue自动生成的拷⻉构造，会自动调用Stack拷⻉构造完成pushst/popst的拷⻉。
//	// 只要Stack拷⻉构造自己实现了深拷⻉，这里就没问题
//	MyQueue mq2 = mq1;
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////
//赋值运算符重载

////运算符重载
//#include<iostream>
//using namespace std;
//
//class Date 
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//其实这里用默认生成的也会处理内置类型，进行浅拷贝，在这里是没问题的。
//	//这也是和构造和析构的一个区别，构造和析构不会处理内置类型
//	
//	int Getyear()
//	{
//		return _year;
//	}
//
//	//d1==d2,传d2就行，d1有this指针，但是在实参和形参不能直接写出来，函数体内可以
//	bool operator==(const Date& d2)
//	{
//		return this->_year == d2._year
//			&& this->_month == d2._month
//			&& this->_day == d2._day;
//	}
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
//// 重载为全局的面临对象访问私有成员变量的问题
//// 有几种方法可以解决：
//// 1、成员放公有--这个最容易，但是不那么好
//// 2、Date提供getxxx函数--上面有在类里面展现出来可以自己看看，然后在底下的函数体内需要修改一下
//// 3、友元函数--这里先不讲这个
//// 4、重载为成员函数--这个我也在类里重载为成员函数了，但是有些需要注意的地方,我最后选取这种
////bool operator==(const Date& d1, const Date& d2)
////{
////	return d1._year == d2._year//如果用了Get**就是这样写的:d1.Getyear() == d2.Getyear()
////		&& d1._month == d2._month
////		&& d1._day == d2._day;
////}
//
//int main()
//{
//	Date d1(2025,8,1);
//	Date d2(2025,10,1);
//	Date d3(2025, 8, 1);
//
//	//我们在这里就需要实现运算符重载函数
//	d1 == d2;
//
//	//运算符重载函数可以显示调用
//	//operator==(d1, d2);
//	
//	//如果成成员函数了，显示调用是这样的
//	//d1.operator==(d2);//只要传一个参d2就行，d1通过this指针，但是不能在实参和形参显示写出来的
//	//再加上运算符重载要求参数个数和运算符作用对象一样多，所以只能传一个
//	//可以具体去看看上面类里面怎么实现的
//
//	cout << (d1 == d2) << '\n';//这里需要打括号，优先级的问题,0
//	cout << (d1 == d3) << '\n';//1
//
//	return 0;
//}


//// .*符号普及,了解即可，刚好提到了这个运算符不能重载
//#include<iostream>
//using namespace std;
//
//void func1()
//{
//	cout << "void func()" << endl;
//}
//
//class A
//{
//public:
//	void func2()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//int main()
//{
//	// 普通函数指针
//	void(*pf1)() = func1;
//	(*pf1)();
//
//	// A类型成员函数的指针
//	void(A::*pf2)() = &A::func2;
//	A aa;
//	(aa.*pf2)();//这里就是使用的.*
//
//	return 0;
//}



////赋值运算符重载
//#include<iostream>
//using namespace std;
//
//class Date 
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//传引用返回可以减少拷贝(之前提到过在这里传值返回是自动调用拷贝函数的)
//	//这里能使用是传引用返回是因为第一个参数用this来的，函数栈帧销毁也不会找不到
//	//函数要返回类型是为例更好处理连续赋值的情况(d3=d1=d2)，用void不好处理
//	Date& operator=(const Date& d)//const和传引用传参的作用就不再多说了
//	{
//		//自己等于自己就可以不用赋值了
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		//比如：d1=d2表达式的返回对象应该为d1,也就是*this
//		return *this;
//	}
//	//赋值运算符重载，但其实在Date类型里面不写也没影响，跟拷贝构造函数处理内置类型原理一样
//	//思考联想方法也一样，不再说了
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
//	Date d2(2025, 8, 1);
//	d1 = d2;
//
//	Date d3;
//	d3 = d1 = d2;//从右往左
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	// 需要注意这里是拷⻉构造，不是赋值重载
//	// 要牢牢记住赋值重载完成两个已经存在的对象直接的拷⻉赋值
//	// 而拷⻉构造用于一个对象拷⻉初始化给另⼀个要创建的对象
//	Date d4 = d1;//因为拷贝构造如果写出这样就有点容易混
//	//Date d4(d1);//写成这样的时候不太容易混淆
//
//	return 0;
//}



//#include<iostream>
//using namespace std;
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	// Stack st2(st1);
//	/*Stack(const Stack& s)
//	{
//		_a = s._a;
//		_capacity = s._capacity;
//		_top = s._top;
//	}*/
//
//	Stack(const Stack& s)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * s._capacity);
//		if (_a == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//
//		memcpy(_a, s._a, s._top * sizeof(STDataType));
//
//		_capacity = s._capacity;
//		_top = s._top;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int& func2()
//{
//	int x = 1;
//	return x;
//}
//
//Stack& Func3()
//{
//	Stack st;
//	return st;
//}
//
//// 10:30
//int main()
//{
//	int ret1 = func2();
//	cout << ret1 << endl;
//
//	Stack ret2 = Func3();
//	// Stack ret2(Func3());
//
//	return 0;
//}