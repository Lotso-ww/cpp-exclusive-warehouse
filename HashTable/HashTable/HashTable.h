#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 状态标识
enum State
{
	EMPTY, // 空位置 
	EXIST, // 已存储元素
	DELETE // 已删除元素
};

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


// 哈希表结点结构
template<class K,class V>
struct HashData
{
	pair<K, V> _kv; // 存储key-value对
	State _state = EMPTY; //初始状态为空
};


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


// 开放定址法哈希表(线性探测)
template<class K,class V,class Hash = HashFunc<K>>
class HashTable
{
public:

	// 构造函数(初始化哈希表大小为第一个质数)
	HashTable()
		:_tables(__stl_next_prime(1))
	{}

	// 插入 key-value对(去重)
	bool Insert(const pair<K, V>& kv)
	{
		// 1.先查找，避免重复插入
		if (Find(kv.first))
			return false;

		// 2.负载因子 >=0.7，扩容
		if ((double)_n / (double)_tables.size() >= 0.7)
		{
			HashTable<K, V, Hash> newht;
			newht._tables.resize(__stl_next_prime(_tables.size() + 1));
			// 3.迁移旧表元素到新表
			for (size_t i = 0; i < _tables.size(); i++)
			{
				// 遍历旧表，旧表数据插入到newht
				if (_tables[i]._state == EXIST)
				{
					newht.Insert(_tables[i]._kv);
				}
			}

			// 4.交换新旧表
			_tables.swap(newht._tables);
		}

		// 5.线性探测找空闲位置
		Hash hs;
		size_t hash0 = hs(kv.first) % _tables.size();
		// 线性探测
		size_t i = 1;
		size_t hashi = hash0;
		while (_tables[hashi]._state == EXIST)
		{
			// 冲突，线性探测下一个位置
			hashi = (hash0 + i) % _tables.size();
			++i;
		}

		// 6.插入元素
		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_n;

		return true;
	}

	// 查找key，返回节点指针(nullptr表示未找到)
	HashData<K, V>* Find(const K& key)
	{
		Hash hs;
		size_t hash0 = hs(key) % _tables.size();
		// 线性探测
		size_t i = 1;
		size_t hashi = hash0;
		// 遇到EMPTY才停止查找(DELETE继续探测)
		while (_tables[hashi]._state != EMPTY)
		{
			if (_tables[hashi]._state != DELETE
				&& _tables[hashi]._kv.first == key)
			{
				return &_tables[hashi];
			}
			// 线性探测下一个位置
			hashi = (hash0 + i) % _tables.size();
			++i;
		}

		return nullptr;
	}

	// 删除key(仅修改状态为DELETE,不实际删除元素)
	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);
		if (ret)
		{
			// 标记为 DELETE,避免影响后续查找
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
	std::vector<HashData<K,V>> _tables; // 哈希表数组

	size_t _n = 0;// 已存储的数据个数
};

// 链地址法哈希表（哈希桶）
namespace hash_bucket
{

	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv; // 哈希桶节点结构（链表节点）
		HashNode<K,V>* _next; 

		HashNode(const pair<K,V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K,class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
			:_tables(__stl_next_prime(1),nullptr)
			,_n(0)
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

		// 插入key-value对（头插法，支持重复插入，去重需先查找）
		bool Insert(const pair<K,V>& kv)
		{
			if (Find(kv.first))
				return false;

			Hash hs;

			// 1. 负载因子≥1，扩容（链地址法负载因子可大于1）
			if (_n == _tables.size())
			{
				std::vector<Node*> newtables(__stl_next_prime(_tables.size() + 1), nullptr);
				// 2. 迁移旧表节点到新表（直接移动节点，不新建，效率更高）
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// 遍历旧表，旧表节点重新映射，挪动到新表
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 3. 重新计算节点在新表的位置
						size_t hashi = hs(cur->_kv.first) % newtables.size();
						// 4. 头插入新表
						cur->_next = newtables[hashi];
						newtables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}

			size_t hashi = hs(kv.first) % _tables.size();

			// 5. 头插入当前节点
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		// 查找key，返回节点指针（nullptr表示未找到）
		Node* Find(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		// 删除key（链表节点删除）
		bool Erase(const K& key)
		{
			Hash hs;
			size_t hashi = hs(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (cur->_kv.first == key)
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
		std::vector<Node*> _tables;// 指针数组（存储链表头指针）
		size_t _n;
	};
}