#include<iostream>
using namespace std;
class A
{
	public:
		int x;int y;
		A(int m,int n){
			x = m;
			y = n;
		}
	void show1(){cout<<x<<" "<<endl;} 
	void show2() const {cout<<y<<" "<<endl;	
	}	
};
int main ()
{
	const A a(1,2); //常对象在定义时必须初始化 
	A const b(1,2);
//	a.x = 12; 常对象成员在生存周期内不能被改变 
//	a.show1();常对象不呢调用不同函数，只能调用常成员函数 
	a.show2();
	return 0 ;
}
