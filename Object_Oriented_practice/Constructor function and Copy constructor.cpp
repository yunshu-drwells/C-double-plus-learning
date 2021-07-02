#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Test
{
public:
	Test(int d = 0) : m_data(d)
	{
		cout << "Create Test Object : " << this << endl;
	}
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	Test& operator=(const Test& t)
	{
		cout << "Assign:" << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

void fun(Test x)
{
	int value = x.GetData();
}

int main()
{
	Test t(10);  //构造
	fun(t);  //拷贝构造
	return 0;
}




/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{
		cout << "Create Test Object : " << this << endl;
	}
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	Test& operator=(const Test& t)
	{
		cout << "Assign:" << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

Test fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}
int main()
{
	Test t(10);    //构造
	Test t1;    //构造
	t1 = fun(t);    //拷贝构造，构造， 拷贝构造
	return 0;
}
*/
