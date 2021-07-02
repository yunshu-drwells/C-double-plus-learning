#include<iostream>
using namespace std;
class A {
		int id;
	public:
		int j=0;
		A(int i) {
			id = i;
			cout<<id<<"gouzao"<<id<<endl;
		}
		A(const A &c){
			cout<<"自定义拷贝构造函数"<<endl;
			id = c.id;	 
		} //这个拷贝函数是完整的，并把a对象成员拷贝给b对象成员 
		void print()
		{
			cout<<this->id<<endl;
		}
		void change()
		{
			id = 6;
		}
		
};
int main() 
{
	A a(3) ;
	A b(a);
	
	a.print();
	b.print();
	
	a.change();
	
	a.print();//38,39行的运行结果得出对象a和对象b不共用内存空间 
	b.print();//38,39行的运行结果得出在将对象a拷贝到对象b时给对象b开辟了行的成员空间，而不是共用了a的空间 
	
	return 0;

}
