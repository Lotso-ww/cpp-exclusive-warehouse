#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
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

#include"queue.h"

int main()
{
	//Lotso::queue<int> q;//默认是用的deque
	//Lotso::queue<int, vector<int>> q; // ֧这个不用最好
	Lotso::queue<int, list<int>> q;//链表实现

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	return 0;
}