#include<iostream>
using namespace std;
class A
{
public:
	const int x,y;
//	A(int m,int n){
//		x = m;y = n;
//	} 常数据成员是不能改变的。
//只能通过构造函数的参数初始化列表对常数据成员进
//行初始化
	A(int m,int n):x(m),y(n){ 
	} 
};
int main()
{
		
	return 0;
}

