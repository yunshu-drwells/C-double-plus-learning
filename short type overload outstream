//短整形运算符重载
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
class Int
{
public:
	Int(long i = 0) : m_i(i)
	{}
	Int(const Int& x)
	{
		this->m_i = x.m_i;
	}
public:
	Int operator+(const Int& x)
	{
		return Int(this->m_i + x.m_i);
	}
	Int operator-(const Int& x)
	{
		return Int(this->m_i - x.m_i);
	}
	Int operator*(const Int& x)
	{
		return Int(this->m_i * x.m_i);
	}
	Int operator/(const Int& x)
	{
		return Int(this->m_i / x.m_i);
	}
	Int operator%(const Int& x)
	{
		return Int(this->m_i % x.m_i);
	}
public:
	Int& operator+=(const Int& x) // a += b;
	{
		this->m_i += x.m_i;
		return *this;
	}
	Int& operator-=(const Int& x)
	{
		this->m_i -= x.m_i;
		return *this;
	}
	Int& operator*=(const Int& x)
	{
		this->m_i *= x.m_i;
		return *this;
	}
	Int& operator/=(const Int& x)
	{
		this->m_i /= x.m_i;
		return *this;
	}
	Int& operator%=(const Int& x)
	{
		this->m_i %= x.m_i;
		return *this;
	}
public:
	Int operator>>(const Int& x) //a >> b
	{
		return Int(this->m_i >> x.m_i);
	}
	Int operator<<(const Int& x)
	{
		return Int(this->m_i << x.m_i);
	}
	Int& operator>>=(const Int& x)
	{
		this->m_i >>= x.m_i;
		return *this;
	}
	Int& operator<<=(const Int& x)
	{
		this->m_i <<= x.m_i;
		return *this;
	}
public:
	bool operator==(const Int& x)
	{
		if (this->m_i == x.m_i)
			return true;
		return false;
	}
	bool operator!=(const Int& x)
	{
		if (this->m_i != x.m_i)
			return true;
		return false;
	}
public:
	Int& operator++() //前置++    比后置++效率    可以引用返回
	{
		this->m_i++;
		return *this;
	}
	Int operator++(int)  //后置++
	{
		Int temp(*this);   //调用拷贝构造函数或：
		//Int tmp(this->m_i);  //用构造函数
		this->m_i++;      //*this++
		return temp;
	}
	Int& operator--() //前置--    比后置++效率    可以引用返回
	{
		this->m_i--;
		return *this;
	}
	Int operator--(int)  //后置--
	{
		Int Tmp(m_i);
		this->m_i--;
		return Tmp;
	}
public:
	int GetData()const
	{
		return this->m_i;
	}
private:
	long m_i;
};

int main()
{
	Int a(1);  //int a = 1;  a++  ++a  a-- --a
	Int b(2);
	Int c(3);

	cout << "a = " << a.GetData() << endl;
	cout << "b = " << b.GetData() << endl;

	Int result;
	a += b;
	result = a + b + c;
	result = a + b; //result = 1 + 2;
	cout << "result = " << result.GetData() << endl;

	result = ++a;
	result = a++;
	

	return 0;
}
