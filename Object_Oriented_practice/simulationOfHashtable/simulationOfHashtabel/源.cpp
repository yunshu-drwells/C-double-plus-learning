#include <iostream>
#include <vector>
using namespace std;


/*
newHt????
负载（载荷）因子：
_size * 10 / _ht.capacity() >= 7
容量以素数增容的原因？
*/

/*
采用闭散列处理哈希冲突时，不能随便物理删除哈希表中已有的元素，若直接删除元素会影响其他元素的搜索。
比如删除元素4，如果直接删除掉，44查找起来可能会受影响。因此线性探测采用标记的伪删除法来删除一个元素。
//哈希表每个空间给个标记
//EMPTY此位置空，EXIST此位置已经有元素，DELETE元素已经删除
enum State{EMPTY，EXIST，DELETE}；I
*/


//hash设计时要尽可能少冲突，非素数有一对公约数，冲突概率暴涨，因此capacity要是素数（质数）
static const int num_primes = 32;
static const unsigned long prime_list[num_primes] =
{
	3, 7, 13, 19,
  53,         97,           193,         389,       769,
  1543,       3079,         6151,        12289,     24593,
  49157,      98317,        196613,      393241,    786433,
  1572869,    3145739,      6291469,     12582917,  25165843,
  50331653,   100663319,    201326611,   402653189, 805306457,
  1610612741, 3221225473ul, 4294967291ul
};

unsigned long GetNextPrime(size_t num) {
	for (int i = 0; i < num_primes; ++i) {
		if (prime_list[i] > num)
			return prime_list[i];
	}
	return prime_list[num_primes - 1];
}

enum State { EMPTY, EXIST, DELETE };
template<class key, class value>  //key-value
class hashTable
{
	struct elemt {
		pair<key, value> _val;
		State _state;
	};
public:
//每个空间都要有key-value, state
//构造函数
	hashTable(size_t capacity = 3):_size(0), _ht(capacity) {
		//_ht(capacity) 初始化列表中，（number）是为容器开辟了number大小的空间	
		for (size_t i = 0; i < capacity; ++i) 
			_ht[i]._state = EMPTY;
	}
public:
//插入方法
//闭散列，线性探测法
	bool insert(const pair<key, value>& val)
	{
		// 检测哈希表底层空间是否充足, 动态规划的思想
		checkCapacity();
		size_t hashAddr = hashFunc(val.first);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == val.first)
				return false;   //重复键值的元素是无法插入的
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
			/*
			// 转一圈也没有找到，注意：动态哈希表，该种情况可以不用考虑，哈希表中元素个数到达
			一定的数量，哈希冲突概率会增大，需要扩容来降低哈希冲突，因此哈希表中元素是不会存满的
			if(hashAddr == startAddr)
			return false;
			*/
		}
		// 插入元素
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
//获取容量
	size_t capacity() {
		return this->_ht.size();
	}
//获取size
	size_t size() {
		return this->_size;
	}
//查找
	int find(const key& t) {
		size_t hashAddr = hashFunc(t);
		while (_ht[hashAddr]._state != EMPTY) {
			if (_ht[hashAddr]._state != DELETE && _ht[hashAddr]._val.first == t)
				return hashAddr;
			hashAddr++;
		}
		return -1;
	}
//删除
	bool erase(const key &key) {
		int index = find(key);
		if (-1 == index)
			return false;
		_ht[index]._state = DELETE;
		_size--;
		return true; 
	}
//交换hash
	void Swap(hashTable<key, value> &ht) {
		swap(_ht, ht._ht);
		swap(_size, ht._size);
}
private:
//检查容量， 不够就扩容
	void checkCapacity()
	{
		if (_size * 10 / _ht.capacity() >= 7)
		{
			hashTable<key, value> newHt(GetNextPrime(_ht.capacity()));
			for (size_t i = 0; i < _ht.capacity(); ++i){
				if (_ht[i]._state == EXIST)
					newHt.insert(_ht[i]._val);
			}
			Swap(newHt);
		}
	}
//哈希函数：寻找插入地址
	size_t hashFunc(const key& data)	{
		return data % _ht.capacity();
	}
private:
	vector<elemt>  _ht;
	size_t       _size;
};
int main() {
	hashTable<int, int> ht;
	int ar[] = { 4, 6, 8, 3, 6, 13, 1, 2, 9 };
	int n = sizeof(ar) / sizeof(int);
	for (int i = 0; i < n; ++i) {
		ht.insert(pair<int, int>(ar[i], ar[i]));
	}
	cout << ht.size() << endl;  //当前元素个数
	ht.erase(8);
	cout << ht.size() << endl;  //删除之后元素个数
	cout <<"capacity : "<< ht.capacity() << endl;
	cout <<"key = 6 : index = "<< ht.find(6) << endl;
	cout << "key = 8 : index = " << ht.find(8) << endl;
	cout <<"key = 13 : index = " << ht.find(13) << endl;

	return 0;
}

/*
unordered系列关联式容器的底层实现是hashtable，
比如在undered_set中value就是key，而在unordered_map中value代表键值对的值
哈希函数使用除留余数法计算存放地址，那么key就必须是整形或者转换为整形才能取模==
*/