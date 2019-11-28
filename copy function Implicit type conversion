//explicit  //单个参数的构造函数，还具有类型转换的作用
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	Test(int d = 0) : m_data(d)  	//构造函数的类型转换（隐式）Test t1;   t1 = 998;
	{
		m_count++;
	}
	//明显 显示    构造函数的隐式类型转换
	//explicit Test(int d = 0) : m_data(d)
	//{
	//	m_count++;
	//}
	~Test()
	{
		m_count--;
	}
public:
	int GetData()const
	{return this->m_data;}
public:
	operator int() //强制转换
	{
		return this->m_data;
	}
public:
	void list()
	{
		fun();
	}
	static void fun()
	{
		m_count = 10;
		cout<<"Test::fun() static"<<endl;
	}
private:
	int m_data;
	static int m_count;
};

int Test::m_count = 0; //

int main()
{
	Test t1;
	t1 = 998;
	return 0;
}
