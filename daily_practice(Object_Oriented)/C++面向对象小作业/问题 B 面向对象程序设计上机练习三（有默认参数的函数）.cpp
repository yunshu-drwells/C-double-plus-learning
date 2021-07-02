#include <iostream>
using namespace std;
void max1(int x,int y)
{
	cout<<x<<' '<<y<<' ';
	int j = x>y?x:y;
	cout<<j<<endl;
}
void max2(int x,int y,int z)
{
	cout<<x<<' '<<y<<' '<<z<<' ';
	int j = x>y?x:y;
	int k = j>z?j:z;
	cout<<k<<endl;
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	max1(a,b);
	max2(a,b,c);
	return 0;
}
