#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;


//#include"stack.h"
//
//int main()
//{
//	//Lotso::stack<int, vector<int>> st; // 数组实现
//	//Lotso::stack<int, list<int>> st;   // 链表实现
//	Lotso::stack<int> st;//默认是用的deque
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//
//	return 0;
//}

//#include"queue.h"
//
//int main()
//{
//	//Lotso::queue<int> q;//默认是用的deque
//	//Lotso::queue<int, vector<int>> q; // ֧这个不用最好
//	Lotso::queue<int, list<int>> q;//链表实现
//
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//
//	return 0;
//}

//#include<deque>
//
//int main()
//{
//	deque<int> dp;
//	dp.push_back(1);
//	dp.push_back(1);
//	dp.push_back(1);
//	dp.push_front(2);
//	dp.push_front(3);
//	dp.push_front(4);
//
//	dp[0] += 10;
//	for (auto e : dp)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//#include<deque>
//#include<vector>
//void test_op1()
//{
//	srand(time(0));
//	const int N = 1000000;
//
//	deque<int> dq;
//	vector<int> v;
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand() + i;
//		v.push_back(e);
//		dq.push_back(e);
//	}
//
//	int begin1 = clock();
//	sort(v.begin(), v.end());
//	int end1 = clock();
//
//	int begin2 = clock();
//	sort(dq.begin(), dq.end());
//	int end2 = clock();
//
//	printf("vector:%d\n", end1 - begin1);
//	printf("deque:%d\n", end2 - begin2);
//}
////
//void test_op2()
//{
//	srand(time(0));
//	const int N = 1000000;
//
//	deque<int> dq1;
//	deque<int> dq2;
//
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand() + i;
//		dq1.push_back(e);
//		dq2.push_back(e);
//	}
//
//	int begin1 = clock();
//	sort(dq1.begin(), dq1.end());
//	int end1 = clock();
//
//	int begin2 = clock();
//	// 拷贝到vector
//	vector<int> v(dq2.begin(), dq2.end());
//	sort(v.begin(), v.end());
//	dq2.assign(v.begin(), v.end());
//	int end2 = clock();
//
//	printf("deque sort:%d\n", end1 - begin1);
//	printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
//}
//
//int main()
//{
//	test_op1();
//	test_op2();
//
//	return 0;
//}

//********************************************************************************************

//// 仿函数/函数对象   对象可以像函数一样使用
//template <class T> 
//struct Less
//{
//	bool operator() (const T& x, const T& y) const { return x < y; }
//};
//#include<queue>
//int main()
//{
//	//priority_queue<int> pq;//默认是大的优先级高(大堆)
//	priority_queue<int,vector<int>,greater<int>> pq;//调整成默认是小的优先级高(小堆)
//	pq.push(3);
//	pq.push(1);
//	pq.push(2);
//	pq.push(4);
//	pq.push(6);
//
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//
//	return 0;
//}

//**********************************************************************************
