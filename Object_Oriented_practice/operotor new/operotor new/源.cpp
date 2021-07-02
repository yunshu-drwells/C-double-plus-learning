#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	//给默认值的构造函数也包含了默认构造函数，new对象数组会调用默认构造函数去初始化（对象数组不能给初始值）
	Test(int d = 0) : m_data(d)
	{
		cout << "Create Test Object : " << this << endl;
	}
	//自定义构造函数
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//重载=操作符
	Test& operator=(const Test& t)
	{
		cout << "Assign:" << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	//析构函数的作用是释放构造函数在堆上开辟的空间
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
	void setValue(int val) {
		m_data = val;
	}
public:
	void* operator new(size_t x) {  //x为要构造的对象大小
		int* tmp = (int*)malloc(x);
		return (void*)tmp;
	}
	void operator delete(void* ptr)
	{
		free(ptr);
	}
	void* operator new[](size_t x) {  //x为要构造的对象数组的大小
		return malloc(x);
	}
	void operator delete[](void* ptr) {  
		/*ptr计算出来的要析构的起始地址是对象数组首元素地址往前走一个指针的大小（随平台变化: 32bit是4Byte,64bit是8Byte）
		最终连同cookie也一块free了，因为构造的对象数组在头部包含了一个cookie*/
		free(ptr);
	}
private:
	int m_data;
};
	



int main()
{
	//new+类名（初始值）是操作符new
	Test* pt = new Test(10);  
	//调用操作符new(operator new)开辟空间，然后调用构造函数初始化新开辟的对象，10是传给构造函数用于初始化对象的值

	delete pt;      
	//先调用析构函数释放构造函数中在堆上开辟的空间，然后调用delete操作符释放在堆上开辟的对象的内存空间

	Test* pt1 = new Test[10];  //开辟一个对象数组
	//会调用操作符new[](operotor new[])开辟空间，并调用默认构造函数去初始化，因此对象数组是不能给初始值去初始化的

	delete[] pt1;

	return 0;
}
#endif


#if 0
//new的对象数组是不能初始化的，并且构造函数不能自定义
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
public:
	void* operator new[](size_t x) {  //x为要构造的对象数组的大小
		return ((void*)malloc(x));
	}
private:
	int m_data;
};


int main()
{
	Test* pt1 = new Test[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//Test* pt1 = new Test[10] (1, 2, 3, 4, 5, 6, 7, 8, 9, 10 );
	return 0;
}
#endif

#if 0
/*默认构造函数存在的意义就是new对象数组
保证new对象数组正确的前提是：
不定义构造函数或者自定义构造函数的同时写上默认构造函数
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	//自定义构造函数并不写默认构造函数new对象数组会报错
	Test() {

	}
	//不写默认构造函数只写，自定义构造函数的话new对象数组会报错
	Test(int x) {
		m_data = x;
	}
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
public:
	void* operator new[](size_t x) {  //x为要构造的对象数组的大小
		return ((void*)malloc(x));
	}
private:
	int m_data;
};


int main()
{
	Test* pt = new Test(10);
	Test* pt1 = new Test[10];
	return 0;
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//定位new
void* operator new(size_t sz, int* ptr, int pos)   //new操作符
{
	return (ptr + pos);
}
int main()
{
	int ar[10];
	new(ar, 0) int(1); //定位new
	new(ar, 3) int(100);
	new(ar, 5) int(200);

	int* p = new int;
	return 0;
}
#endif

#if 1
#include <iostream>
using namespace std;

//重载定位new
void* operator new(size_t sz, int* ptr, int pos) {
	return (ptr + pos);
}

int mem1[10];
int main() {
	int mem2[10];
	int* mem3 = new int[10];

	int* p = nullptr;


	//定位new
	//分配到静态区
	p = new(mem1) int(998);

	//分配到栈区
	p = new(mem2) int(666);

	//分配到堆区
	p = new(mem3) int(999);

	p = new(mem3, 5) int(100);

	return 0;
}
#endif