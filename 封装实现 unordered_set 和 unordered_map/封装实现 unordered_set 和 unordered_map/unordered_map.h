#pragma once
#include"HashTable.h"


namespace Lotso
{
	template<class K, class V,class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyofT
		{
			// 仿函数：从T（pair<const K, V>）中提取key
			const K& operator() (const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K,V>, MapKeyofT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K,V>, MapKeyofT, Hash>::ConstIterator const_iterator;


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

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair <iterator, bool> ret = insert({ key,V() });
			return ret.first->second;
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
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyofT, Hash> _ht;
	};
}
