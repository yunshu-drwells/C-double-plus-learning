#include<iostream> 
#include<stdio.h>
using namespace std;

class Time
{
	private:
		int hour;
		int minute;
		int second;
		public:
			int setHour(int h)
			{
				if(h>12||h<0)
				h=12;
				return h;
			}
			int   setMinute(int m)
			{
				if(m>60||m<0)
				m=0;
				return m;
			 } 
			 int  setSecond(int s)
			 {
			 	if(s>60||s<0)
			 	s=0;
			 	return s;
			 }
			 void setTime(int h,int m,int s)
			 {
			 	hour=setHour(h);
			 	minute=setMinute(m);
			 	second=setSecond(s);
			 }
			 void showTime()
			 {
			 	printf("%02d:%02d:%02d\n",hour,minute,second);
			 }
			
};
int main()
{
	int h,m,s;
	Time T;
	cin>>h>>m>>s;
	T.setTime(h,m,s);
	T.showTime();

return 0;
}
