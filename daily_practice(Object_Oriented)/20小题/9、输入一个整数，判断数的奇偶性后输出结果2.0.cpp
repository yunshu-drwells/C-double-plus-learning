#include <iostream>
using namespace std;
int main()
{
	int c;
	cout<<"输入一个整数:"<<endl;
	cin>>c;
	if(c%2==0) cout<<"输入的数为偶数"<<endl;
	if(c%2!=0) cout<<"输入的数为奇数"<<endl;
	return 0;
}
