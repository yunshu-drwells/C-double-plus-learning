#include <iostream>
using namespace std;
int main()
{
	int a[999] ;
	cout<<"请输入一个n,程序回求得斐波那契数列的第n项和前n项之和" <<endl;
	int n;
	cin>>n;
	int  N; 
	int S = 1;
 
	a[0] = 0;
	a[1] = 1;
	for(int i = 0;i<n-2;i++)
{
	a[i+2] = a[i] + a[i+1];
	S += a[i+2];
	N = a[i+2];
}

	cout <<"第n项 = "<<N<< endl;
	cout <<"前n项和 = "<<S<< endl;
	return 0;
}
