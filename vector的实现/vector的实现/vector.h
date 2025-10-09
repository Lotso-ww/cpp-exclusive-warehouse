#pragma once

#include<cstring>
#include<assert.h>
#include<iostream>
using namespace std;

namespace Lotso
{
	template<class T>
	class vector
	{
	public:
		//typedef T* iterator;
		using iterator = T*;
		using const_iterator = const T*;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			//:_start(nullptr)
			//,_finish(nullptr)
			//,_end_of_storage(nullptr)
		{ }

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		vector(initializer_list<T> il)
		{
			reserve(il.size());
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		//传统写法
		/*vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}*/

		/*vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				clear();

				reserve(v.capacity());
				for (const auto& e : v)
				{
					push_back(e);
				}
			}
			return *this;
		}*/

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		//暂时解决类型错误匹配到下面那个模板的问题
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		//现代写法
		//函数模板--不一定是vector迭代器，也可以是其它的迭代器
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			//reserve(last - first);//有的迭代器不行
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector<T>& operator=( vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}


		void clear()
		{
			_finish = _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				//先记录一下，不然后面start会变
				size_t sz = size();
				T* tmp = new T[n];
				/*if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}*///string,vector这种深拷贝的会出错
				
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						//tmp[i] = _start[i];//swap更好用
						std::swap(tmp[i], _start[i]);
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			// 扩容可能导致 pos 失效，需记录偏移量
			if (_finish == _end_of_storage)
			{
				//提前记录一下
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;
			return pos;
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}