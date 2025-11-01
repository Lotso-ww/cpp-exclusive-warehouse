#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <string>
using namespace std;

void test_map1() {
	// 1. 默认构造（空 map）
	map<string, string> dict1;

	// 2. 初始化列表构造（C++11+，推荐）
	map<string, string> dict2 = { {"sort", "排序"}, {"left", "左边"}, {"right", "右边"} };

	// 3. 迭代器区间构造（从其他 map 或容器拷贝）
	map<string, string> dict3(dict2.begin(), dict2.end());

	// 4. 拷贝构造
	map<string, string> dict4(dict3);

	cout << "dict2 初始化结果：" << endl;
	for (const auto& [k, v] : dict2) {  // C++17 结构化绑定（简洁遍历）
		cout << k << ":" << v << endl;
	}
}
void test_map2() {

	map<string, string> dict = { {"sort", "排序"}, {"left", "左边"}, {"right", "右边"},{"string", "字符串"},{"map", "地图,映射"} };

	// 方式1：普通迭代器遍历（支持修改 Value）
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end()) {
		// 关键：迭代器解引用得到 pair<const Key, T>，需通过 -> 访问 first/second
		// (*it).first 等价于 it->first（推荐后者，更简洁）
		cout << it->first << ":" << it->second << endl;
		// 尝试修改 Key（编译报错！Key 是 const 的）
		// it->first = "new_left"; 
		// 修改 Value（合法）
		if (it->first == "left") {
			it->second = "左边（修改后）";
		}
		++it;
	}
	cout << endl;

	// 方式2：范围 for 遍历（传引用避免拷贝，const 保护不被修改）
	for (const auto& e : dict) {
		// e 是 pair<const string, string> 类型
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	// 方式3：C++17 结构化绑定（最简洁，直接拆分 Key 和 Value）
	for (const auto& [k, v] : dict) {
		cout << k << ":" << v << endl;
	}
}
void test_map()
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
	for (const auto& [k, v] : dict)
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
void test_map3()
{
	map<string, string> dict;
	//方式1：插入 pair 对象（C++98 风格，较繁琐)
	pair<string, string> kv1("sort", "排序");
	dict.insert(kv1);

	// 方式2：插入匿名 pair 对象（略简洁）
	dict.insert(pair<string, string>("left", "左边"));

	// 方式3：用 make_pair 生成 pair（推荐，无需显式写类型）
	dict.insert(make_pair("right", "右边"));

	// 方法4：初始化列表插入（C++11+，最简洁),用多参数的隐式类型转换
	dict.insert({ "move","移动" });
	// 批量插入多个键值对
	dict.insert({ {"map", "映射"}, {"erase", "删除"} });

	// 插入重复 Key（返回 false，不修改原数据）
	auto ret = dict.insert({ "left", "左边（重复插入）" });
	if (!ret.second) {
		cout << "Key 'left' 已存在，当前值：" << ret.first->second << endl;
	}

	// 输出结果
	for (const auto& [k, v] : dict) {
		cout << k << ":" << v << endl;
	}
}

void test_map4() 
{
	map<string, string> dict = {
		{"sort", "排序"}, {"left", "左边"}, {"right", "右边"}
	};

	// 1. 查找 Key 'left'
	auto pos = dict.find("left");
	if (pos != dict.end()) {
		cout << "找到 Key 'left'，值：" << pos->second << endl;
		// 2. 删除迭代器指向的节点（安全删除）
		dict.erase(pos);
		cout << "删除 Key 'left' 后：" << endl;
		for (const auto& [k, v] : dict) {
			cout << k << ":" << v << endl;
		}
	}

	// 3. 直接删除指定 Key（返回删除的个数，map 中 0 或 1）
	size_t del_cnt = dict.erase("right");
	cout << "删除 Key 'right'，影响个数：" << del_cnt << endl;

	// 4. 删除迭代器区间（删除所有元素）
	dict.erase(dict.begin(), dict.end());
	cout << "删除所有元素后，map 大小：" << dict.size() << endl;
}
void test_map5()
{
	map<string, int> countMap;  // 统计水果出现次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "香蕉" };

	// 这样很麻烦
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
	
	// 场景1：插入 + 修改（统计次数，最常用）
	for (const auto& fruit : arr) 
	{
		// 若 fruit 不存在：插入 {fruit, 0}，返回 0 的引用，++ 后变为 1；
		// 若 fruit 已存在：返回现有 Value 的引用，++ 后次数增加；
			countMap[fruit]++;
	}
	cout << "水果统计结果：" << endl;
		
	for (const auto& [fruit, cnt] : countMap) 
	{
			cout << fruit << ":" << cnt << endl;
	}
	cout << endl;

	// 场景2：纯粹插入（Key 不存在时，插入默认 Value）
	map<string, string> dict;
	dict["insert"];  // 插入 { "insert", "" }（string 默认空）
	cout << "插入 'insert' 后，值：" << dict["insert"] << endl;

	// 场景3：插入 + 修改（Key 不存在时插入，存在时修改）
	dict["left"] = "左边";  // 插入 { "left", "左边" }
	dict["left"] = "左边（修改后）";  // 修改 Value 为 "左边（修改后）"
	cout << "修改 'left' 后，值：" << dict["left"] << endl;

	// 场景4：纯粹查找（Key 存在时，返回 Value 引用）
	cout << "查找 'left'，值：" << dict["left"] << endl;

	// 对比：at() 接口（仅支持查找+修改，Key 不存在时抛异常，不插入）
	dict.at("left") = "左边（at 修改）";  // 合法，修改 Value
	// dict.at("nonexist") = "不存在";  // 抛出异常：out_of_range

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
	//test_map3();
	//test_map4();
	//test_map5();
	test_multimap();
}

