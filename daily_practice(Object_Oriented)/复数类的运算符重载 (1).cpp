#include<iostream>
using namespace std;
//double a[2]={3.2,8.9};
//double b[2]={4.5,5.6};
//int i = 1;

class plural
{
public:
	double i;
	double j;
		
public:
	plural()
	{
	}
	plural(double x,double y):i(x),j(y)
	{
	}
	plural operator + (const plural& p)
	{
		plural result;
	    result.i = i+p.i;
		result.j = j+p.j;
		return result;
		}
		plural operator - (const plural& p)
	{
		plural result;
	    result.i = i-p.i;
		result.j = j-p.j;
		return result;
		}
};
int main()
{
	double i = 3.2,j = 4.5,k = 8.9,l = 5.6;
	plural a(i,j);
	plural b(k,l);
	plural c = a + b;
	plural d = a - b;
	cout<<"a="<<a.i<<"+"<<a.j<<"i"<<endl;
	cout<<"b="<<b.i<<"+"<<b.j<<"i"<<endl;
	cout<<"a+b="<<c.i<<"+"<<c.j<<"i"<<endl;
	cout<<"a-b="<<d.i<<d.j<<"i"<<endl;
	return 0;
}
	
	
	
	