#define _CRT_SECURE_NO_WARNINGS 1
#include"RBTree.h"

#include"Map.h"
#include"Set.h"

template<class T>
void func(const Lotso::set<T>& s)
{
	typename Lotso::set<T>::const_iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_set()
{
	Lotso::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(1);
	s.insert(5);
	s.insert(0);
	s.insert(10);
	s.insert(8);

	Lotso::set<int>::iterator it = s.begin();
	// *it += 10;
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	func(s);
}

void test_map()
{
	Lotso::map<string, string> dict;
	dict.insert({ "sort", "ÅÅÐò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });

	dict["string"] = "×Ö·û´®"; // ²åÈë+ÐÞ¸Ä
	dict["left"] = "×ó±ßxxx";  // ÐÞ¸Ä

	auto it = dict.begin();
	while (it != dict.end())
	{
		// it->first += 'x'; // ²»ÄÜÐÞ¸Ä
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& [k, v] : dict)
	{
		cout << k << ":" << v << endl;
	}
	cout << endl;

	string arr[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
	Lotso::map<string, int> countMap;
	for (auto& e : arr)
	{
		/*auto it = countMap.find(e);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert({ e, 1 });
		}*/
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
	cout << "²âÊÔset:" << endl;
	test_set();
	cout << "------------------" << endl;
	cout << "²âÊÔmap:" << endl;
	test_map();

	return 0;
}

