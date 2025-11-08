#pragma once
#include"RBTree.h"

namespace Lotso
{
	template<class K, class V>
	class map
	{
		struct MapKeyofT
		{
			// 仿函数：从T（pair<const K, V>）中提取key
			const K& operator() (const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::ConstIterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}


		const_iterator begin() const
		{
			return _t.Begin();
		}

		const_iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const pair<K, V>& kv)
		{
			return _t.Find(kv);
		}

		V& operator[](const K& key)
		{
			//pair<iterator, bool> ret = _t.Insert({ key,V() });
			auto [it, flag] = _t.Insert({ key,V() });
			return it->second;
		}
	private:
		// 红黑树：存储pair<const K, V>，key不可修改
		RBTree<K, pair<const K, V>, MapKeyofT> _t;
	};
}
