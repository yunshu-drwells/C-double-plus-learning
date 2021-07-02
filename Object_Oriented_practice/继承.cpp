#include<iostream>
using namespace std;
class A{
	public:A(){cout << "A 构造" << endl;}
	~A(){cout << "A 析构" <<endl;}
	
	
};
class Point{
	int x,y;
	public: Point(int a,int b)
	{x=a;y=b;cout << "Point 构造"<<endl;}
	~Point(){cout << "Point 析构"<<endl;}
	
	
};
class Circle : public Point{
	A a;int r;
	public: Circle(int a,int b,int c):Point(a,b)
	{r=c;cout<<"Circle 构造"<<endl;}
	~Circle(){cout << "Circle 析构"<<endl;}
	
	
};
int main (){Circle ci(1,2,3);}

