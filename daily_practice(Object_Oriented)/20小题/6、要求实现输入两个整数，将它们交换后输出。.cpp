#include <iostream>
using namespace std;
int main()
{
	int a,b;   //
	int temp;
	cout << "请分别输入两个数a,b: ";
	cin >>a>>b;
	temp = a;
	a = b;
	b = temp;
	cout << "将它们交换后输出" <<"a = "<<a<<"b = "<<b<< endl;
	return 0;
}
