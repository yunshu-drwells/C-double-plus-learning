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
		Tmp(int a, int b) : x(a), y(b)
		{}
	public:
		int GetX()
		{
			return x;
		}
	public:
		int x;  //
		int y;  //哑成员
	};
public:
	int m_data;
};
int main()
{
	Test T;
	cout << "sizeof(T) = " << sizeof(T) << endl;
	Test::Tmp tp(1, 2);
	cout << "sizeof(tp) = " << sizeof(tp) << endl;
	return 0;
}