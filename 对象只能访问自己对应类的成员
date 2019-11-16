#include <iostream>
#include <time.h>
using namespace std;
// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃

class Date
{
public :
void Display ()
{
cout << _year << "-" << _month << "-" << _day << endl;
}
void SetDate(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	Date* p = NULL;
	p->PrintA();
	p->Show();
}
