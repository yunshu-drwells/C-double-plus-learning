#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;
int main()
{
	int radius;
	double perimeter, area;
	cout << "请输入半径: ";
	cin >> radius;
	perimeter = 2 * PI * radius;
	area = PI * pow(radius, 2);
	cout << "周长是 : " << perimeter << endl;
	cout << "面积是 : " << area << endl;
	return 0;
}

