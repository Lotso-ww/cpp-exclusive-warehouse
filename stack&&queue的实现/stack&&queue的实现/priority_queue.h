#pragma once
#include<vector>
using namespace std;

namespace Lotso
{
	// 仿函数/函数对象   对象可以像函数一样使用
	template <class T>
	struct Less
	{
		//大堆
		bool operator() (const T& x, const T& y) const { return x < y; }
	};

	template <class T>
	struct Greater
	{
		//小堆
		bool operator() (const T& x, const T& y) const { return x > y; }
	};

	//默认大的优先级高
	template<class T, class Container = std::vector<T>,class Compare=Less<T>>
	class priority_queue
	{
	public:
		template<class InPutIterator>
		priority_queue(InPutIterator first,InPutIterator last)
			:_con(first, last)
		{
			//建堆
			for (int i = (_con.size() - 1 - 1 )/ 2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}

		// 强制编译器生成默认构造
		priority_queue() = default;

		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//三个等价的形式，大堆
				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])
				if(com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}

		void adjust_down(int parent)
		{
			Compare com;
			int child = 2 * parent + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() &&com(_con[child],_con[child + 1]))
					child++;
				//if (_con[child] > _con[parent])
				//if (_con[parent] < _con[child])
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else {
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			adjust_down(0);
		}

		const T& top() 
		{
			return _con[0];
		}

		bool empty() 
		{
			return _con.empty();
		}

		size_t size() 
		{
			return _con.size();
		}


		const T& top() const
		{
			return _con[0];
		}

		bool empty() const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();  
		}
	private:
		Container _con;
	};
}