#include<iostream>
using namespace std;

//#include<exception>
//
//double Divide(int a, int b)
//{
//	// 当 b == 0 时抛出异常
//	if (b == 0)
//	{
//		//string s("Divide by zero condition!");
//		//throw s;
//
//		throw exception("Divide by zero condition!");
//	}
//	else
//	{
//		return ((double)a / (double)b);
//	}
//}
//
//
//void Func()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Divide(len, time) << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	cout << "Func():" << __LINE__<< endl;
//}
//
//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		// 异常会先匹配最适配的
//		catch (const string& s)
//		{
//			cout << s << endl;
//		}
//		catch (const exception& e)
//		{
//			cout << e.what() << endl;
//		}
//		catch (...) // 任意类型的对象
//		{
//			cout << "未知异常" << endl;
//		}
//
//		cout << "Func():" << __LINE__ << endl;
//	}
//
//	return 0;
//}

#include<thread>

// 一般大型项目程序才会使用异常,下面我们模拟设计一个服务的几个模块
// 每个模块的继承都是Expection的派生类,每个模块可以添加自己的数据
// 最后捕获的时候,我们捕获基类就可以,通过多态可以打印不同信息

class Exception
{
public:
	Exception(const string& errmsg,int id)
		:_errmsg(errmsg)
		,_id(id)
	{ }

	virtual string what() const
	{
		return _errmsg;
	}

	int getid()const
	{
		return _id;
	}

protected:
	string _errmsg;
	int _id;
};

class SqlException :public Exception
{
public:
	SqlException(const string& errmsg,int id,const string& sql)
		:Exception(errmsg,id)
		,_sql(sql)
	{ }

	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
private:
	const string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{
	}

	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};

class HttpException : public Exception
{
public:
	HttpException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{
	}

	virtual string what() const
	{
		string str = "HttpException:";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}

private:
	const string _type;
};

void SQLMgr()
{
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}
	else
	{
		cout << "SQLMgr 调用成功" << endl;
	}
}

void CacheMgr()
{
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	else
	{
		cout << "CacheMgr 调用成功" << endl;
	}
	SQLMgr();
}

void HttpServer()
{
	if (rand() % 3 == 0)
	{
		throw HttpException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpException("权限不足", 101, "post");
	}
	else
	{
		cout << "HttpServer调用成功" << endl;
	}
	CacheMgr();
}


//int main()
//{
//	srand(time(0));
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//
//		try
//		{
//			HttpServer();
//		}
//		catch (const Exception& e) // 这里捕获基类,基类对象和派生类对象都可以被捕获
//		{
//			// 多态调用
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}


//// 下面程序模拟展示了聊天时发送消息，发送失败补货异常，但是可能在
//// 电梯地下室等场景手机信号不好，则需要多次尝试
//// 如果多次尝试都发送不出去，则就需要捕获异常再重新抛出，
//// 其次如果不是网络差导致的错误，捕获后也要重新抛出。
//
//void _SendMsg(const string& s)
//{
//	if (rand() % 2 == 0)
//	{
//		throw HttpException("网络不稳定,发送失败",102, "put");
//	}
//	else if (rand() % 7 == 0)
//	{
//		throw HttpException("你已经不是对方的好友,发送失败", 102, "put");
//	}
//	else
//	{
//		cout << "发送成功" << endl;
//	}
//}
//
//// 网络不稳定,要求重试三次,均失败
//void SendMsg(const string& s)
//{
//	for (size_t i = 0; i < 4; i++)
//	{
//		try
//		{
//			_SendMsg(s);
//
//			// 走到这里,如果没有抛异常导致结束
//			// 那就代表成功了,可以执行到这个break,跳出循环
//			break;
//		}
//		catch (const Exception& e)
//		{
//			if (e.getid() == 102)
//			{
//				if (i == 3)
//					throw;
//
//				cout << "开始第" << i + 1 << "重试" << endl;
//			}
//			else
//			{
//				// 重新抛出异常
//				// throw e;
//				throw;
//			}
//		}
//	}
//}
//
//int main()
//{
//	srand(time(0));
//	string str;
//	while (cin >> str)
//	{
//		try
//		{
//			SendMsg(str);
//		}
//		catch (const Exception& e)
//		{
//			cout << e.what() << endl << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}

// C++11标记不会抛异常的方法
// double Divide(int a, int b) noexcept
// C++98用来标记会抛异常的方法
// double Divide(int a,int b) throw(const char*)

double Divide(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，那下面的array就没有得到释放。
	// 所以这里捕获异常后并不处理异常，
	// 异常还是交给外层处理，这里捕获了再重新抛出去。
	int* array = new int[10];

	int len, time;
	cin >> len >> time;
	try {
	cout << Divide(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;

		// 重新抛出，捕获到什么抛出什么
		throw;
	}

	cout << "delete []" << array << endl;
	delete[] array;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}

	// 不确定是检查是否为不抛异常,不抛就返回1;
	//int i = 0;
	//cout << noexcept(Divide(1, 2)) << endl;
	//cout << noexcept(Divide(1, 0)) << endl;
	//cout << noexcept(Func()) << endl;
	//cout << noexcept(++i) << endl;

	return 0;
}


// C++11标记不会抛异常的方法
// double Divide(int a, int b) noexcept
// C++98用来标记会抛异常的方法
// double Divide(int a,int b) throw(const char*)

// C++98
// 这里表示这个函数只会抛出bad_alloc的异常
// void* operator new (std::size_t size) throw (std::bad_alloc);
// 这里表示这个函数不会抛出异常
// void* operator delete (std::size_t size, void* ptr) throw();
// C++11
// size_type size() const noexcept;
// iterator begin() noexcept;
// const_iterator begin() const noexcept;

double Divide(int a, int b) noexcept
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
int main()
{
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Divide(len, time) << endl;
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	int i = 0;
	cout << noexcept(Divide(1, 2)) << endl;
	cout << noexcept(Divide(1, 0)) << endl;
	cout << noexcept(++i) << endl;
	return 0;
}