#pragma once
#include"RBTree.h"

namespace Lotso
{
	template<class K>
	class set
	{
		// 仿函数：从T（const K）中提取key
		struct SetKeyofT
		{
			const K& operator() (const K& key)
			{
				return key;
			}
		};
	public:
		// typename 是为了防止这里没实例化报错
		typedef typename RBTree<K, const K, SetKeyofT>::Iterator iterator;
		typedef typename RBTree<K, const K, SetKeyofT>::ConstIterator const_iterator;

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
		
		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		// 红黑树：存储const K，禁止修改
		RBTree<K, const K, SetKeyofT> _t;
	};
}
