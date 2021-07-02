#if 1
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class Singleton {
public:
	static Singleton* GetInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == _singleton) {
			_mt.lock();
			if (nullptr == _singleton) {
				_singleton = new Singleton();
			}
			_mt.unlock();
		}
		return _singleton;
	}
private:
	Singleton() {};
private:
	static Singleton* _singleton;
	static mutex _mt;
};

Singleton* Singleton::_singleton = nullptr;
mutex Singleton::_mt; 
void thread_func(int n)
{
	for (int i = 0; i < n; ++i)
		cout << Singleton::GetInstance() << endl;
}

	
int main() {
	thread t1(thread_func, 10);
	thread t2(thread_func, 10);
	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	return 0;
}




#endif

#if 0
//懒汉模式
#include <iostream>
using namespace std;
class Singleton {
public:
	static Singleton* getInstance() {
		if (nullptr == _singleton)
			_singleton = new Singleton;
		return _singleton;
	}
private:
	Singleton() {};
private:
	static Singleton* _singleton;
};

Singleton* Singleton::_singleton = nullptr;

int main() {
	Singleton* i = Singleton::getInstance();
	Singleton* i1 = Singleton::getInstance();
	Singleton* i2 = Singleton::getInstance();
	Singleton* i3 = Singleton::getInstance();

	return 0;
}
#endif


#if 0
//饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	// 构造函数私有
	Singleton() {};

	// C++98 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	// or
	// C++11
	//Singleton(Singleton const&) = delete;
	//Singleton& operator=(Singleton const&) = delete;

private:
	static Singleton m_instance;
};

Singleton Singleton::m_instance;



#endif

#if 0
//只允许创建一个对象
#include <iostream>
using namespace std;
class Test {
public:
	static Test* creatInstance() {
		if (soleInstance == nullptr) 
			soleInstance = new Test;
		return soleInstance;
	}
private:
	Test() {};
private:
	static Test* soleInstance;
};
Test* Test::soleInstance = nullptr;  //静态成员类外声明

int main() {
	Test* p = Test::creatInstance();
	Test* p1 = Test::creatInstance();
	Test* p2 = Test::creatInstance();
	return 0;
}


#endif

#if 0
//不允许对象拷贝
#include <iostream>
#include <boost/utility.hpp>
using namespace std;
class Test : public boost::noncopyable {

};
int main() {
	Test t1;
	//Test t2 = t1;  //不能拷贝构造，派生类要拷贝构造就得先拷贝构造基类
	return 0;
}

#endif

#if 0
//不允许对象拷贝
#include <iostream>
using namespace std;
class Test {
public:
	Test() = default;
	Test(const Test& t) = delete;
private:
	int a = 0;
	int b = 0;
};
int main() {
	Test t1;
	//Test t2 = t1;
	Test t3;
	t3 = t1;  //对象赋值
	return 0;
}
#endif

#if 0
//不允许对象拷贝
#include <iostream>
using namespace std;
class Test {
public:
	Test()= default;
private:
	Test(const Test& t) {};
private:
	int a = 0;
	int b = 0;
};
int main() {
	Test t1;
	//Test t2 = t1;
	Test t3;
	t3 = t1;  //对象赋值
	return 0;
}
#endif

#if 0
//复习定位new
#include <iostream>
using namespace std;
static int mem1[10];

//重载定位new
void* operator new(size_t sz, int* ptr, int pos) {
	return (ptr + pos);
}

int main() {
	int* p = nullptr;
	p = new(mem1) int(998);
	return 0;
}
#endif




#if 0
//不允许在堆上创建
#include <iostream>
using namespace std;
class Test {
private:
	void* operator new(size_t sz) {};
private:
	int a = 0;
	int b = 0;
};
int main() {

	return 0;
}

#endif

#if 0
//不允许在堆上创建
#include <iostream>
using namespace std;
class Test
{
public:
	static Test CreateInstance()  //要在堆上实例化对象，就得依靠这个静态方法
	{
		return Test();
	}
	Test(const Test& c) {};  //将拷贝构造函数声明为公有
private:
	Test() { }  //将构造函数声明为私有
private:
	int a = 0;
	int b = 0;
};

int main()
{
	Test t = Test::CreateInstance();
	return 0;
}
#endif




#if 0
//只允许在堆上创建
#include <iostream>
using namespace std;
class Test
{
public:
	static Test* CreateInstance()  //要在堆上实例化对象，就得依靠这个静态方法
	{
		return new Test;
	}
	//Test(const Test &) = delete;
private:
	Test(){ }  //将构造函数声明为私有
private:
	int a = 0;
	int b = 0;
};

void main()
{
	Test t = Test::CreateInstance();
}
#endif