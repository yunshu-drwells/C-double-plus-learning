#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a+b+c<<' '<<a*b*c<<' ';
	cout<<fixed<<setprecision(2);
	cout<<(a+b+c)/3.0<<endl;
	return 0;
} 
