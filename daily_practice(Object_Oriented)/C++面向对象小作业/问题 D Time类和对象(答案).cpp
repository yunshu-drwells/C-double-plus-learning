#include<iostream>
using namespace std;
class Time{
private:
int hour,minute,second;
public:
void set(int,int,int);
void print();
void add(int n);
};
void Time::set(int h,int m,int s){
this->hour=h;this->minute=m;this->second=s;
}
void Time::print(){
cout<<"时间：";
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
void Time::add(int n){
if((this->second+n)>=60)
{
this->second=(this->second+n)-60;
this->minute+=1;
}
if((this->minute)==60)
{
this->minute=(this->minute)-60;
this->hour+=1;
}
if((this->hour)==24)
{
this->hour=(this->hour)-24;
//this->hour+=1;
}
}
int main()
{
	int a,b,c;        //
	Time t1;
	cin>> a >> b >> c;//
	t1.set(a,b,c);    //()
	t1.print();
	t1.add(3);
	t1.print();
	return 0;
}
/*
--------------------- 
作者：两榜进士  
来源：CSDN 
原文：https://blog.csdn.net/clerk0324/article/details/7602751 
版权声明：本文为博主原创文章，转载请附上博文链接！*/
