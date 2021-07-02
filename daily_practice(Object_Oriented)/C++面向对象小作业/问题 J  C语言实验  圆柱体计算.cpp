c#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int r,h;
	const float pai=3.1415926;
	cin>>r>>h;
	cout<<fixed<<setprecision(2);
	cout<<2*pai*r<<' '<<pai*r*r<<' '<<2*pai*r*h<<' '<<pai*r*r*h<<endl;
	return 0;
}
