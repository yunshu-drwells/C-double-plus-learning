#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Note: assumes long is at least 32 bits.
static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
	53,         97,           193,         389,       769,
	1543,       3079,         6151,        12289,     24593,
	49157,      98317,        196613,      393241,    786433,
	1572869,    3145739,      6291469,     12582917,  25165843,
	50331653,   100663319,    201326611,   402653189, 805306457,
	1610612741, 3221225473ul, 4294967291ul
};

inline unsigned long _stl_next_prime(unsigned long n)
{
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n); 
	//lower_bound是算法库algorithm中的函数，在[first, last)区间上返回一个存放不小于n的数的内存地址
	return pos == last ? *(last - 1) : *pos;
}



//结点
template<class Value>
struct hashtable_node {
	hashtable_node* next;
	Value val;
};

#if 0
//实现迭代器
template <class Value, class Key>
struct __hashtable_iterator {
	node* cur;
	hashtable* ht;

	__hashtable_iterator(node* n, hashtable* tab) : cur(n), ht(tab) {}
	__hashtable_iterator() {}
	reference operator*() const { return cur->val; }
	pointer operator->() const { return &(operator*()); }
	iterator& operator++(); 
	iterator operator++(int);
	bool operator==(const iterator& it) const { return cur == it.cur; }
	bool operator!=(const iterator& it) const { return cur != it.cur; }
};
#endif


template <class Value, class Key>
class hashtable {
typedef size_t size_type;
typedef struct hashtable_node<Value> node;
typedef Value value_type;
typedef Value key_type;
public:
//构造函数
	hashtable(size_t n): num_elements(n){
		initialize_buckets(n);
	}
//开辟新结点
	node* new_node(const value_type& obj)
	{
		node* n = (node*)malloc(sizeof(node));
		n->next = (node*)0;
		n->val = obj;
		return n;
	}
	//判断是否需要扩容
	void resize(size_type num_elements_hint)
	{
		const size_type old_n = buckets.size();
		if (num_elements_hint > old_n) {
			const size_type n = next_size(num_elements_hint);
			if (n > old_n) {
				vector<node*> tmp(n, (node*)0);
				for (size_type bucket = 0; bucket < old_n; ++bucket) {
					node* first = buckets[bucket];
					while (first) {
						size_type new_bucket = bkt_num_key(first->val, n);
						buckets[bucket] = first->next;
						first->next = tmp[new_bucket];
						tmp[new_bucket] = first;
						first = buckets[bucket];
					}
				}
				buckets.swap(tmp);
			}
		}
	}
//插入方法(唯一值)
	bool insert_unique(const value_type& obj)
	{
		/*当元素个数大于hashtable的容量时，一个桶下面的元素个数会非常多，容易牺牲索引效率
		在插入之前要先判断元素个数是否大于容量，在元素个数大于容量时要扩容*/
		resize(num_elements + 1);
		return insert_unique_noresize(obj);
	}
	size_type bkt_num_key(const key_type &key, size_t n) const {
		return key % n;
	}
	size_type bkt_num_key(const key_type& key) const {
		return bkt_num_key(key, buckets.size());
		//?????????????????????????????????是size还是capacity
	}
	size_type bkt_num(const value_type& obj) {
		return bkt_num_key(obj);  //sgi中参数是get_key(obj)， 因为值不一定是int类型
	}
	bool insert_unique_noresize(const value_type& obj) {
		//1.计算哈希地址
		const size_type n = bkt_num(obj);
		node* first = buckets[n];

		for (node* cur = first; cur; cur = cur->next)
			if (cur->val == obj)
				return false;
		//头插
		node* tmp = new_node(obj);
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return true;
	}
//插入方法(相等值)
	bool insert_equal_noresize(const value_type& obj)
	{
		const size_type n = bkt_num(obj);
		node* first = buckets[n];

		//在桶中第一个相同的值后面尾插
		for (node* cur = first; cur; cur = cur->next)
			if (cur->val == obj) {
				node* tmp = new_node(obj);
				tmp->next = cur->next;
				cur->next = tmp;
				++num_elements;
				return true;
			}
		//桶中没有相同值就头插
		node* tmp = new_node(obj);
		tmp->next = first;
		buckets[n] = tmp;
		++num_elements;
		return true;
	}
	bool insert_equal(const value_type& obj)
	{
		resize(num_elements + 1);
		return insert_equal_noresize(obj);
	}


//求size
	size_type size()const {
		return num_elements;
	}
//求最大容量
	size_type max_size()const {
		return size_type(-1);
	}
//判空
	bool empty()const {
		return size() == 0;
	}
	void show_hashtable() {
		for (size_t i = 0; i < buckets.size(); ++i) {
			node* p = buckets[i];
			cout << "bucket["<<i<<"] :";
			while (p != NULL) {
				cout << p->val << "->";
				p = p->next;
			}
			cout << endl;
		}

	}
private:
	size_type next_size(size_type n) const {
		return _stl_next_prime(n);
	}
	void initialize_buckets(size_type n) {
		const size_type n_buckets = next_size(n);
		//预留空间
		buckets.reserve(n_buckets);
		//插入空指针
		buckets.insert(buckets.end(), n_buckets, (node*)0);
		//元素个数赋0
		num_elements = 0;	
	}
private:
	vector<node*> buckets;
	size_type num_elements;
};

int main() {
	int ar[] = {2, 55, 108, 161, 6, 8, 6, 8, 4};
	int n = sizeof(ar) / sizeof(int);
	hashtable<int, int> ht(53);
	for (int i = 0; i < n; ++i) {
		//ht.insert_unique(ar[i]);
		ht.insert_equal(ar[i]);
	}
	ht.show_hashtable();
	return 0;
}
//代码格式化:Ctrl+K+F