#include<iostream>
using namespace std;
class Point
{
	int x,y;
public:
	Point(int a,int b)
	{
		x = a;
		y = b;
		cout<<"Point"<<endl;
		cout<<"the centre point"<<"("<<gets()<<","<<gety()<<")"<<endl;
	}
	int gets()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};
class Circle : public Point
{
	int r;
public:
	Circle(int a,int b,int c):Point(a,b)
	{
		r = c;
		cout<<"Circle"<<endl;
		cout<<"r = "<<r<<"  area = "<<area()<<endl;
	}
	double area()
	{
		return 3.14*r*r;
	}
};
class Cylinder : public Circle
{
	int h;
public:Cylinder(int a,int b,int c,int d):Circle(a,b,c)
	{
		h = d;
		cout<<"Cylinder"<<endl;
		cout<<"Cylinder's height = "<<h<<endl;
		cout<<"Cylinder's volume = "<<volume()<<endl;	
	}
	double volume()
	{
		return area()*h;
	}

};
int main()
{
	Cylinder cy(1,2,3,4);
}
