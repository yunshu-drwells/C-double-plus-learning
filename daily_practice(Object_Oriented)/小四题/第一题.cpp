#include<iostream>
using namespace std;
class Rect
{
private:
	double Length;
	double Width;
public:
	Rect():Length(0), Width(0){};
	Rect(const Rect &);
	Rect(double ,double );
	void show1()
{
	cout<<"the length and width of r1 "<<"is:"<<this->Length<<","<<this->Width<<endl;
	cout<<"the perimeter of r1 is:"<<2*(this->Length+this->Width)<<endl;
	cout<<"the area of r1 is:"<<this->Length*this->Width<<endl;
}
	void show2()
{
	cout<<"the length and width of r2 "<<"is:"<<this->Length<<","<<this->Width<<endl;
	cout<<"the perimeter of r1 is:"<<2*(this->Length+this->Width)<<endl;
	cout<<"the area of r1 is:"<<this->Length*this->Width<<endl;
}
};
Rect::Rect(double l,double w)
	{
		Length = l;
		Width = w;
	};
Rect::Rect(const Rect &r3)
{
	this->Length = r3.Length;
	this->Width = r3.Width;
};

int main()
{
	double i;
	double j;
	cin>>i>>j;
	if(i <= 0|| j <= 0) 
	{
		i = 0;
		j = 0;
	}
	Rect r1(i,j);
	Rect r2(r1);
	r1.show1();
	r2.show2();
	return 0;
}
