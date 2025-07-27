

//#include<stdio.h>
//
//int main()
//{
//	printf("Hello World\n");
//	return 0;
//}


//#include<iostream>//不需要带.h
//using namespace std;
//
//int main()
//{
//	cout << "Hello World" << '\n';
//	cout << "Hello World" << endl;
//
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//
//int rand = 10;
//
//int main()
//{
//	printf("%d", rand);
//	//这种不行，因为rand是stdlib中的的一个库函数，重定义了
//
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//
//namespace Lotso 
//{
//	//命名空间可以定义变量/函数/类型
//	int rand = 10;
//
//	int Sub(int x, int y)
//	{
//		return x - y;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int data;
//	};
//}//这里是没有;的
//
//int main()
//{
//	//默认访问的是全局的rand函数指针
//	printf("%p\n", rand);
//
//	//编译器语法查找确认规则是默认先局部查找->全局查找->没有找到就报未声明的标识符这个错误
//	//::域作用限定符，这里指定作用域，就直接按这个域去找->没有找到就报未声明的标识符这个错误
//	printf("%d\n", Lotso::rand);
//
//	//这底下的就不详细讲述了，很好理解
//	printf("%p\n", Lotso::Sub);
//	printf("%d\n", Lotso::Sub(5,3));//2
//
//	struct Lotso::Node node;
//
//	return 0;
//}


////命名空间的嵌套使用
//#include<stdio.h>
//#include<stdlib.h>
//
//namespace Lotso
//{
//	namespace A
//	{
//		int rand = 10;
//		int Sub(int x, int y)
//		{
//			return x - y;
//		}
//	}
//
//
//	namespace B
//	{
//		int rand = 20;
//		int Sub(int x, int y)
//		{
//			return x - y;
//		}
//	}
//}
//
//int main()
//{
//	printf("%d\n", Lotso::A::rand);//10
//	printf("%d\n", Lotso::B::rand);//20
//
//	printf("%d\n", Lotso::A::Sub(5,3));//2
//	printf("%d\n", Lotso::B::Sub(6,2));//4
//
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
////命名空间中成员全部展开
//using namespace std;
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;//输入
//	cout << a << " " << b << '\n';//输出
//
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
////命名空间中成员部分展开
//using std::cout;
//
//int main()
//{
//	int a, b;
//	std::cin >> a >> b;//输入
//	cout << a << " " << b << '\n';//输出
//
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;//输入
//
//	cout << a << " " << b << '\n';//输出
//	cout << a << " " << b << endl;//end line
//
//	return 0;
//}
