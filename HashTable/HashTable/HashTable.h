#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

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


template<class K,class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
// 特化
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto ch : key)
		{
			hash += ch;
			hash *= 131;
		}
		return hash;
	}
};
template<class K,class V,class Hash = HashFunc<K>>
class HashTable
{
public:

	HashTable()
		:_tables(__stl_next_prime(1))
	{}

	bool Insert(const pair<K, V>& kv)
	{
		if (Find(kv.first))
			return false;

		// 负载因子 >=0.7 扩容
		if ((double)_n / (double)_tables.size() >= 0.7)
		{
			HashTable<K, V, Hash> newht;
			newht._tables.resize(__stl_next_prime(_tables.size() + 1));
			for (size_t i = 0; i < _tables.size(); i++)
			{
				// 遍历旧表，旧表数据插入到newht
				if (_tables[i]._state == EXIST)
				{
					newht.Insert(_tables[i]._kv);
				}
			}

			_tables.swap(newht._tables);
		}

		Hash hs;
		size_t hash0 = hs(kv.first) % _tables.size();
		// 线性探测
		size_t i = 1;
		size_t hashi = hash0;
		while (_tables[hashi]._state == EXIST)
		{
			hashi = (hash0 + i) % _tables.size();
			++i;
		}

		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_n;

		return true;
	}

	HashData<K, V>* Find(const K& key)
	{
		Hash hs;
		size_t hash0 = hs(key) % _tables.size();
		// 线性探测
		size_t i = 1;
		size_t hashi = hash0;
		while (_tables[hashi]._state != EMPTY)
		{
			if (_tables[hashi]._state != DELETE
				&& _tables[hashi]._kv.first == key)
			{
				return &_tables[hashi];
			}
			hashi = (hash0 + i) % _tables.size();
			++i;
		}

		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);
		if (ret)
		{
			ret->_state = DELETE;
			--_n;
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	// 内部接口：仅用于扩容迁移，不检查负载因子，不扩容
	void _InsertForExpand(const pair<K, V>& kv)
	{
		Hash hs;
		size_t hash0 = hs(kv.first) % _tables.size();
		size_t i = 1;
		size_t hashi = hash0;
		while (_tables[hashi]._state == EXIST)
		{
			hashi = (hash0 + i) % _tables.size();
			++i;
		}
		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_n;
	}
private:
	std::vector<HashData<K,V>> _tables;

	size_t _n = 0;// 存储的数据个数
};