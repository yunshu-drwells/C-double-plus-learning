#if 0

#include <iostream>
using namespace std;
int main() {
	try {
		int* p = new int[536870911];  //array_max_bit: 2147483647bit
	}catch(bad_alloc &e){
		cout << e.what() << endl;
		return 0;
	}
	cout << "alloc successed" << endl;
	return 0;
}

#endif


#if 0
#include <iostream>
using namespace std;

#define DefaultArraySize 10

template<typename elemType>
class Array{
private:
	int  size;
	elemType* ia;
public:
	explicit Array(int sz = DefaultArraySize)	{
		size = sz;
		ia = new elemType[size];
	}
	~Array(){
		delete[] ia;
	}
	elemType& operator[](int ix) const
	{
		if (ix < 0 || ix >= size)		{
			string eObj = "out_of_range error in Array<elemType >::operator[]()";
			throw out_of_range(eObj);
			//throw range_error(eObj);
			//throw bad_alloc(eObj);
		}
		return  ia[ix];
	}
};

int main()
{
	//int br[10];   br[12];
	Array<int> ar;
	for (int i = 1; i <= 10; ++i)
		ar[i - 1] = i;

	try	{
		for (int i = 0; i <= 10; ++i)
			cout << ar[i] << " ";
		cout << endl;
	}catch (const out_of_range & e)	{
		cout << endl;
		cout << e.what() << endl;
		return 0;
	}
}
#endif


#if 0
#include <iostream>
using namespace std;

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try	{
		Func();
	}catch (const char* errmsg)	{
		cout << errmsg << endl;
	}
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

//栈满异常声明
template<typename T>
class pushOnFull
{
private:
	T _value;
public:
	pushOnFull(T i)	{
		_value = i;
	}
	T value()const	{
		return _value;
	}
	void print()	{
		cerr << "栈满，" << value() << "未压入栈" << endl;
	}
};

//栈空异常声明
template<typename T>
class popOnEmpty
{
public:
	void print()	{
		cerr << "栈已空，无法出栈" << endl;
	}
};

template<typename T>
class Stack
{
private:
	int top;                                    //栈顶指针（下标）
	T* elements;                               //动态建立的数值
	int maxSize;                               //栈最大允纳的元素个数
public:
	Stack(int default_size = 20)	{
		maxSize = default_size;
		elements = new T[maxSize];
		top = -1;
	}
	~Stack()	{
		delete[] elements;
	}
	////////////////////////////////////////////////////////////////
	void Push(const T& data) throw(pushOnFull<T>)	{
		if (IsFull())
			throw pushOnFull<T>(data);
		elements[++top] = data;
	}
	T Pop() throw(popOnEmpty<T>)	{
		if (IsEmpty())
			throw popOnEmpty<T>();

		T data = elements[top];
		top--;
		return data;
	}
	/////////////////////////////////////////////////////////////////
	bool IsEmpty() const	{
		return top == -1;
	}
	bool IsFull() const	{
		return top == maxSize - 1;
	}
	void PrintStack()	{
		for (int i = top; i >= 0; --i)
			cout << elements[i] << " ";
		cout << endl;
	}
};


int main()
{
	Stack<int> st(10);

	try	{
		for (int i = 1; i <= 10; ++i)
		{
			st.Push(i);
		}
	}	catch (pushOnFull<int>& e)
	{
		e.print();
		return 0;
	}
	st.PrintStack();

	try	{
		for (int i = 0; i <= 10; ++i)
			st.Pop();
	}	catch (popOnEmpty<int>& e)
	{
		e.print();
		return 0;
	}
	cout << "Main End." << endl;
	return 0;
}

#endif



















#if 0
//C++11 shared_ptr
#include <iostream>
#include <memory>  //new 
using namespace std;
int main()
{
	int* p = new int(10);
	int* q = new int(20);

	shared_ptr<int> sp1(p);
	cout << *sp1 << endl;
	cout << "use_count = " << sp1.use_count() << endl;

	{
		shared_ptr<int> sp2 = sp1;
		cout << "use_count = " << sp1.use_count() << endl;
	}
	cout << "use_count = " << sp1.use_count() << endl;


	sp1.reset(q);  //重定向引用的资源
	cout << *sp1 << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// 1.演示引用计数线程安全问题，就把AddRefCount和SubRefCount中的锁去掉
// 2.演示可能不出现线程安全问题，因为线程安全问题是偶现性问题，main函数的n改大一些概率就变大了，就容易出现了。
// 3.下面代码我们使用SharedPtr演示，是为了方便演示引用计数的线程安全问题，将代码中的SharedPtr换成shared_ptr进行测试，可以验证库的shared_ptr，发现结论是一样的。
template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}
	~SharedPtr() { Release(); }
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	// sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		if (_ptr != sp._ptr)
		{
			// 释放管理的旧资源
			Release();
			// 共享管理新对象的资源，并增加引用计数
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			AddRefCount();
		}
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }
	void AddRefCount()
	{
		// 加锁或者使用加1的原子操作
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		// 引用计数减1，如果减到0，则释放资源
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();
		if (deleteflag == true)
			delete _pMutex;
	}
private:
	int* _pRefCount; // 引用计数
	T* _ptr; // 指向管理资源的指针
	mutex* _pMutex; // 互斥锁
};

class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0)
		:_year(year), _month(month), _day(day)
	{ cout << "Date()" << endl; }
	~Date() { cout << "~Date()" << endl; }
	int _year;
	int _month;
	int _day;
};

void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		SharedPtr<Date> copy(sp);
		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}
int main()
{
	SharedPtr<Date> p(new Date);
	cout << p.Get() << endl;
	const size_t n = 999999;
	thread t1(SharePtrFunc, ref(p), n);
	thread t2(SharePtrFunc, ref(p), n);
	t1.join();
	t2.join();
	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	return 0;
}
#endif


#if 0
//循环引用
#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode
{
public:
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
	T data;
	shared_ptr<ListNode<T>> m_prev;   //ListNode *m_prev;
	shared_ptr<ListNode<T>> m_next;   //ListNode *m_next;
};

int main()
{
	shared_ptr<ListNode<int>> node1(new ListNode<int>);
	shared_ptr<ListNode<int>> node2(new ListNode<int>);
	cout << "use_count 1 = " << node1.use_count() << endl;
	cout << "use_count 2 = " << node2.use_count() << endl;

	node1->m_next = node2;
	node2->m_prev = node1;

	cout << "use_count 1 = " << node1.use_count() << endl;  //2
	cout << "use_count 2 = " << node2.use_count() << endl;  //2
	return 0;
}

#endif



#if 0
//循环引用:解决办法
#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode
{
public:
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
	T data;
	weak_ptr<ListNode<T>> m_prev;   //ListNode *m_prev;  //弱指针 * ->
	weak_ptr<ListNode<T>> m_next;   //ListNode *m_next;
};

int main()
{
	shared_ptr<ListNode<int>> node1(new ListNode<int>);
	shared_ptr<ListNode<int>> node2(new ListNode<int>);
	cout << "use_count 1 = " << node1.use_count() << endl;
	cout << "use_count 2 = " << node2.use_count() << endl;

	node1->m_next = node2;
	node2->m_prev = node1;

	cout << "use_count 1 = " << node1.use_count() << endl;  //2
	cout << "use_count 2 = " << node2.use_count() << endl;  //2
	return 0;
}

#endif




#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//内置类型删除器
template<class T>
struct freeMalloc{
	void operator()(T* ptr)	{
		cout << "free type ptr : " << ptr << endl;
		free(ptr);
	}
};

//文件指针删除器
struct freeFile {
	void operator()(FILE* fp) {
		cout << "free file ptr : " << fp << endl;
		fclose(fp);
	}
};

template<typename U>
auto freeMal = [](U* p)->void {free(p); };

auto freeFil = [](FILE* fp)->void {fclose(fp); };

void freeFi(FILE* fp) {
	fclose(fp);
}
int main()
{
	//如果不是new的，比如malloc或者是文件指针和套接字
	int *p = (int *)malloc(sizeof(int));

#if 0
	shared_ptr<int> is(p, freeMalloc<int>());  //仿函数
#else
	//shared_ptr<int> is(p, [](int* p)->void {free(p); } );  //lambda
	shared_ptr<int> is(p, freeMal<int>);  //lambda
#endif


	FILE* fp = fopen("test.txt", "w");
#if 0
	//shared_ptr<FILE> fs(fp, freeFile());  //仿函数
#else
	//shared_ptr<FILE> fs(fp, [](FILE* fp)->void {fclose(fp); } );  //lambda
	shared_ptr<FILE> fs(fp, freeFil );  //lambda
	//shared_ptr<FILE> fs(fp, freeFi);  //函数地址
#endif

	return 0;
}

#endif

















#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif
