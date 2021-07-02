#include<iostream>
using namespace std;
class Max
{
	int a,b,c;
public:
	void seta (int e)
	{
		a = e;
	}
	void setb (int f)
	{
		b = f;
	}
	void setc (int g)
	{
		c = g;
	}
	int getnumber()
	{
		cin>> a >> b >> c; 
	}
	int getmax()
	{
		return a?b:c;
	}
	
};
int main()
{
	Max max;
	max.getnumber();
	cout<< max.getmax() <<endl;
	return 0;
}
