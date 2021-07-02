#include <iostream>
using namespace std;
class A
{
public:
	void a(int d)
{
	e = d;
	if(e%2==0) cout<<"输入的数为偶数"<<endl;

}
	void b(int d)
{
	f = d;
	if(f%2!=0) cout<<"输入的数为奇数"<<endl;
}
private : int e,f;
};
int main()
{
	A m;
	int c;
	cout<<"输入一个整数:"<<endl;
	cin>>c;
	m;
	m.b(c);
	return 0;
}
