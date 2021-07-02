#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"Constructing an object of A"<<endl;
		cout<<"Constructing an object of A"<<endl;	
	}

	~A()
	{
		cout<<"Destructing an object of A"<<endl;
		cout<<"Destructing an object of A"<<endl; 
	}
}; 
int main()
{
	A a;
	return 0;
}
