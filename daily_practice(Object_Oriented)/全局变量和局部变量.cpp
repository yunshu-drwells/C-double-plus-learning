#include <iostream>
using namespace std;
int number = 0; //全局变量在程序运行的过程中始终存在（生命周期永恒）从main开始到main结束
				//在各个函数中均能被访问
void increase(int n)
{
	number += n;
	//number2 -= n;  //局部变量对其它函数不可见
}
void decrease(int n)
{
	number -= n;
}
int main()
{
	//cout<<n<<endl;  //局部变量进入函数时生效，退出时失效（生命周期很短）仅在本函数内可以被访问
	int number2 = 100;
	number = 10;
	increase(1);
	cout<<number<<endl;
	decrease(2);
	cout<<number<<endl;
	cout<<number2<<endl;
	return 0;
}