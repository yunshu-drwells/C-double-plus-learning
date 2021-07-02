#include<iostream>
using namespace std;
class Time
{
private:
	int hour,min,sec;
public:
	void gettime(int,int,int);
	int Showtime()
	{
		cout<< hour << ":" << min << ":" << sec <<endl;
	}
};
void Time::gettime(int a,int b,int c)
{
	hour = a; min = b; sec = c;
}
int main()
{
	int j,k,l;
	Time frozentime;
	cin >> j >> k >> l;
	frozentime.gettime(j,k,l);
	frozentime.Showtime();
	return 0;
}
