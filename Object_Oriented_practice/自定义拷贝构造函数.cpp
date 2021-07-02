#include<iostream>
using namespace std;
class A {
		int id;
	public:
		int j=0;//在C98中这里的公有成员变量 j会被理解为const类型 需要在编译选项中加入编译时加入命令-std=c++11 
		A(int i) {
			id = i;
			cout<<id<<"gouzao"<<id<<endl;
		}
		A(A &){
			cout<<"自定义拷贝构造函数"<<endl; 
		} //这个拷贝函数不完整，还是没有把a对象拷贝给b对象 
		void print()
		{
			cout<<this->id<<endl;
		}
		void change()
		{
			id = 6;
		}
		~A() {
			cout<<id<<"xigou"<<id<<endl;
		}
		
};
int main() {
	A a(3);
	A b(a);
	cout<<"end of main"<<endl;
	cout<<a.j<<endl;
	a.print();
	b.print();
	a.change();
	a.print();
	b.print();
	return 0;
}


