#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 质数表(SGI STL 同款，用于扩容)
static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
  53,         97,         193,       389,       769,
  1543,       3079,       6151,      12289,     24593,
  49157,      98317,      196613,    393241,    786433,
  1572869,    3145739,    6291469,   12582917,  25165843,
  50331653,   100663319,  201326611, 402653189, 805306457,
  1610612741, 3221225473, 4294967291
};
inline unsigned long __stl_next_prime(unsigned long n)
{
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	// >= n
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

// 哈希函数仿函数
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;// 默认直接转换
	}
};

// 特化string类型的哈希函数
template<>
struct HashFunc<string>
{
	// BKDR字符串哈希算法
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto ch : key)
		{
			hash += ch;// 累加字符ASCII码
			hash *= 131;// 乘质数131，减少冲突
		}
		return hash;
	}
};

namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	// 前置声明
	template<class K, class T, class KeyofT, class Hash>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyofT, class Hash>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyofT, Hash> HT;
		typedef HTIterator<K, T, Ref, Ptr, KeyofT, Hash> Self;
		Node* _node;
		const HT* _pht;
		
		HTIterator(Node* node,const HT* pht)
			:_node(node)
			,_pht(pht)
		{}

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
			if (_node->_next) //当前桶没走完
			{
				_node = _node->_next;
			}
			else //当前桶走完了，找到下一个桶的第一个结点
			{
				KeyofT kot;
				Hash hs;

				// 算出当前位置
				size_t hashi = hs(kot(_node->_data)) % _pht->_tables.size();
				// ++到下一个位置
				++hashi;
				while (hashi < _pht->_tables.size())
				{
					if (_pht->_tables[hashi]) // 找到下一个不为空的桶
					{
						_node = _pht->_tables[hashi];
						break;
					}
					else
					{
						++hashi;
					}
				}

				if (hashi == _pht->_tables.size()) // 最后一个桶走完了，要++到end()位置
				{
					// end() 中_node是空
					_node = nullptr;
				}
			}

			return *this;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator ==(const Self& s) const
		{
			return _node == s._node;
		}
	};

	template<class K,class T ,class KeyofT,class Hash = HashFunc<K>>
	class HashTable
	{
		// 友元声明
		template<class K, class T, class Ref, class Ptr, class KeyofT, class Hash>
		friend struct HTIterator;

		typedef HashNode<T> Node;
	public:
		typedef HTIterator<K, T, T&, T*, KeyofT, Hash> Iterator;
		typedef HTIterator<K, T, const T&, const T*, KeyofT, Hash> ConstIterator;
		Iterator Begin()
		{
			if (_n == 0)
			{
				return End();
			}
			
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return  Iterator(_tables[i],this);
				}

			}

			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr,this);
		}

		ConstIterator Begin() const
		{
			if (_n == 0)
			{
				return End();
			}

			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return  ConstIterator(_tables[i],this);
				}

			}

			return End();
		}

		ConstIterator End() const
		{
			return ConstIterator(nullptr,this);

		}

		HashTable()
			:_tables(__stl_next_prime(1), nullptr)
			, _n(0)
		{}

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_n = 0;
		}

		pair<Iterator,bool> Insert(const T& data)
		{
			KeyofT kot;
			Hash hs;

			// 先查找，避免重复插入
			if (auto it = Find(kot(data));it!=End())
				return {it,false};

		
			// 负载因子 == 1 就开始扩容
			if (_n == _tables.size())
			{
				std::vector<Node*> newtables(__stl_next_prime(_tables.size() + 1), nullptr);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// 遍历旧表，旧表节点重新映射，挪动到新表
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 头插
						size_t hashi = hs(kot(cur->_data)) % newtables.size();
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}

			size_t hashi = hs(kot(data)) % _tables.size();

			// 头插
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return {Iterator(newnode,this),true};
		}

		Iterator Find(const K& key)
		{
			KeyofT kot;
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return { cur ,this};
				}

				cur = cur->_next;
			}

			return { nullptr,this };
		}

		bool Erase(const K& key)
		{
			KeyofT kot;
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					// 删除
					if (prev == nullptr)
					{
						// 桶中第一个节点
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					--_n;
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}

			return false;
		}
	private:
		std::vector<Node*> _tables;
		size_t _n;
	};
}