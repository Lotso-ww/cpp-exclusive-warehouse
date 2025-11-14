#pragma once
#include"HashTable.h"

namespace Lotso
{
	template<class K,class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyofT
		{
			// 仿函数：从T（pair<const K, V>）中提取key
			const K& operator() (const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket:: HashTable<K, const K, SetKeyofT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, const K, SetKeyofT, Hash>::ConstIterator const_iterator;

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		const_iterator begin() const
		{
			return _ht.Begin();
		}

		const_iterator end() const
		{
			return _ht.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}
	private:
		hash_bucket::HashTable<K, const K, SetKeyofT, Hash> _ht;
	};
}