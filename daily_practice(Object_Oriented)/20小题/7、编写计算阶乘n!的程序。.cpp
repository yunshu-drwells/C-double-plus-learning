#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int S = 1;
	for(int i = 0;i<n,n>0;i++)
{
	S *=n;
	n--;
}
	cout <<"n1 = "<<S<< endl;
	return 0;
}
