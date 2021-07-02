#include <iostream> 
using namespace std;
int main()
{
	char c1='a', c2='b', c3='c';
	int i1=10, i2=20, i3=30;
	double d1=0.1, d2=0.2, d3=0.4;
	double a,b,c,d,e,f,g,h,i,j,k,l;
	a = c1+i2*i3/i2%i1;       
	b = i1++ +i2%i3;
	c = i2-- * ++i3;           
	d = i1>i2>i3<d1<d2<d3;
	e = (c1=i2*i3)!=(i2%i1);    
	f = d1>d2||i1==i2;
	g = c1>i1?i1:c2;         
	h = 0?1:2?0:0?3:4;
	i = i1+=i2*=i3;          
	j = i3=(i1=1,i2--);
	k = i1=(c1,c2,c3);       
	l = !i1&&i2--;

	cout<< "a = " << a<<endl;
	cout<< "b = " << b<<endl;
	cout<< "c = " << c<<endl;
	cout<< "d = " << d<<endl;
	cout<< "e = " << e<<endl;
	cout<< "f = " << f<<endl;
	cout<< "g = " << g<<endl;
	cout<< "h = " << h<<endl;
	cout<< "i = " << i<<endl;
	cout<< "j = " << j<<endl;
	cout<< "k = " << k<<endl;
	cout<< "l = " << l<<endl;
	return 0;
}
