#include<iostream>
using namespace std;
class Point
{
private:
	int x,y;
public:
	void Setpoint(int a,int b)
	{
		x = a;
		y = b;
	}
	int Showpoint()
	{
		cout << "(" << x << "," << y << ")" <<endl;
	}
};
int main()
{
	Point printpoint;
	printpoint.Setpoint(10,11);
	printpoint.Showpoint();
	return 0;
}
