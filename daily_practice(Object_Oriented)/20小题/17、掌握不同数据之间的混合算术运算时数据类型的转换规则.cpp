#include <iostream> 
#include <typeinfo>
using namespace std;
int main() 
{	bool b = true;	
	short s = 3;
	int i = 1; 
	float f = 1.0; 
	unsigned int ui = 3;
	cout << "b type: "<< typeid(b).name() << endl;
	cout << "s type: " << typeid(s).name()<< endl;
	cout << "i type: " << typeid(i).name()<< endl;
	cout << "f type: " << typeid(f).name()<< endl;
	cout << "ui type: " << typeid(ui).name()<< endl;
	cout << "b + b type: " << typeid(b +b).name() << endl;
	cout << "'a' + 'b' type: " << typeid('a' + 'b').name() << endl;
	cout << "s + s type: " << typeid(s + s).name() << endl;
	cout << "'a' + i + f type: " << typeid('a' + i + f).name() << endl;
	cout << "'a' + 3.14 type: " << typeid('a' + 3.14).name() << endl;
	cout << "123 + 123L type: " << typeid(123 + 123L).name() <<endl;
	cout << "123L + 123U type: " << typeid(123L + 123U).name() << endl;
	cout << "123 + ui type: " << typeid(123 + ui).name() << endl;
	return 0;
}
/*
typeid 操作符可以在程序中可用于获取一个表达式的类型。不同数据之间的混合算术运算中数据类型的转换规则如下：
(1)如果有一操作数的类型是long double，则将另一个操作数转换为long double；
(2)否则，如果有一操作数的类型是double，则将另一个操作数转换为double；
(3)否则，如果有一操作数的类型是float，则将另一个操作数转换为float；
(4)否则，说明操作数都为整数，因此执行整形提升，即把bool、char、unsigned char、signed char、short、unsigned short和signed char提升为int；
(5)在这种情况下，如果有一个操作数的类型是unsigned long，则将另一个操作数转换为unsigned long；
(6)否则，如果有一个操作数的类型是long int，而另一个操作数是unsigned int，则转换将取决于两种类型的相对长度。如果long能够表示unsigned int的所有可能值，则将unsigned int转换为long；
(7)否则，将两个操作数都转换为unsigned long；
(8)否则，如果一个操作数是long，则将另一个操作数转换为long；
(9)否则，如果一个操作数是unsigned int，则将另一个操作数转换为unsigned int；
(10)如果编译器到达此处，说明两个操作数都是int类型。*/
