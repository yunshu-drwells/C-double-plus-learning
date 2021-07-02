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
	si1 >> cin;  //将输入输出流重载为类的成员方法,事实证明是可以的,但是其使用不符合习惯
	si1 << cout << endl;
	return 0;
}
//The output stream could be overloaded as a member function of the class.But it doesn’t meet human usage habits
