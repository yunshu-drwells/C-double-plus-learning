#include<iostream>
using namespace std;

//不允许改动程序其它地方。
//在此处添加重载函数，使得程序按要求正常输出。 
int max(int x,int y)
{
	cout<<"int compare ";
	return x>y?x:y;
}
double max(double x,double y)
{
	cout<<"double compare ";
	return x>y?x:y;
}
int main()
{
cout<<max(4,5)<<endl;
cout<<max(45.23,2.3)<<endl;
    return 0;
}
