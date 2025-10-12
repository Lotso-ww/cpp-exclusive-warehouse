#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
using namespace std;


void test_list1()
{
	Lotso::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	Lotso::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list2()
{
	Lotso::list<int> lt;
	// 头插2个元素，尾插2个元素
	lt.push_front(-2);
	lt.push_front(-1);
	lt.push_back(1);
	lt.push_back(2);

	cout << "头插+尾插后：";
	for (auto e : lt) cout << e << " ";  // 预期输出：-1 -2 1 2
	cout << endl;

	// 尾删2次，头删2次
	lt.pop_back();
	lt.pop_back();
	lt.pop_front();
	lt.pop_front();

	cout << "删除后size：" << lt.size() << endl;  // 预期输出：0
	cout << endl;
}

// 用const迭代器遍历的打印函数（验证只读特性）
void Print(const Lotso::list<int>& lt)
{
	Lotso::list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		// *it = 10;  // 编译报错：const迭代器不可修改数据
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list3()
{
	// 初始化列表构造
	Lotso::list<int> lt1 = { 1,2,3,4,5,6 };
	// 拷贝构造
	Lotso::list<int> lt2(lt1);

	cout << "lt2（拷贝lt1）：";
	for (auto e : lt2) cout << e << " ";  // 预期输出：1 2 3 4 5 6
	cout << endl;

	// const迭代器遍历
	const Lotso::list<int>& clt = lt1;
	cout << "const迭代器遍历lt1：";
	Print(clt);  // 预期输出：1 2 3 4 5 6
	cout << endl;
}

void test_list4()
{
	Lotso::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	// 任意位置插入：在第2个元素（2）前插入100
	auto it = lt.begin();
	++it;
	lt.insert(it, 100);
	cout << "插入100后：";
	for (auto e : lt) cout << e << " ";  // 预期输出：1 100 2 3 4
	cout << endl;

	// 任意位置删除：删除100
	it = lt.begin();
	++it;
	it = lt.erase(it);
	cout << "删除100后：";
	for (auto e : lt) cout << e << " ";  // 预期输出：1 2 3 4
	cout << endl;

	// 清空容器
	lt.clear();
	cout << "clear后size：" << lt.size() << endl;  // 预期输出：0
}
int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	test_list4();
	return 0;
}