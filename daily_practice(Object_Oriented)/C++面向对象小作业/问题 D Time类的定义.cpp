#include<iostream>
using namespace std;
class Time
{
private:
	int hour,minute,second;
public:
	void set(int,int,int);
	void printtime();
};
void Time::set(int a,int b,int c) 
{
	hour = a;minute = b;second = c;
}
void Time::printtime()
{
	if(hour<10)
	cout<<0<<hour<<":";
	else
	cout<<hour<<":";
	
	if(minute<10)
	cout<<0<<minute<<":";
	else
	cout<<minute<<":";
	
	if(second<10)
	cout<<0<<second<<endl;
	else
	cout<<second<<endl;
}
int main()
{
	int j,k,l;
	Time frozentime;
	cin >> j >> k >> l;
	frozentime.set(j,k,l);
	frozentime.printtime();
	return 0;
}
