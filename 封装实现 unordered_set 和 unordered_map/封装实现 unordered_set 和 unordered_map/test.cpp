#define _CRT_SECURE_NO_WARNINGS 1
#include"HashTable.h"

#include"unordered_set.h"
#include"unordered_map.h"

void Print(const Lotso::unordered_set<int>& s)
{
	Lotso::unordered_set<int>::const_iterator it = s.begin();
	while (it != s.end())
	{
		// *it = 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	Lotso::unordered_set<int> us;
	us.insert(3);
	us.insert(1000);
	us.insert(2);
	us.insert(102);
	us.insert(2111);
	us.insert(22);

	Lotso::unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	Print(us);

	Lotso::unordered_map<string, string> dict;
	dict.insert({ "string", "字符串" });
	dict.insert({ "string", "字符串" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });
	// 修改
	dict["left"] = "左边,剩余";

	// 插入
	dict["insert"];

	// 插入+修改
	dict["map"] = "地图";

	for (auto& [k, v] : dict)
	{
		//k += 'x';
		//v += 'x';

		cout << k << ":" << v << endl;
	}

	return 0;
}