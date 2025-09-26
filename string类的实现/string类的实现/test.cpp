#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

namespace Lotso
{
	void test_string1()
	{
		string s1;
		cout << s1.c_str() << endl;

		string s2("Hello Lotso");
		cout << s2.c_str() << endl;
		s2[0] = 'h';

		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i]++;
		}
		cout << s2.c_str() << endl;

		string s3 = "hello world";//隐式类型转换，构造+拷贝构造->优化为构造
		string s4("hello world");

		string s5;
		s5.resize(100, '*');
		cout << s5.c_str() << endl;

		s5.resize(10);
		cout << s5.c_str() << endl;

		s5.resize(20, '#');
		cout << s5.c_str() << endl;

	}

	void test_string2()
	{
		string s2("Hello Lotso");
		cout << s2.c_str() << endl;
		s2[0] = 'h';

		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i]++;
		}
		cout << s2.c_str() << endl;

		string s4("hello world");
		const string s5("hello Lotso");
		for (size_t i = 0; i < s5.size(); i++)
		{
			//s5[i]++;不可以写，但可以读
			cout << s5[i] << "-";
		}
		cout << endl;

		for (auto ch : s4)
		{
			cout << ch << " ";
		}
		cout << endl;

		string::iterator it4 = s4.begin();
		while (it4 != s4.end())
		{
			*it4 += 1;
			cout << *it4 << " ";
			++it4;
		}
		cout << endl;

		for (auto ch : s5)
		{
			cout << ch << " ";
		}
		cout << endl;

		string::const_iterator it5 = s5.begin();
		while (it5 != s5.end())
		{
			//*it5+=1;//这个不行
			cout << *it5 << " ";
			++it5;
		}
		cout << endl;

		//string s1;
		//cout << s1.c_str() << endl;

		//string s2("Hello Lotso");
		//cout << s2.c_str() << endl;
		//s2.push_back('x');
		//cout << s2.c_str() << endl;

		//string s3("hello");
		//s3.append("********************");
		//cout << s3.c_str() << endl;

		//string s4("hello");
		//s4 += '*';
		//s4 += "hello Lotso";
		//cout << s4.c_str() << endl;

	}

	void test_string3()
	{
		string s1;
		cout << s1.c_str() << endl;

		string s2("Hello Lotso");
		cout << s2.c_str() << endl;
		s2.push_back('x');
		cout << s2.c_str() << endl;

		string s3("hello");
		s3.append("********************");
		cout << s3.c_str() << endl;

		string s4("hello");
		s4 += '*';
		s4 += "hello Lotso";
		cout << s4.c_str() << endl;

		string s5("hello world");
		cout << s5.c_str() << endl;
		s5.insert(5,'x');
		cout << s5.c_str() << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		s1.erase(4, 3);
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;
		s2.erase(4);
		cout << s2.c_str() << endl;

		string s3("hello world");
		cout << s3.c_str() << endl;
		s3.erase(4,100);
		cout << s3.c_str() << endl;

		string s4 = s1.substr(2);
		cout << s4.c_str() << endl;
		string s5 = s1.substr(2, 2);
		cout << s5.c_str() << endl;

	}
	

	void test_string5()
	{
		string s1("hello world");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		s1[0] = 'x';
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("hello worldxxxx");
		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;

		s3 = s3;
		cout << s3.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += '\0';
		s1 += "yyy";
		//如果底层实现不用memcpy这里会出问题
		cout << s1 << endl;
		cout << s1.c_str() << endl;

		string s2(s1);
		cout << s1 << endl;
		cout << s2 << endl;

	}

	void test_string7()
	{
		string url = "https://legacy.cplusplus.com/reference/string/string/rfind/";
		size_t i1 = url.find(':');
		if (i1 != string::npos)
		{
			string protocol = url.substr(0, i1);
			cout << protocol << endl;

			size_t i2 = url.find('/', i1 + 3);
			if (i2 != string::npos)
			{
				string domain = url.substr(i1 + 3, i2 - (i1 + 3));
				cout << domain << endl;

				string uri = url.substr(i2 + 1);
				cout << uri << endl;
			}
		}
	}

	void test_string8()
	{
		Lotso::string s1, s2("xxxxxx");
		cin >> s1 >> s2;
		cout << s1 << endl;
		cout << s2 << endl;

		getline(cin, s1);
		cout << s1 << endl;

		Lotso::string s3("hello world"), s4("xxxxxx");
		s3.swap(s4);

		swap(s3, s4);
	}
};

int main()
{
	try 
	{
		//Lotso::test_string1();
		//Lotso::test_string2();
		//Lotso::test_string3();
		//Lotso::test_string4();
		//Lotso::test_string5();
		//Lotso::test_string6();
		Lotso::test_string7();
		//Lotso::test_string8();


	/*	cout << typeid(Lotso::string::iterator).name() << endl;
		cout << typeid(std::string::iterator).name() << endl;*/
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

//
////补充
//#include <iostream>
//#include <cctype>
//using namespace std;
//
//int main() {
//	// 测试比较运算符
//	Lotso::string s1("apple"), s2("app"), s3("banana");
//	cout << "s1 == s2? " << (s1 == s2 ? "是" : "否") << endl; // 否（长度不同）
//	cout << "s1 < s3? " << (s1 < s3 ? "是" : "否") << endl;   // 是（'a' < 'b'）
//	cout << "s2 <= s1? " << (s2 <= s1 ? "是" : "否") << endl; // 是（s2更短）
//
//	// 测试输入输出
//	Lotso::string s4, s5;
//	cout << "\n请输入两个单词（空格分隔）：";
//	cin >> s4 >> s5;
//	cout << "读取结果：s4=" << s4 << ", s5=" << s5 << endl;
//
//	cin.ignore(); // 忽略输入流中剩余的换行符
//
//	Lotso::string s6;
//	cout << "请输入一行话（含空格）：";
//	getline(cin, s6);
//	cout << "整行读取结果：" << s6 << endl;
//
//	return 0;
//}

