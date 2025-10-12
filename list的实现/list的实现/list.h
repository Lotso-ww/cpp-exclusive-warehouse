#pragma once
#include<iostream>
#include<list>
using namespace std;

namespace Lotso
{
	template<class T>
	struct list_node
	{
		list_node<T>* _prev;
		list_node<T>* _next;
		T _data;

		list_node(const T& x=T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(x)
		{}
	};


	//加个Ref,再搞一个const的太浪费了
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		using Self = list_iterator<T,Ref,Ptr>;
		using Node = list_node<T>;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{ }

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}


		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	////const迭代器，但是这样太浪费了，就只有一效部分不同
	//template<class T>
	//struct list_const_iterator
	//{
	//	using Self = list_const_iterator<T>;
	//	using Node = list_node<T>;
	//	Node* _node;

	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{
	//	}

	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	Self& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	Self& operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}


	//	Self operator++(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	Self operator--(int)
	//	{
	//		Self tmp(*this);
	//		_node = _node->_prev;
	//		return tmp;
	//	}

	//	bool operator!=(const Self& s) const
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const Self& s) const
	//	{
	//		return _node == s._node;
	//	}
	//};

	template<class T>
	class list
	{
		using Node = list_node<T>;
	public:
		/*using iterator = list_iterator<T>;
		using const_iterator = list_const_iterator<T>;*/
		using iterator = list_iterator<T, T&,T*>;
		using const_iterator = list_iterator<T, const T&,const T*>;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}
		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}

		list()
		{
			empty_init();
		}

		list(initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(size_t n, T val = T())
		{
			empty_init();
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		
		list(int n, T val = T())
		{
			empty_init();
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
			_size = 0;
		}


		//传统写法
		// lt2(lt1)
		//list(const list<T>& lt)
		list(const list& lt)//在类里面这样写也行
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		//lt1=lt3
		list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (auto& e : lt)
				{
					push_back(e);
				}
			}

			return *this;
		}


		////现代写法
		//// lt2(lt1)
		////list(const list<T>& lt)
		//list(const list& lt)//在类里面这样写也行
		//{
		//	empty_init();
		//	
		//	list tmp(lt.begin(), lt.end());
		//	swap(tmp);
		//}

		////lt1=lt3
		//list<T>& operator=(list<T> tmp)
		//{
		//	swap(tmp);
		//	return *this;
		//}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}


		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			_head->_prev = newnode;
			newnode->_next = _head;
			newnode->_prev = tail;
			tail->_next = newnode;
			++_size;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			//prev newnode cur
			newnode->_prev = prev;
			newnode->_next = cur;
			prev->_next = newnode;
			cur->_prev = newnode;
			++_size;
		}

		//用iterator做返回类型可以更好解决迭代器失效的问题
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			--_size;

			//return iterator(next);
			return next;//可以直接这样写，会隐式类型转换的
		}
		
		size_t size() const
		{
			return _size;
		}
	private:
		Node* _head;
		size_t _size = 0;
	};
}