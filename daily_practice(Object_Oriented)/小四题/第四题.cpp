#include<iostream>
using namespace std;
class Pet
{
public:
	virtual void speak()  = 0;	
};
class Dog
{
public:
	void speak()
	{
		cout<<"miao!miao!"<<endl;	
	}
};
class Cat
{
public:
	void speak()	
	{
		cout<<"wang!wang!"<<endl;	
	}
};
int main()
{
	Dog dog;
	Cat cat;
	cout<<"How does a pet speak ?"<<endl;
	dog.speak();
	cat.speak();
return 0;
}






