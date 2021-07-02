#include<iostream>
using namespace std;
class A
{
	int id;
public:
	A(int i)
	{
		id = i;
		cout<<id<<"--->"<<"构造函数 "<<endl;
//		cout<<&id<<endl; 
	 } 
	~A()
	{
		cout<<id<<"--->"<<"析构函数"<<endl;    //先进后出 
//		cout<<&id<<endl;
	}
};
int main()
{
	A a(1),b(2);
	cout<<"end of main"<<endl;
	return 0 ;
}
