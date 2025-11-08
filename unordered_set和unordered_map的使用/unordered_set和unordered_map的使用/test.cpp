#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
using namespace std;


void test_unset1()
{
	const size_t N = 1000000;
	unordered_set<int> us;
	set<int> s;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	cout << "没有重复，有序:" << endl;
	for (size_t i = 0; i < N; ++i)
	{
		//v.push_back(rand()); // N比较大时，重复值比较多
		//v.push_back(rand() + i); // 重复值相对少
		v.push_back(i); // 没有重复，有序
	}

	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();
	cout << "set insert:" << end1 - begin1 << endl;
	size_t begin2 = clock();
	us.reserve(N);
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();
	cout << "unordered_set insert:" << end2 - begin2 << endl;

	int m1 = 0;
	size_t begin3 = clock();
	for (auto e : v)
	{
		auto ret = s.find(e);
		if (ret != s.end())
		{
			++m1;
		}
	}

	size_t end3 = clock();
	cout << "set find:" << end3 - begin3 << "->" << m1 << endl;
	int m2 = 0;
	size_t begin4 = clock();
	for (auto e : v)
	{
		auto ret = us.find(e);
		if (ret != us.end())
		{
			++m2;
		}
	}
	size_t end4 = clock();
	cout << "unorered_set find:" << end4 - begin4 << "->" << m2 << endl;
	cout << "插入数据个数：" << s.size() << endl;
	cout << "插入数据个数：" << us.size() << endl << endl;

	size_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	size_t end5 = clock();
	cout << "set erase:" << end5 - begin5 << endl;

	size_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	size_t end6 = clock();
	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
}

void test_unset2()
{
		//只去重，遍历无序
		unordered_set<int> s;
		s.insert(4);
		s.insert(1);
		s.insert(2);
		s.insert(4);
		s.insert(5);

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;

	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	unordered_map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& [k, v] : countMap)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;
}
int main()
{
	test_unset1();
	//test_unset2();

	return 0;
}


//#include <unordered_set>
//using namespace std;
//
//int main()
//{
//	unordered_set<int> us;
//
//	// 插入（返回pair<iterator, bool>，bool标记是否插入成功）
//	us.insert(10);
//	us.insert({ 20, 30, 40 });
//
//	// 查找（返回迭代器，未找到返回end()）
//	auto it = us.find(20);
//	if (it != us.end()) 
//	{ 
//		// 找到处理  
//	}
//
//	// 删除（按key删除，返回删除个数）
//	us.erase(30);
//	// 其他常用接口
//	us.size();       // 元素个数
//	us.empty();      // 是否为空
//	us.clear();      // 清空容器
//}


//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	unordered_map<string, int> um;
//
//	// 插入
//	um.insert({ "sort", 1 });
//	um.insert(make_pair("left", 2));
//
//	// []运算符（插入+访问/修改，最常用）
//	um["right"] = 3;  // 插入
//	um["left"] = 22;  // 修改
//
//	// 查找
//	auto it = um.find("sort");
//	if (it != um.end()) { cout << it->first << ":" << it->second << endl; }
//
//	// 删除
//	um.erase("right");
//}
