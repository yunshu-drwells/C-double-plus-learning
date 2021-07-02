#include<iostream>
using namespace std;
class Max
{
	int a,b,c;
public:
	int printfmaxnumber(int e,int f,int g)
	{
		a = e;
		b = f;
		c = g;
		return a?b:c;
	}	
};
int main()
{
	Max max;
	int e,f,g,h;
	cin>> e >> f >> g;
	h=max.printfmaxnumber(e,f,g);
	cout<< h <<endl;
	return 0;
}
