#pragma once
#include<vector>
#include<list>
#include<deque>
using namespace std;
namespace Lotso
{
	// 模板参数：T为元素类型，Container为底层容器类型（默认deque<T>）
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack() {}
		void push(const T& x )
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top() 
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}