#include<iostream>
using namespace std;
class A
{
	int z;
public:
	A(){cout<<"A 构造"<<endl;}
	A(int m)
	{
		z = m;
		cout<<"A constructor"<<endl;
		cout<<"z: "<<z<<endl;
	}
	
	~A(){cout<<"A 析构"<<endl;}
};
class point {
	int x;
	int y;
public:
	point(int a,int b)
{
	 x = a;
	 y = b;
	 cout<<"point 构造"<<endl;
	 cout<<"x:  y:"<<x<<"  "<<y<<endl;
}
~point (){cout<<"point 析构"<<endl;}
};
class circle : public point 
{
	A a;
	int r;
public: circle(int a,int b,int c):point (a,b),a(5)
		{
		r = c;
		cout<<"circle 构造"<<endl;
		cout<<"r:"<<r<<endl;
		}
		~circle()
		{
		cout<<"circle 析构"<<endl;
		}
};

int main()
{
	circle ci(1,2,3);
	return 0;
}