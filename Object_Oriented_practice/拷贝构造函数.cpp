#include<iostream>
#define Debug 
using namespace std;
class Object
{	
	int id;  //属性（特征）
public:
	Object(int u)  //变量的初始化，这个构造函数是为了访问受保护的私有变量 
	{
		this->id = u;  //this-> 这个this指针的 目的是为了每个对象访问自己的属性（特征）时访问的是自己的对应的 
	}
	Object(const Object & other)  //copy constructor 函数名是类名，无返回值，参数形式是固定的 
	{
		this->id = other.id;
	}
	int change()   //改值     //方法，函数，行为(成员函数） 
	{
		this->id = 1;
	 } 
	void print()  //打印值    //方法，函数，行为(成员函数） 
	{	
		cout<<this->id<<endl;
	}
}; 
int main()
{
	
	Object A(9);  //直接初始化
	A.print();
	#ifdef Debug
	Object B = A; //拷贝初始化
	cout<<1<<endl;
	#endif
	#ifndef Debug
	Object B(0);  //直接初始化 ：int b(5) 拷贝初始化：int b = 5;
	  /*在C98和C11标准中用宏定义进行条件编译的时候条件编译的语句中如果出现定义对象，
	则此对象必须被初始化不然会报错 C14中不会报错 Object B(0);可以先初始化0  */ 
	B = A;
	cout<<0<<endl;
	#endif
	B.print();
	
	A.change();
	A.print();
	B.print();
	
	return 0;
}
	
	

