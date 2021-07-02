#include<iostream>
using namespace std;
class Animal{
	public:
		int legs = 4;
		void show(){
			cout<<"Animal show()"<<endl;
		}
};
class Dog : public Animal
{
	public:
		int tail = 1;
};
int main(){
	Dog d;
	cout << d.legs <<"  "<<d.tail <<endl;
	d.show();
}
