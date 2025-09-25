#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
#include<assert.h>
#include<list>
using namespace std;


//int main()
//{
//	char buff1[] = "abcA";
//	buff1[0]++;
//
//	char buff2[] = "草莓熊Lotso";
//	cout << sizeof(buff2) << endl;//
//
//	buff2[1]++;
//	cout << buff2 << endl;
//
//	buff2[1]++;
//	cout << buff2 << endl;
//
//	buff2[3]++;
//	cout << buff2 << endl;
//
//	buff2[3]++;
//	cout << buff2 << endl;
//
//	return 0;
//}


//void test_string1()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string s4(s2, 0, 5);//从s2下标为0的位置拷贝5个过去构造s4;
//	cout << s4 << endl;
//
//	//pos位置一直拷贝到结尾
//	//1.写一个超过s2长度的
//	string s5(s2, 6, 15);
//	cout << s5 << endl;
//	//2.直接不写，默认使用缺省值npos
//	string s6(s2, 6);
//	cout << s6 << endl;
//
//	string s7("hello world", 6);//取前6个
//	cout << s7 << endl;
//
//	string s8(10, 'x');//用10个x
//	cout << s8 << endl;
//
//	s7 = "xxxxxx";//这样也可以
//	cout << s7 << endl;
//
//}
//
//int main()
//{
//	test_string1();
//}

//class string
//{
//public:
//	char& operator[](size_t pos)//这里的引用体现了引用可以修改返回对象的作用
//	{
//		assert(pos < _size);
//		return _str[pos];
//	}
//private:
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};

////operate[]
//void test_string2()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//
//	s1[0]='x';//可以直接使用下标来访问修改,类似于上面那样
//	cout << s1 << endl;
//	cout << s1[0] << endl;
//
//	//相比于数组这个越界有严格的检查
//	//s1[12];//断言
//	//s1.at(12);//抛异常
//
//	//size和length一样，但更推荐size
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//}
//
//int main()
//{
//	try
//	{
//		test_string2();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//void Print(const string& s)
//{
//	//2.const版本
//	//const string::iterator it1=s.cbegin();
//	//上面这样使用是不对的，const不应该用来修饰整个迭代器，这样都遍历不了了，而是修饰指向的对象
//	string::const_iterator it1 = s.cbegin();//这里使用cbgin和普通的都可以
//	while (it1 != s.cend())
//	{
//		//*it1 = 'x';不能修改
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//
//	//3.reverse版本，加上const一起演示,逆序输出
//	string::const_reverse_iterator it2 = s.rbegin();//这里使用rbegin
//	while (it2 != s.rend())
//	{
//		//*it2 = 'x';//不能修改
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//}
////下标遍历，迭代器
//void test_string3()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//
//	//下标+【】
//	//遍历or修改
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i]++;
//	}
//	cout << s1 << endl;
//
//	//迭代器
//	//行为像指针一样的东西
//	//1.常规使用
//	string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		//(*it1)-;//修改
//		cout << *it1 << " ";
//		++it1;
//	}
//
//	//相对于下标+[]来说，迭代器更加通用，我们这里再来看看在链表中的使用
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	list<int>::iterator lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//	//迭代器的其它使用形式
//	Print(s1);
//}
//int main()
//{
//	test_string3();
//}

////迭代器对于函数的使用，auto
//void test_string4()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//
//	//string::iterator ret1 = find(s1.begin(), s1.end(), 'x');
//	//利用auto进行优化
//	auto ret1 = find(s1.begin(), s1.end(), 'x');
//	if (ret1 != s1.end())
//	{
//		cout << "找到了x" << endl;
//	}
//
//	//list也是一样可以这样使用
//
//	//C++11
//	int i = 0;
//	//通过初始化表达式值类型自动推荐对象类型
//	auto j = i;
//	auto k = 10;
//	auto p1 = &i;
//	//指定一定是指针
//	auto* p2 = &i;
//	cout << p1 << endl;
//	cout << p2 << endl;
//
//	//引用
//	int& r1 = i;
//	//r2不是int&引用，是int
//	auto r2 = r1;
//	//r3是int&引用
//	auto& r3 = r1;
//	cout << &r1 << endl;
//	cout << &r2 << endl;
//	cout << &i << endl;
//	cout << &r3 << endl;
//}
//int main()
//{
//	test_string4();
//}

////范围for
//void test_string5()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//
//	//C++11
//	//范围for,自动取容器数据赋值，自动迭代++，自动判断结束
//	//其实底层还是迭代器，这个看反汇编可以发现
//	
//	//for (auto ch : s1)//其实可以直接使用&,可以修改
//	for(auto& ch:s1)
//	{
//		ch -= 1;
//	}
//
//	for (const auto& ch : s1)
//	{
//		cout << ch << ' ';//只能读不能改
//	}
//	cout << endl;
//
//	//支持迭代器的容器，都可以使用范围for
//	//数组也支持，这里先使用一点C风格
//	int a[10] = { 1,2,3 };
//	for (auto e : a)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//}
//int main()
//{
//	test_string5();
//}



////size,capacity,resize,shrink_to_fit等
//void TestCapacity()
//{
//	string s1;
//	//s1.reserve(200);//确定要插入多少时，可以提前扩容
//	size_t old = s1.capacity();
//	cout << s1.capacity() << endl;
//	for (size_t i = 0; i < 200; i++)
//	{
//		s1.push_back('x');//尾插
//		if (s1.capacity() != old)
//		{
//			cout << s1.capacity() << endl;
//			old = s1.capacity();
//		}
//	}
//	cout << endl << endl;
//}
//
//void test_string6()
//{
//	string s1("hello world");
//	cout << s1.max_size() << endl;//了解下即可
//
//	cout << s1.size() << endl;//不包含结尾的\0
//	cout << s1.capacity() << endl;//存储实际有效字符的个数，不包含结尾的\0
//
//	s1.clear();//空间不会清理
//	cout << s1.size() << endl;//不包含结尾的\0
//	cout << s1.capacity() << endl<<endl;//存储实际有效字符的个数，不包含结尾的\0
//
//	//测试空间增容
//	TestCapacity();
//
//	//reserve最好只用来增容
//	string s2("hello world");
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	s2.reserve(20);//会开的比20大
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//	//s2.reserve(5);//vs上不会缩容
//	s2.shrink_to_fit();//这个可以实现缩容,但是一般不会用，代价比较大
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//
//
//	string s3(s2);
//	cout << s3 << endl;
//
//	// < 当前对象的size时，相当于保留前n个，删除后面的数据
//	s3.resize(5);
//	cout << s3 << endl;
//
//	// > 当前对象的size时，插入数据
//	s3.resize(10, 'x');
//	cout << s3 << endl;
//
//	s3.resize(30, 'y');
//	cout << s3 << endl;
//
//}
//int main()
//{
//	test_string6();
//}


////push_back,append,+=,+;
////appear,=
//void test_string7()
//{
//	string s1("hello world");
//	s1.push_back('&');//尾插一个字符
//	s1.append("hello bit");//尾插一个字符串
//	cout << s1 << endl;
//
//	s1.append(10, 'x');//尾插10个x
//	cout << s1 << endl;
//
//	//还可以配着迭代器使用
//	string s3;
//	string s2(" apple hello!");
//	//我不想要空格和!
//	s3.append(++s2.begin(), --s2.end());
//	cout << s3 << endl;
//
//	//其实我们直接使用+=更加方便
//	string s4("hello world");
//	s4 += ' ';
//	s4 += "hello bit";
//	cout << s4 << endl;
//
//	//为什么不把 + 重载为成员的而是全局，因为这样可以不用一定把成员变量写在左边
//	cout << s4 + "xxxx" << endl;
//	cout << "xxxx" + s4 << endl;
//
//	//assign,没有直接赋值好用
//	s4 = "xxx";
//	cout << s4 << endl;
//	s4.assign("yyy");
//	cout << s4 << endl;
//}
//int main()
//{
//	test_string7();
//}
//
////insert,erase,replace
//void test_string8()
//{
//	string s1("hello world");
//
//	//上面都是尾插，这里实现一个头插
//	s1.insert(0, "xxxxx");
//	cout << s1 << endl;
//
//	//但是头插一个必须这样写
//	s1.insert(0, 1, '*');
//	cout << s1 << endl;
//
//	//第5个位置插入一个*
//	s1.insert(5, 1, '*');
//	cout << s1 << endl;
//
//	//迭代器
//	s1.insert(s1.begin(), '&');
//	cout << s1 << endl<<endl;
//
//	string s2("hello world");
//
//	s2.erase(0, 1);//头删
//	cout << s2 << endl;
//
//	s2.erase(s2.begin());//头删
//	cout << s2 << endl;
//
//	s2.erase(5, 2);//指定位置开始删除2个
//	cout << s2 << endl<<endl;
//
//	//没给的话就全删掉
//	s2.erase(5);//这里应该也是默认npos
//	cout << s2 << endl;
//
//
//	string s3("hello world");
//
//	s3.replace(5, 1, "&&&");//把5这个位置的1个替换成&&&
//	cout << s3 << endl;
//
//	s3.replace(5, 3, "*");//从5开始的三个替换成*
//	cout << s3 << endl;
//
//	//我们再来看看怎么把所有空格都替换成%%
//	string s4("hello            world hello wugongda");
//	cout << s4 << endl;
//
//	size_t pos = s4.find(' ');
//	while (pos != string::npos)
//	{
//		s4.replace(pos, 1, "%%");
//
//		//找到下一个空格
//		pos = s4.find(' ', pos + 2);
//	}
//
//	cout << s4 << endl;
//
//	//这样的话效率不是很高，我们换个思路优化一下
//	string s5("hello            world hello wugongda");
//	cout << s5 << endl;
//	string s6;
//	s6.reserve(s5.size());
//	for (auto ch : s5)
//	{
//		if (ch != ' ')
//		{
//			s6 += ch;
//		}
//		else
//		{
//			s6 += "%%";
//		}
//	}
//	cout << s6 << endl;
//	//s5 = s6;
//	
//}
//int main()
//{
//	test_string8();
//}


//题目

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string str;
//	// cin >> str;//这个不行
//	getline(cin, str);
//	//getline(cin, str, '#');//指定碰到#结束
//
//
//	size_t pos = str.rfind(' ');
//	if (pos != str.size())
//	{
//		cout << str.size() - (pos + 1) << endl;
//	}
//	else
//	{
//		cout << str.size() << endl;
//	}
//}

//
//int main()
//{
//    string s = "hello Lotso";
//    // 1. 找字符'w'
//    size_t pos1 = s.find('L');
//    if (pos1 != string::npos) {
//        cout << "'L'在位置：" << pos1 << endl;// 输出6
//    }
//
//    // 2. 找子串"world"
//    size_t pos2 = s.find("Lotso");
//    if (pos2 != string::npos) {
//        cout << "world在位置：" << pos2 << endl;// 输出6
//    }
//
//    // 3. 从下标3开始找字符'l'
//    size_t pos3 = s.find('l', 3);  // 从第3位（0开始）往后找
//    cout << "'l'在位置：" << pos3 << endl;// 输出3（s[3]是'l'）
//}

//int main()
//{
//	string s = "hello world";
//	// 1. 从位置6开始，取5个字符
//	string sub1 = s.substr(6, 5);  // sub1 = "world"
//
//	// 2. 从位置0开始，取5个字符
//	string sub2 = s.substr(0, 5);  // sub2 = "hello"
//
//	// 3. 从位置6开始，取到末尾
//	string sub3 = s.substr(6);     // sub3 = "world"
//}

//#include <cstring>
//int main()
//{
//	string s = "hello";
//	// 1. printf输出（printf不直接支持string）
//	printf("s = %s\n", s.c_str());  // 输出：s = hello
//
//	// 2. 调用C库函数strlen（需要包含<cstring>）
//	size_t len = strlen(s.c_str());  // len = 5
//}

//int main()
//{
//	string s;
//	if (s.empty()) {  // 推荐
//		cout << "s是空串";
//	}
//	// 不推荐：if (s.size() == 0)
//}

void SplitFilename(const std::string& str)
{
	std::cout << "Splitting: " << str << '\n';
	std::size_t found = str.find_last_of("/\\");

	std::cout << " path: " << str.substr(0, found) << '\n';
	std::cout << " file: " << str.substr(found + 1) << '\n';
}
void test_string7()
{
	string s("test.cpp.zip");
	size_t pos = s.rfind('.');
	string suffix = s.substr(pos);
	cout << suffix << endl;

	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::cout << str << '\n';

	std::size_t found = str.find_first_not_of("abcdef");
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_not_of("abcdef", found + 1);
	}

	std::cout << str << '\n';

	std::string str1("/usr/bin/man");
	std::string str2("D:\\1-草莓熊Lotso\\1-课件\\4.C++课件\\C++进阶课件");

	SplitFilename(str1);
	SplitFilename(str2);

	string url2("https://legacy.cplusplus.com/reference/string/string/substr/");
	string url1("http://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=65081411_1_oem_dg&wd=%E5%90%8E%E7%BC%80%20%E8%8B%B1%E6%96%87&fenlei=256&rsv_pq=0xc17a6c03003ede72&rsv_t=7f6eqaxivkivsW9Zwc41K2mIRleeNXjmiMjOgoAC0UgwLzPyVm%2FtSOeppDv%2F&rqlang=en&rsv_dl=ib&rsv_enter=1&rsv_sug3=4&rsv_sug1=3&rsv_sug7=100&rsv_sug2=0&rsv_btype=i&inputT=1588&rsv_sug4=6786");

	string protocol, domain, uri;
	size_t i1 = url1.find(':');
	if (i1 != string::npos)
	{
		protocol = url1.substr(0, i1 - 0);
		cout << protocol << endl;
	}

	// strchar
	size_t i2 = url1.find('/', i1 + 3);
	if (i2 != string::npos)
	{
		domain = url1.substr(i1 + 3, i2 - (i1 + 3));
		cout << domain << endl;

		uri = url1.substr(i2 + 1);
		cout << uri << endl;
	}
}

void test_string4()
{
	string s("test.cpp.zip");
	size_t pos = s.find('.');
	string suffix = s.substr(pos);
	cout << suffix.c_str() << endl;

	string copy(s);
	cout << copy.c_str() << endl;

	s = suffix;
	cout << suffix.c_str() << endl;
	cout << s.c_str() << endl;

	s = s;
	cout << s.c_str() << endl;
}

void test_string5()
{
	string s1("hello world");
	string s2("hello world");

	cout << (s1 < s2) << endl;
	cout << (s1 == s2) << endl;
	cout << ("hello world" < s2) << endl;
	cout << (s1 == "hello world") << endl;
	//cout << ("hello world" == "hello world") << endl;

	cout << s1 << s2 << endl;

	string s0;
	cin >> s0;
	cout << s0 << endl;
}

void test_string6()
{
	string s1("hello world");
	string s2 = s1;

	cout << s1 << endl;
	cout << s2 << endl;

	string s3("xxxxxxxxxxxxxx");
	s1 = s3;

	cout << s1 << endl;
	cout << s3 << endl;
}

int main()
{
	test_string7();
}

//后面再补充

