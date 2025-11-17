#pragma once

namespace Lotso
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		//list_node(const T& x = T())
		//	:_next(nullptr)
		//	,_prev(nullptr)
		//	,_data(x)  // 拷贝构造
		//{}

		//list_node(T&& x)
		//	:_next(nullptr)
		//	, _prev(nullptr)
		//	, _data(move(x)) // 移动构造或拷贝构造
		//{}

		template<class X>
		list_node(X&& x = X())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(forward<X>(x))  // 拷贝构造
		{
		}
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		using Self = list_iterator<T, Ref, Ptr>;
		using Node = list_node<T>;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{
		}

		// *it = 1
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		// ++it
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		// --it
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
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

	template<class T>
	class list
	{
		using Node = list_node<T>;
	public:
		using iterator = list_iterator<T, T&, T*>;
		using const_iterator = list_iterator<T, const T&, const T*>;

		// using iterator = list_iterator<T>;
		// using const_iterator = list_const_iterator<T>;

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
			_head = new Node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		// 9:09
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
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		list(int n, T val = T())
		{
			empty_init();
			for (int i = 0; i < n; ++i)
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

		// 传统写法
		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		// lt1 = lt3;
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

		// 现代写法
		//list(list<T>& lt)
		//list(const list& lt)
		//{
		//	empty_init();

		//	list tmp(lt.begin(), lt.end());
		//	swap(tmp);
		//}

		//// lt1 = lt3;
		////list<T>& operator=(list<T> tmp)
		//list& operator=(list tmp)
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

		//void push_back(const T& x)
		//{
		//	insert(end(), x);
		//}

		//// 不是万能引用
		//// 因为T是list的参数，list<Lotso::string>实例化时，T就确定了。
		//void push_back(T&& x)
		//{
		//	insert(end(), move(x));
		//}

		template <class... Args>
		void emplace_back(Args&&... args);

		template<class X>
		void push_back(X&& x)
		{
			// 保持x的属性往下传递
			// 实例化push_back(Lotso::string&& x)，保持右值属性往下传递
			// 实例化push_back(Lotso::string& x)，保持左值属性往下传递
			insert(end(), forward<X>(x));
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

		//void insert(iterator pos, const T& x)
		//{
		//	Node* cur = pos._node;
		//	Node* prev = cur->_prev;
		//	Node* newnode = new Node(x);

		//	// prev newnode cur
		//	prev->_next = newnode;
		//	newnode->_prev = prev;
		//	newnode->_next = cur;
		//	cur->_prev = newnode;

		//	++_size;
		//}

		//void insert(iterator pos, T&& x)
		//{
		//	Node* cur = pos._node;
		//	Node* prev = cur->_prev;
		//	Node* newnode = new Node(move(x));

		//	// prev newnode cur
		//	prev->_next = newnode;
		//	newnode->_prev = prev;
		//	newnode->_next = cur;
		//	cur->_prev = newnode;

		//	++_size;
		//}

		template<class X>
		void insert(iterator pos, X&& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(forward<X>(x));

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
			--_size;

			//return iterator(next);
			return next;
		}

		size_t size() const
		{
			/*size_t n = 0;
			for (auto& e : *this)
			{
				++n;
			}
			return n;*/
			return _size;
		}

	private:
		Node* _head;
		size_t _size = 0;
	};
}
