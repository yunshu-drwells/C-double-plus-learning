#include<iostream>
#include<math.h>
using namespace std;
double d;
class Point1
{
	friend class Point2;
private:
	double x1;
	double y1;
public:
	Point1(double i,double j)
	{
		x1 = i;
		y1 = j;
	}
	void Show1()
	{
		cout<<"The first point is the coordinate:"<<"X = "<<this->x1<<","<<"X = "<<this->y1<<endl;
	}

};
class Point2
{
	friend class Point1;
	private:
	double x2;
	double y2;
	
public:
	double d;
	Point2(double i,double j)
	{
		x2 = i;
		y2 = j;
	}
	void Show2()
	{
		cout<<"The second point is the coordinate:"<<"X = "<<this->x2<<","<<"X = "<<this->y2<<endl;
	}
	
	void distance(Point1 *p1)
	{
		int m,n;
		m = p1->x1-x2;
		n = p1->y1-y2;
		cout<<sqrt(m*m+n*n)<<endl;
	}
	
};

int main()
{
	double x1,y1;
	double x2,y2;
	cin>>x1>>y1>>x2>>y2;
	Point1 point1(x1,y1);
	Point2 point2(x2,y2);
	point1.Show1();
	point2.Show2();
	point2.distance(&point1);
return 0; 
}
 
