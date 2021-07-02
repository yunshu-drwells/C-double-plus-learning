#include<iostream>
using namespace std;
int main()
{
	enum hanxin {a,b,c,d,e,f,g,h,i,j} k;
	k=b;	
	int x;
	for(int n=0;n<99;n++)
	{
		x=k+n;
		if(x%3==1&&x%5==2&&x%7==3)
		cout<<"韩信点兵的最小x是"<<x<<endl; 
	}
	return 0;
}
