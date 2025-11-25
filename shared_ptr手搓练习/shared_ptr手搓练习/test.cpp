#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
using namespace std;

namespace Lotso
{
	template<class T>
	class shared_ptr
	{
	public:
		explicit shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{
		}

		template<class D>
		explicit shared_ptr(T* ptr, D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _del(del)
		{
		}

		~shared_ptr()
		{
			release();
		}

		shared_ptr(const shared_ptr& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}

		shared_ptr& operator = (const shared_ptr& sp)
		{
			if (_ptr != sp._ptr)
			{
				release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
			}

			return *this;
		}

		T* get()
		{
			return _ptr;
		}

		int use_count() const
		{
			return _pcount;
		}

		void release()
		{
			if (--(*_pcount) == 0)
			{
				_del(_ptr);

				delete _pcount;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator[](size_t i)
		{
			return _ptr[i];
		}
	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) {delete ptr; };
	};
}


#include<memory>
class A
{
public:
	A(int a1 = 1, int a2 = 1)
		:_a1(a1)
		, _a2(a2)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

	int _a1 = 1;
	int _a2 = 1;
};


//int main()
//{
//	Lotso::shared_ptr<A> sp1(new A);
//	Lotso::shared_ptr<A> sp2(sp1);
//	sp1 = sp1;
//	sp1 = sp2;
//
//	Lotso::shared_ptr<A> sp3(new A);
//
//	sp1 = sp3;
//	return 0;
//}




//template<class T>
//void DeleteArrayFunc(T* ptr)
//{
//	delete[] ptr;
//}
//
//template<class T>
//class DeleteArray
//{
//public:
//	void operator()(T* ptr)
//	{
//		delete[] ptr;
//	}
//};
//
//int main()
//{
//	// 定制删除器
//	Lotso::shared_ptr<A> sp1(new A[10], DeleteArray<A>());// 仿函数
//	Lotso::shared_ptr<A> sp2(new A[10], DeleteArrayFunc<A>);// 函数指针
//
//	// 推荐
//	Lotso::shared_ptr<A> sp3(new A[10], [](A* ptr) {delete[] ptr; });// lambda
//	Lotso::shared_ptr<FILE> sp4(fopen("Test.cpp", "r"), [](FILE* ptr) {fclose(ptr); });
//	Lotso::shared_ptr<A> sp5(new A);
//
//	// 删除器的位置是一致的,shared_ptr在构造函数参数,unique_ptr类模版的参数
//	std::unique_ptr<A, DeleteArray<A>> up1(new A[10]); // 仿函数
//	std::unique_ptr<A, void(*)(A*)> up2(new A[10], DeleteArrayFunc<A>);// 函数指针
//	auto del = [](A* ptr) {delete[] ptr; };
//	std::unique_ptr<A, decltype(del)> up3(new A[10], del); // lambda
////
//	// 更简洁的方式
//	std::shared_ptr<A[]> sp10(new A[10]);
//	std::unique_ptr<A[]> up10(new A[10]);
////
//	auto sp11 = make_shared<A>(1, 1);
//
//	return 0;
//}