//#pragma warning (disable:0020)
//#include <iostream>
//#include <time.h>
//using namespace std;
//// 1.下面程序能编译通过吗？
//// 2.下面程序会崩溃吗？在哪里崩溃
//
//class Date
//{
//public :
//void Display ()
//{
//cout << _year << "-" << _month << "-" << _day << endl;
//}
//void SetDate(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	Date* p = NULL;
//	p->PrintA();
//	p->Show();
//}


//#include <iostream>
//#include <time.h>
//using namespace std;
//
//class Test;
//ostream& operator<<(ostream& out, const Test& t);
//
//class Test
//{
//	//友元
//	friend ostream& operator<<(ostream& out, const Test& t);
//public:
//	Test(int d = 0) : m_data(d)
//	{
//		cout << "Create Test Object : " << this << endl;
//	}
//	//Test t1 = t;
//	Test(const Test& t)
//	{
//		cout << "Copy Create Test Object : " << this << endl;
//		m_data = t.m_data;
//	}
//	//=重载 运算符的重载
//	Test& operator=(const Test& t)
//	{
//		cout << "Assign: " << this << " = " << &t << endl;
//		if (this != &t)
//		{
//			m_data = t.m_data;
//		}
//		return *this;
//	}
//	~Test()
//	{
//		cout << "Free Test Object : " << this << endl;
//	}
//public:
//	int GetData()const
//	{
//		return m_data;
//	}
//	int SetData(int data)
//	{
//		m_data = data;
//	}
//private:
//	int m_data;
//};
//
//Test fun(Test t)
//{
//	int value = t.GetData();
//	Test tmp(value);
//	return tmp;
//}
//
//ostream& operator<<(ostream& out, const Test& t)
//{
//	out << t.m_data;
//	return out;
//}
//
//int main()
//{
//	Test t1(100);
//	Test t2, t3;
//	t2 = t1; //t3.operator=( t2.operator=(t1) )
//			 //t2.operator=(t1); //
//
//	cout << "t1 = " << t1 << endl;
//
//	return 0;
//}



/*
//输出流函数重载------>输出流函数重载为成员方法
#include <iostream>
using namespace std;
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{cout << "Create Test Object : " << this << endl;}
	//Test t1 = t;
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//=重载 运算符的重载
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{cout << "Free Test Object : " << this << endl;	}
public:
	int GetData()const
	{return m_data;}
	int SetData(int data)
	{m_data = data;	}
	ostream& operator<<(ostream& os)   //输出流函数重载为成员方法
	{
		os << m_data;
		return os;
	}
private:
	int m_data;
};

Test fun(Test t)
{
	cout<<"fun : " << endl;
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

int main()
{
	Test t1(100);
	Test t2, t3;
	t2 = t1; //t3.operator=( t2.operator=(t1) )
			 //t2.operator=(t1); //
	Test tmp = fun(t2);
	//cout << "t1 = " << t1 << endl;
	t1 << cout;				//输出流函数重载为成员方法用对象去驱动
	t1 << cout << endl;     //输出流函数重载为成员方法用对象去驱动
	return 0;
}
*/



/*
//输出流重载为全局函数
#include <iostream>
using namespace std;
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{cout << "Create Test Object : " << this << endl;}
	//Test t1 = t;
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//=重载 运算符的重载
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{cout << "Free Test Object : " << this << endl;}
public:
	int GetData()const
	{return m_data;}
	int SetData(int data)
	{m_data = data;}
private:
	int m_data;
};

Test fun(Test t)
{
	cout << "fun : " << endl;
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

ostream& operator<<(ostream& os, const Test& t)   //输出流函数重载为全局方法
{
	os << t.m_data;     //全局函数也无法满足要求，全局函数无法访问类的私有数据成员
	return os;
}

int main()
{
	Test t1(100);
	Test t2, t3;
	t2 = t1; //t3.operator=( t2.operator=(t1) )
			 //t2.operator=(t1); //
	Test tmp = fun(t2);
	//cout << "t1 = " << t1 << endl;
	cout << t1;
	return 0;
}
*/



/*
//输出流重载友元函数
#include <iostream>
using namespace std;
class Test
{
	//输出流重载友元函数
	friend ostream& operator<<(ostream& out, const Test& t);
public:
	Test(int d = 0) : m_data(d)
	{cout << "Create Test Object : " << this << endl;}
	//Test t1 = t;
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//=重载 运算符的重载
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{cout << "Free Test Object : " << this << endl;}
public:
	int GetData()const
	{return m_data;}
	int SetData(int data)
	{m_data = data;}
private:
	int m_data;
};

Test fun(Test t)
{
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

ostream& operator<<(ostream& out, const Test& t)		//输出流重载友元函数
{
	out << t.m_data;
	return out;
}

int main()
{
	Test t1(100);
	Test t2, t3;
	t2 = t1; //t3.operator=( t2.operator=(t1) )
			 //t2.operator=(t1); //

	cout << "t1 = " << t1 << endl;
	cout << t1;
	cout << t1 << endl;
	return 0;
}
*/



/*
//输出流重载友元函数-----省略返回值后
#include <iostream>
using namespace std;
class Test
{
	//输出流重载友元函数
	friend void operator<<(ostream& out, const Test& t);
public:
	Test(int d = 0) : m_data(d)
	{
		cout << "Create Test Object : " << this << endl;
	}
	//Test t1 = t;
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//=重载 运算符的重载
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << " = " << &t << endl;
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
	int SetData(int data)
	{
		m_data = data;
	}
private:
	int m_data;
};

Test fun(Test t)
{
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

void operator<<(ostream& out, const Test& t)		//输出流重载友元函数
{
	out << t.m_data;
}

int main()
{
	Test t1(100);
	Test t2, t3;
	t2 = t1; //t3.operator=( t2.operator=(t1) )
			 //t2.operator=(t1); //

	cout << t1;  //只能以这种方式驱动
	//cout << t1 << endl;
	//cout << "t1 = " << t1 << endl;
	return 0;
}
*/


/*
//string类模拟实现
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
	String()
	{
		//m_data = (char*)malloc(1);    //string类型变量的默认初始值是为null,所以不开辟空间也无可厚非
	}
	String(const char* str)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(m_data, str);
	}

	String(const String& s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
		if (m_data != nullptr)
			strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this == &s)
			return *this;

		free(m_data);

		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
		strcpy(m_data, s.m_data);

		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char* m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
*/




/*
//string类模拟实现--构造函数改进1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char *str = nullptr)
	{
		if(str == nullptr)
		{
			m_data = (char*)malloc(sizeof(char));
			m_data[0] = '\0';
		}
		else
		{
			m_data = (char *)malloc(sizeof(char)*(strlen(str)+1));
			strcpy(m_data, str);
		}
	}

	String(const String &s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data)+1));
		if (m_data != nullptr)
			strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this == &s)
			return *this;

		free(m_data);

		m_data = (char*)malloc(sizeof(char)*(strlen(s.m_data)+1));
		strcpy(m_data, s.m_data);

		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char *m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
*/




/*
//string类模拟实现--构造函数改进2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char *str = "")    //设默认值
	{
		m_data = (char *)malloc(sizeof(char)*(strlen(str)+1));
		if (m_data != nullptr)
			strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data)+1));
		if (m_data != nullptr)
			strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			free(m_data);
			m_data = (char*)malloc(sizeof(char)*(strlen(s.m_data) + 1));
			if (m_data != nullptr)
				strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char *m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
*/




/*/
//string类模拟实现--构造函数改进3(使用C++中的new和delete进行动态内存管理)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String& s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			free(m_data);
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete[]m_data;
		m_data = NULL;
	}
private:
	char* m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
*/




/*
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
*/






//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<assert.h>
//#include<string.h>
//using namespace std;
//
///////////////////////////////////////////
////length()
////operator[]
////operator+
////operator+=
////operator > < >= <= == !=
///////////////////////////////////////////
//class String
//{
//public:
//	String(const char* str = "")   //常类型到常类型
//	{
//		m_data = new char[strlen(str) + 1];
//		strcpy(m_data, str);
//	}
//	String(const String& s)
//	{
//		m_data = new char[strlen(s.m_data) + 1];
//		strcpy(m_data, s.m_data);
//	}
//	~String()
//	{
//		delete[]m_data;
//		m_data = NULL;
//	}
//public:
//	int length()
//	{
//		return strlen(m_data);
//	}
//
//	char operator[](int i)
//	{
//		assert(i >= 0 && i < length());
//		return m_data[i];
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			delete[](this->m_data);
//			this->m_data = new char[strlen(s.m_data) + 1];
//			strcpy(this->m_data, s.m_data);
//		}
//		return *this;
//	}
//
//
//	//String operator+(const String& s)
//	//{
//	//	char* tmp = (char*)malloc(strlen(m_data) + 1);
//	//	if(tmp != NULL)
//	//		strcpy(tmp, m_data);
//	//	(void)realloc(tmp, (strlen(m_data) + strlen(s.m_data) + 1));
//	//	if (tmp != NULL)
//	//		strcat(tmp, s.m_data);
//	//	 String temp(tmp);    //*****功能实现正确*****但未释放tmp*****
//	//	 return temp;
//	//}
//
//
//	String operator+(const String& s)
//	{
//		char* tmp = new char[strlen(this->m_data) + strlen(s.m_data) + 1];
//		strcpy(tmp, this->m_data);
//		strcat(tmp, s.m_data);
//
//		String temp(tmp);
//		delete []tmp;
//		return temp;
//	}
//
//	//String& operator+=(const String& s)
//	//{
//	//	this->m_data = (char*)realloc(this->m_data, (strlen(m_data) + strlen(s.m_data) + 1));
//	//	if (this->m_data != nullptr)
//	//		strcat(this->m_data, s.m_data);
//	//	return *this;
//	//}
//
//	String& operator+=(const String& s)
//	{
//		char* tmp = new char[strlen(this->m_data) + strlen(s.m_data) + 1];
//		strcpy(tmp, this->m_data);
//		strcat(tmp, s.m_data);
//
//		delete [](this->m_data);
//		this->m_data = tmp;
//		return *this;
//	}
//
//public:
//	bool operator==(const String& s)
//	{
//		if (strcmp(this->m_data, s.m_data) == 0)
//			return true;
//		return false;
//	}
//	bool operator!=(const String& s)
//	{
//		if (strcmp(this->m_data, s.m_data) != 0)
//			return true;
//		return false;
//	}
//	bool operator>(const String& s)
//	{
//		if (strcmp(this->m_data, s.m_data) > 0)
//			return true;
//		return false;
//	}
//	bool operator<(const String& s)
//	{
//		if (strcmp(this->m_data, s.m_data) < 0)
//			return true;
//		return false;
//	}
//	bool operator>=(const String& s)
//	{
//		if (strcmp(this->m_data, s.m_data) < 0)
//			return false;
//		return true;
//	}
//	bool operator<=(const String& s)
//	{
//		if (strcmp(this->m_data, s.m_data) > 0)
//			return false;
//		return true;
//	}
//private:
//	char* m_data;
//};
//
//int main()
//{
//	String s1("Hello"); //s1[0] ==> H
//	String s2("Bit.");
//
//	s1 = s2;
//	for (int i = 0; i < s1.length(); ++i)
//		cout << s1[i];
//	cout << endl;
//
//
//	String s = s1 + s2; //s = HelloBit
//	for (int i = 0; i < s.length(); ++i)
//		cout << s[i];
//	cout << endl; 
//
//
//	s1 += s2;    //
//
//	for (int i = 0; i < s1.length(); ++i)
//		cout << s1[i];
//	cout << endl;
//
//
//	if (s1 == s2)
//		cout << "s1 == s2" << endl;
//	if (s1 != s2)
//		cout << "s1 != s2" << endl;
//	if (s1 > s2)
//		cout << "s1 > s2" << endl;
//	if (s1 < s2)
//		cout << "s1 < s2" << endl;
//	if (s1 >= s2)
//		cout << "s1 >= s2" << endl;
//	if (s1 <= s2)
//		cout << "s1 <= s2" << endl;
//	return 0;
//}









/*

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
	//t1.m_data;
	//cout<<"m_count = "<<Test::m_count<<endl;
	//{
	//	Test t2;
	//	//cout<<"m_count = "<<Test::m_count<<endl;
	//}
	//cout<<"m_count = "<<Test::m_count<<endl;
	return 0;
}

*/




















/*
//下面的程序定义了一个简单的SmallInt类，
//用来表示从-128到127之间的整数。
//类的唯一的数据成员val存放一个-128到127
//（包含-128和127这两个数）之间的整数，为了方便，
//类SmallInt还重载了一些运算符。
//阅读SmallInt的定义，回答题目后面的问题。
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class SmallInt;
ostream& operator<<(ostream& os, const SmallInt& si);
istream& operator>>(istream& is, SmallInt& si);

//SmallInt si(1000);

class SmallInt
{
public:
	SmallInt(int i = 0);
	//重载插入和抽取运算符
	friend ostream& operator<<(ostream& os, const SmallInt& si);
	friend istream& operator>>(istream& is, SmallInt& si);

	//重载算术运算符
	SmallInt operator+(const SmallInt& si) { return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt& si) { return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt& si) { return SmallInt(val * si.val); }
	SmallInt operator/(const SmallInt& si) { return SmallInt(val / si.val); }
	//重载比较运算符
	bool operator==(const SmallInt& si) { return (val == si.val); }
private:
	char val;
};
SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}

ostream& operator<<(ostream& os, const SmallInt& si)
{
	os << (int)si.val;
	return os;
}

istream& operator>>(istream& is, SmallInt& si)
{
	int tmp;
	is >> tmp;
	si = SmallInt(tmp);
	return is;
}
//问题1：（本小题4分）上面的类定义中，
//重载的插入运算符和抽取运算符被定义为类的友元函数，
//能不能将这两个运算符定义为类的成员函数？//不能
//如果能，写出函数原型，如果不能，说明理由。

int  main()
{
	SmallInt si(1000);
	cout << si << endl;
	SmallInt si1;
	cin >> si1;
	cout << si1 << endl; 
	return 0;
}
*/
///////////////////////////////////////语法上可以，语义上不可以
/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//SmallInt si(1000);

class SmallInt
{
public:
	SmallInt(int i = 0);
	//重载插入和抽取运算符
	ostream& operator<<(ostream& os)
	{
		os << (int)this->val;
		return os;
	}
	istream& operator>>(istream& is)
	{
		int tmp;
		is >> tmp;
		this->val = tmp;
		return is;
	}

	//重载算术运算符
	SmallInt operator+(const SmallInt& si) { return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt& si) { return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt& si) { return SmallInt(val * si.val); }
	SmallInt operator/(const SmallInt& si) { return SmallInt(val / si.val); }
	//重载比较运算符
	bool operator==(const SmallInt& si) { return (val == si.val); }
private:
	char val;
};
SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}
int  main()
{
	SmallInt si(1000);
	si << cout << endl;
	SmallInt si1;
	si1 >> cin;
	si1 << cout << endl;
	return 0;
}
*/




/*
//双向链表
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class List;

class ListNode
{
	friend class List;
public:
	ListNode(int data=0) : m_data(data), next(nullptr)
	{}
	ListNode(int data, ListNode *n)
		: m_data(data), next(n)
	{}
	~ListNode()
	{}
public:
	ListNode*& GetNext()
	{
		return next;
	}
private:
	int m_data;
	ListNode *next;
};

class List
{
public:
	List()
	{
		first = last = new ListNode;
		size = 0;
	}
	~List()
	{}
public:
	void push_back(int x)
	{
		ListNode *s = new ListNode(x);
		last->next = s;
		last = s;
		size++;
	}
	void push_front(int x)
	{
		ListNode *s = new ListNode(x);
		s->next = first->next;
		first->next = s;
		size++;
	}
private:
	ListNode *first;
	ListNode *last;
	size_t    size;
};

int main()
{
	List mylist;
	mylist.push_back(1);
	return 0;
}
*/








/*
//哑成员
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	Test(int d = 0) :m_data(d)
	{}
public:
	class Tmp //内部类
	{
	public:
		Tmp(int a , int b) : x(a), y(b)
		{}
	public:
		int GetX()
		{return x;}
	public:
		int x;  //哑成员
		int y;  //哑成员
	};
public:
	int m_data;
};
int main()
{
	Test T;
	cout <<"sizeof(T) = "<< sizeof(T) << endl;
	Test::Tmp tp(1,2);
	cout<<"sizeof(tp) = "<<sizeof(tp) << endl;
	return 0;
}
*/



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
*/



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
	return Test(value); //临时对象的语法
}
int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);
	return 0;
}
*/

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

Test& fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}

int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);
	cout << t1.GetData() << endl;
	return 0;
}
*/


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


Test& fun(Test& x)
{
	return x;
}
int main()
{
	Test t(10);
	Test t1;
	t1 = fun(t);  //对象赋值
	cout << t1.GetData() << endl;
	return 0;
}
*/


/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Complex
{
	friend ostream& operator<<(ostream& out, const Complex& c);
public:
	Complex(int real, int imag) : m_real(real), m_imag(imag)
	{}
	~Complex()
	{}
public:
	Complex operator+(const Complex& c);
private:
	int m_real;
	int m_imag;
};

ostream& operator<<(ostream& out, const Complex& c)
{
	out << "(" << c.m_real << "," << c.m_imag << ")";
	return out;
}
Complex Complex::operator+(const Complex& c)
{
	return Complex(m_real + c.m_real, m_imag + c.m_imag);
}

int main()
{
	Complex c1(1, 2), c2(2, 3);
	Complex c = c1 + c2;
	cout << "c = " << c << endl;
	return 0;
}
*/




/*
//new的底层模拟实现
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
	void TestInit(int d = 0)
	{
		m_data = d;
	}
	void TestDestroy()
	{
		m_data = 0;
	}
public:
	int GetData()const
	{
		return m_data;
	}
public:
	void* operator new(size_t sz) //1
	{
		void* ptr = malloc(sz);
		return ptr;
	}
	void operator delete(void* ptr)
	{
		free(ptr);
	}
private:
	int m_data;
};

void* operator new(size_t sz) //1
{
	void* ptr = malloc(sz);
	return ptr;
}
void operator delete(void* ptr)
{
	free(ptr);
}

void* operator new[](size_t sz) //1
{
	void* ptr = malloc(sz);
	return ptr;
}
void operator delete[](void* ptr)
{
	free(ptr);
}

int main()
{
	//operator new 
	Test* pt = new Test(10);//1 2   //操作符new
	delete pt;              //1 2
	//Test *pt = (Test*)operator new(sizeof(Test)); //申请空间malloc

	Test* pt1 = new Test[10];//40
	return 0;
}
*/





/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//定位new
void* operator new(size_t sz, int* ptr, int pos)   //操作符new
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
*/


/*
//实现类的对象只能在堆上开辟， 禁止拷贝构造和对象赋值
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
	friend Test* CreateTestObject(int data);
public:
	static Test* CreateObject(int data)
	{
		return new Test(data);
	}
private:
	Test(int d = 0)
	{
		m_data = d;
	}
protected: //继承中才体现价值
	//Test(const Test &);//拷贝构造方法受保护
	//Test& operator=(const Test &);  //赋值运算符重载方法受保护
	Test(const Test&) = delete;//拷贝构造方法受保护
	Test& operator=(const Test&) = delete;  //赋值运算符重载方法受保护
private:
	int m_data;
};

Test* CreateTestObject(int data)
{
	return new Test(data);
}

int main()
{
	//Test t(1);
	//Test t1(t);
	//Test t2;
	//t2 = t;
	Test* pt1 = Test::CreateObject(1);
	Test* pt2 = CreateTestObject(1);
	//*pt1 = *pt2;  //Test::operator =”: 无法访问 protected 成员
	return 0;
}
*/



/*
//开辟4G的内存  4*4294967296位 = 4*536870912字节
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int* q = (int*)malloc(sizeof(int) * 536870912);  //4*536870912字节
	if (NULL == q)
	{
		cout << "malloc:Out Of Memory." << endl;
		exit(1);
	}
	int* p = new int[10];
	if (p == NULL)
	{
		cout << "new:Out Of Memory." << endl;
		exit(1);
	}
	delete[]p;
	return 0;
}
*/



/*
//set_new_handler
//0 尽可能 满足 需求
//1 申请成功 直接返回
//2 申请不成功，设置了set_new_handler方法，有可能成功返回
//3 内存确实不足，抛出异常
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void Out_Of_Memory()
{
	cout << "new:Out Of Memory." << endl;
	//执行内存回收
	exit(1);
}

int main()
{
	set_new_handler(Out_Of_Memory);
	int* p = new int[536870911];//  new
	//int *p = new int[5];
	delete[]p;
	return 0;
}
*/






/*
//函数模板  //泛型
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class Type1, class Type2>
Type1 Max(Type1 a, Type2 b)
{
	return a > b ? a : b;
}

int main()
{
	cout << Max(1, 1.2) << endl;  //char
	return 0;
}
*/


/*
//效率不高， 所以需要特化
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<typename Type1, typename Type2>
Type1 Max(Type1 a, Type2 b)
{
	return a > b ? a : b;
}
double Max(int a, double b)   //模板函数的特化
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max(1, 1.2)<<endl;
	cout<<Max<double>(1, 1.2) << endl;
	cout << Max(1, 1.2) << endl;
}
*/



/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<typename Type1, typename Type2>
Type1 Max(Type1 a, Type2 b)
{
	return a > b ? a : b;
}
void main()
{
	cout<<Max('A', 'B')<<endl;  //char
	cout<<Max(10,20)<<endl;     //int
	cout<<Max(12.34,23.45)<<endl; //double
	cout<<Max((double)1,2.3)<<endl;
	cout<<Max(1,(int)2.3)<<endl;
	cout<<Max<int>(1, 2)<<endl;
}
*/



/*
//类模板
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<typename Type>
class Stack
{
public:
	Stack(size_t sz = STACK_DEFAULT_SIZE)
	{
		capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
		base = new Type[capacity];
		top = 0;
	}
	~Stack()
	{
		delete[]base;
		capacity = top = 0;
	}
public:
	void push(const Type& x)
	{base[top] = x;}
	void pop()
	{top--;}
	Type Top()const
	{return base[top];}
	Type& Top()
	{return& base[top];}
public:
	bool empty()const
	{return top == 0;}
	bool full()const
	{return top == capacity;}
private:
	enum { STACK_DEFAULT_SIZE = 20 };
	Type* base;
	size_t capacity;
	size_t top;
};

int main()
{
	Stack<int> Int_st;
	return 0;
}
*/


/*
//string的模拟实现
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream& out, const string& s);
	public:
		string(const char* str = "") //nullptr
		{
			m_size = strlen(str);
			m_capacity = m_size; //
			m_str = new char[m_capacity + 1]; //
			strcpy(m_str, str);
		}
		string(const string& s) :m_str(nullptr), m_capacity(0), m_size(0)
		{
			string tmp(s.m_str);  //拷贝构造函数调用构造函数，类的构造函数具有类型转换的功能，能够构造tmp
			Swap(tmp); //*this  tmp  深拷贝（被拷贝的对象先拷贝到一个临时对象tmp中，
			//tmp是一个栈上的临时对象但它拥有的数据成员在堆上，
			//	于是将tmp和this指针代表的要被拷贝进去的对象的数据成员进行交换,
			//	出swap函数的同时临时变量tmp也就被释放，同时原先要拷贝进去的数据成员也就非释放了)
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);  //调用拷贝构造函数用对象s构造对象tmp
				Swap(tmp);  //然后调用Swap函数进行深拷贝
			}
			return *this;
		}
		~string()
		{
			if (m_str)
			{
				delete[]m_str;
				m_str = nullptr;
				m_capacity = m_size = 0;
			}
		}
	public:
		typedef char* iterator; //迭代器  在string中迭代器是原生指针
		typedef const char* const_iterator; //
	public:
		iterator begin()
		{return m_str;}
		iterator end()  //end永远迭代字符串最后一个元素的下一个位置
		{return m_str + m_size;}
		const_iterator begin()const
		{return m_str;}
		const_iterator end()const
		{return m_str + m_size;}
	public:
		size_t size()const
		{return m_size;};
		size_t capacity()const
		{return m_capacity;}
	public:
		void push_back(char ch)
		{
			if (m_size >= m_capacity)
			{
				int new_capacity = (m_capacity == 0 ? 1 : m_capacity * 2);
				reserve(new_capacity);
			}
			m_str[m_size++] = ch;
			m_str[m_size] = '\0';
		}
		void clear()
		{
			m_size = 0;
			m_str[0] = '\0';
		}
		const char* c_str()const
		{
			return m_str;
		}
	public:
		char operator[](size_t i) //-1
		{
			assert(i < m_size); //15 14
			return m_str[i];
		}
		const char operator[](size_t i)const //-1
		{
			assert(i < m_size); //15 14
			return m_str[i];
		}
	public:
		//abcdefghij00000
		void resize(size_t new_sz, char c = '\0')
		{
			if (new_sz > m_size)
			{
				if (new_sz > m_capacity)
				{
					reserve(new_sz); //	
				}
				memset(m_str + m_size, c, new_sz - m_size);  //memset的三个参数，1内存中的起始地址，2要被修改的值，3修改的个数
			}
			m_str[new_sz] = '\0';
			m_size = new_sz;
		}
		void reserve(size_t new_capacity)
		{
			if (new_capacity > m_capacity)
			{
				char* new_str = new char[new_capacity + 1];
				m_capacity = new_capacity;
				strcpy(new_str, m_str);
				delete[]m_str;
				m_str = new_str;
			}
		}
		void Swap(string& s)
		{
			swap(m_str, s.m_str);
			swap(m_capacity, s.m_capacity);
			swap(m_size, s.m_size);
		}
	private:
		char* m_str;
		size_t m_capacity;
		size_t m_size;
	};

};

ostream& bit::operator<<(ostream& out, const string& s)
{
	out << s.m_str;
	return out;
}

int main()
{
	bit::string s("Hello Bit.");
	bit::string s1;
	s1 = s;

	for (size_t i = 0; i < s1.size(); ++i)
		cout << s1[i];
	cout << endl;
	return 0;
}
*/


/*
void main()
{
	bit::string s("Hello Bit.");
	char *str = (char*)s.c_str();
	*str = 'h';
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s;
	s.push_back('a');
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;  //1 a\0
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s("Hello Bit.");
	cout<<"s = "<<s<<endl;
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;

	//bit::string::iterator it = s.begin(); //
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s("Hello Bit.");
	cout<<"s = "<<s<<endl;
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;

	//bit::string::iterator it = s.begin(); //
	bit::string::const_iterator it = s.begin(); //const char* it
	while(it != s.end())
	{
		cout<<*it;
		it++;
	}
	cout<<endl;
}

/*
void main()
{
	bit::string s("Bit.");
	cout<<"s = "<<s<<endl;
	cout<<"size = "<<s.size()<<endl;
	cout<<"capacity = "<<s.capacity()<<endl;

	s.reserve(20);
	cout<<"s = "<<s<<endl;  //Bit.
	cout<<"size = "<<s.size()<<endl; //4
	cout<<"capacity = "<<s.capacity()<<endl; //20

	s.resize(30,'a');
	cout<<"s = "<<s<<endl;  //Bit.
	cout<<"size = "<<s.size()<<endl; //4
	cout<<"capacity = "<<s.capacity()<<endl; //30

	s.resize(2,'a');
	cout<<"s = "<<s<<endl;  //Bi
	cout<<"size = "<<s.size()<<endl; //2
	cout<<"capacity = "<<s.capacity()<<endl; //30
}
*/





/*
//vector的模拟实现
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

namespace bit
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;  //vector中迭代器是原生指针
		typedef const T* const_iterator;
	public:
		iterator begin()
		{return start;}
		iterator end()
		{return finish;}
	public:
		vector() :start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{}
		~vector()
		{
			delete[]start;
			start = finish = end_of_storage = nullptr;
		}
	public:
		size_t size()const
		{return finish - start;	}  //两个指针相减得到的是指针区间上的元素个数
		size_t capacity()const
		{return end_of_storage - start;	}
	public:
		T& operator[](size_t i)
		{
			assert(i < size());
			return start[i];
		}
		void push_back(const T& value)
		{
			insert(end(), value);
		}
	public:
		iterator insert(iterator pos, const T& x)
		{
			if (size() == capacity())
			{
				int new_capacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(new_capacity);
			}

			iterator p = finish;
			if (pos == nullptr)
				* finish = x;
			else
			{
				while (p != pos)
				{
					*p = *(p - 1);
					p--;
				}
				*pos = x;
			}
			finish++;
			return pos;
		}
	public:
		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				finish = start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}

			iterator p = finish;
			finish = finish + n - size();
			while (p != finish)
			{
				*p = value;
				p++;
			}

			//int len = n - size();
			//for(int i=0; i<len; ++i)
			//{
			//	*finish++ = value; 
			//}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				int old_size = size();
				for (int i = 0; i < old_size; ++i)
				{
					tmp[i] = start[i];
				}
				delete[]start;
				start = tmp;
				finish = start + old_size;
				end_of_storage = start + n;
			}
		}
	public:
		iterator start;  //vector元素的起始位置
		iterator finish;  //真实存储的元素结尾
		iterator end_of_storage;  //vector真实容量
	};
};



int main()
{
	bit::vector<int> v;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.push_back(1);
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
*/



/*
int main()
{
	bit::vector<int> v;
	v.reserve(10);

	v.insert(v.begin(), 5);
	v.insert(v.begin(), 4);
	v.insert(v.begin(), 3);
	v.push_back(2);
	v.push_back(1);

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

/*
int main()
{
	bit::vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	v.reserve(10);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	v.resize(15, 1);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	for(int i=0; i<v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
*/

