#define _CRT_SECURE_NO_WARNINGS 1
#include<map>
#include<iostream>
using namespace std;

void test_map1()
{
	map<string, string> dict;
	// C++98
	pair<string, string> kv1("sort", "排序");
	dict.insert(kv1);
	dict.insert(pair<string, string>("left", "左边"));//匿名对象
	dict.insert(make_pair("left", "左边"));

	// C++11
	dict.insert({ "right","右边" });//这是多参数的隐式类型转换
	// initial_list
	//dict.insert({kv1, pair<string, string>("left", "左边")});
	dict.insert({ {"string", "字符串"}, {"map", "地图,映射"} });

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//pair是一个结构，直接解引用不行
		// cout << *it << endl;
		
		// 下面这两种都可以，推荐第二种
		//cout << (*it).first <<":"<< (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		//cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		++it;
	}
	cout << endl;

	// 传引用
	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	// 结构化绑定 C++17
	//auto [x, y] = kv1;
	//for (auto [k, v] : dict)//不推荐
	for (const auto& [k,v] : dict)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;

	auto pos = dict.find("left");
	if (pos != dict.end())
	{
		dict.erase(pos);
	}

	for (const auto& [k, v] : dict)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;
}

void test_map2()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	map<string, int> countMap;
	//for (auto& e : arr)
	//{
	//	auto it = countMap.find(e);
	//	if (it != countMap.end())
	//	{
	//		it->second++;
	//	}
	//	else
	//	{
	//		countMap.insert({ e,1 });
	//	}
	//}

	//直接用这个
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (const auto& [k, v] : countMap)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;

	map<string, string> dict;
	// 插入
	dict["sort"];
	// 插入+修改
	dict["left"] = "左边";
	// 修改
	dict["sort"] = "排序";
	// 查找
	cout << dict["sort"] << endl;

	// 纯粹的查找+修改
	// at
	dict.at("left") = "xxxxx";
	// key不存在，会抛异常
	// dict.at("insert") = "xxxxx";
}

void test_multimap()
{
	//multimap没有[]
	multimap<string, string> dict;
	dict.insert({ "right", "右边" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边xx" });
	dict.insert({ "right", "右边" });


	for (const auto& [k, v] : dict)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;
}
int main()
{
	//test_map1();
	//test_map2();
	test_multimap();
}