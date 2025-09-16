#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//void main()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//
//	*char2 += 1;
//	//(*(char*)pChar3) += 1;
//
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//
//	const int i = 10;
//	int j = 1;
//	cout << &i << endl;
//	cout << &j << endl;
//	cout << (void*)pChar3 << endl;
//}
//

//#include<iostream>
//using namespace std;
//int main()
//{
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 50);
//	cout << p2 << endl;
//	cout << p3 << endl;
//
//	// 这里需要free(p2)吗？
//	free(p3);
//
//	int* p5 = new int;	    // 单个对象
//	int* p6 = new int[10];  // 数组
//
//	int* p7 = new int(5);	    // 单个对象
//	int* p8 = new int[10]{1,2,3,10};  // 数组
//
//	delete p5;
//	delete[] p6;
//	delete p7;
//	delete[] p8;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//
//	int* p5 = new int;	    // 单个对象
//	int* p6 = new int[10];  // 数组
//
//	int* p7 = new int(5);	    // 单个对象
//	int* p8 = new int[10] {1, 2, 3, 10};  // 数组
//
//	delete p5;
//	delete[] p6;
//	delete p7;
//	delete[] p8;
//}
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//struct ListNode
//{
//	ListNode* _next;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _val(val)
//	{
//	}
//};
//
//int main()
//{
//	// 只开空间，不调用构造初始化，不太好使
//	A* p1 = (A*)malloc(sizeof(A));
//
//	A* p2 = new A;
//	A* p3 = new A(10);
//
//	delete p2;
//	delete p3;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
////如果不抛异常的话这个程序退出码不为0，异常退出，
////这也是跟malloc不一样的一点，new申请失败会抛异常
//void func()
//{
//	int i = 1;
//	int* ptr = nullptr;
//	do {
//		if (i == 493)//为了方便调试
//		{
//			int x = 0;
//		}
//
//		ptr = new int[1024 * 1024];//throw
//		cout << i++ << ":" << ptr << '\n';
//	} while (ptr);
//	cout << i++ << ":" << ptr << '\n';
//}
//int main()
//{
//	try 
//	{
//		func();//可以直接跳跃函数到异常
//	}
//	catch(const exception& e)
//	{
//		cout << e.what() << '\n';//打印错误信息
//	}
//	return 0;
//}


//operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间
// 申请空间失败，尝试执行空间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常。

//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//		return (p);
//}
//
///*
//operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//free的实现
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)



//#include<iostream>
//using namespace std;
//class A 
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A();" << this << '\n';
//	}
//	~A()
//	{
//		cout << "~A();" << this << '\n';
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//A* p2 = (A*)operator new(sizeof(A));//可以显示调用
//
//	//可以看看反汇编
//	A* p1 = new A(1);
//	delete p1;
//
//	A* p2 = new A[10];//看反汇编为啥会是44，而不是40;
//	//但是把析构注释掉就又是40了
//	delete[] p2;
//
//	return 0;
//}


//在内存池里用的多
#include<iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A();" << this << '\n';
	}
	~A()
	{
		cout << "~A();" << this << '\n';
	}
private:
	int _a;
};

//定位new表达式的使用
int main()
{
	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	A* p1 = (A*)operator new(sizeof(A));
	//显示调用构造函数
	new(p1)A(1);//有参数就需要传，这里其实可以传也可以不传，看你实现的构造函数

	p1->~A();//析构可以直接这样用，构造不行;
	operator delete(p1);

	A* p2 = (A*)operator new(sizeof(A));
	new(p2)A(10);
	p2->~A();
	operator delete(p2);
}

