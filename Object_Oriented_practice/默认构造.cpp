#include<iostream>
using namespace std;
class A
{
	int id;
public:
	A(int i)
	{
		id = i;
		cout<<id<<"gouzao"<<id<<endl;
	}
	~A(){
		cout<<id<<"xigou"<<id<<endl;
	}
	
};
int main()
{
	A a(3);
	A b(a);
	cout<<"end of main"<<endl;
	return 0;
}


