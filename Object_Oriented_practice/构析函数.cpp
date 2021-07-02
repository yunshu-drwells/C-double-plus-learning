#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"构造函数"<<endl;	
	}

	~A()
	{
		cout<<"构析函数"<<endl; 
	}
}; 
int main()
{
	A a;
	return 0;
}
