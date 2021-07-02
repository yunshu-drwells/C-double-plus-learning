
#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1
#include <iostream>
#include <bitset>
#include <string>
using namespace std;
#define _N 1000

template<class T>
size_t BKDRHash(const T* str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++){
		hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..  
	}
	return hash;
}

template<class T>
size_t SDBMHash(const T* str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = 65599 * hash + ch;
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
	return hash;
}

template<class T>
size_t RSHash(const T* str)
{
	register size_t hash = 0;
	size_t magic = 63689;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}

class str2Int1 {
public:
	size_t operator()(const string& str) {
		return BKDRHash<char>(str.c_str());
	}
};

class str2Int2 {
public:
	size_t operator()(const string& str) {
		return SDBMHash<char>(str.c_str());
	}
};

class str2Int3 {
public:
	size_t operator()(const string& str) {
		return RSHash<char>(str.c_str());
	}
};


template<class K, class hashFunc1 = str2Int1,
				  class hashFunc2 = str2Int2, 
				  class hashFunc3 = str2Int3>
class BloomFilter {
public:
	BloomFilter() :_size(0) {

	}
	void insert(const string& key) {
		size_t bitCount = _bmp.size();
		_bmp.set(hashFunc1()(key) % bitCount);
		_bmp.set(hashFunc2()(key) % bitCount);
		_bmp.set(hashFunc3()(key) % bitCount);
		_size++;
	}
	bool test(const string& key) {
		size_t bitCount = _bmp.size();
		return (_bmp.test(hashFunc1()(key) % bitCount)
			&& _bmp.test(hashFunc2()(key) % bitCount)
			&& _bmp.test(hashFunc3()(key) % bitCount));
		//若有一个哈希的值在位图中不存在，那一定不存在。所有哈希值都存在，可能存在
	}
private:
	bitset<_N * 5> _bmp;
	size_t _size;
};
int main() {
	string url = "www.baidu.com";
	BloomFilter<string> bf;
	bf.insert(url);
	cout<<bf.test(url)<<endl;
	return 0;
}
#endif

#if 0
//bitset
#include <iostream>
#include <vector>
using namespace std;
//simulation of bitset
template<size_t _N>
class bitSet {
public:
	bitSet() :_bitArray((_N >> 5) + 1), _bitCount(_N) {  //_N/32+1
	}
	void set(size_t pos) {
		if (pos >= _bitCount)
			return;
		_bitArray[pos >> 5] |= (1 << (pos % 32));
	}
#if 0
	size_t count() {
		int bitCnttable[256] = {
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 	};
		size_t size = _bit.size();
		size_t count = 0;
		for (size_t i = 0; i < size; ++i)
		{
			int value = _bit[i];
			int j = 0;
			while (j < sizeof(_bit[0]))
			{
				unsigned char c = value;
				count += bitCntTable[c];
				++j;
				value >>= 8;
			}
		}
		return count;
	}
#else
	size_t count() const {
		int size = _bitArray.size();
		size_t _V = 0;
		for (int i = size - 1; 0 <= i; --i) {
			for (size_t eachEle = _bitArray[i]; eachEle != 0; eachEle >>= 4)
				_V += "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4"[eachEle & 0xF];
		}
		return _V;
	}

#endif
private:
	vector<int> _bitArray;
	size_t _bitCount;
};
int main() {
	bitSet<36> bs;
	bs.set(10);
	bs.set(20);
	bs.set(30);
	bs.set(35);
	cout<< bs.count() << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <bitset>
using namespace std;
int main() {
	bitset<10> bt;
	cout << bt << endl;
	cout << "size:" << bt.size() << endl;

	bt.set(4);
	cout << bt.set(3) << endl;  //设置某一位, 返回值是所操作的bitset对象
	cout << bt.set(3, false) << endl;  //将第三位设置为0，set的第二个bool类型的参数默认值为true
	cout << bt.set() << endl;  //设置所有位为1


	cout << bt.test(3) << endl;  //测试某一位

	cout << bt[3] << endl;  //通过重载的运算符[]访问某一位
	//cout << bt[12] << endl;  //越界操作程序会崩溃
	//cout << bt.at(3)<<endl;  //Vs2019将at方法删除了，VS2013任然可以用
	//cout << bt.at(12) << endl;  //越界操作程序会崩溃

	cout << bt.reset(3) << endl;
	cout << bt.reset() << endl;  //将所有位重置为0

	cout << bt.flip() << endl;  //所有二进制位取反

	cout << (bt <<= 2) << endl;  //左移两位

	cout << bt.count() << endl;  //统计位为1的位数

	cout << bt.to_ulong() << endl;  //将位图转换为unsigned long类型
	cout << bt.to_ullong() << endl;  //将位图转换为unsigned long long类型
	auto s = bt.to_string();
	cout << typeid(s).name() << endl;
	cout << bt.to_string() << endl;  //将位图转换为string类型
	return 0;
	}
#endif