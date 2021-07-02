#include<iostream>
using namespace std;
class Object
{
private:
	int x;
	int y;
public:
	void change()
	{
		this->x = 10;
		this->y = 20;
	}
	int Add()
	{
		return this->x + this->y;
	}
	void Test()
	{
		cout<<"x = "<<this->x<<",y = "<<this->y<<endl;
		cout<<this->Add()<<endl;   //this指针可以直接访问本类的其它成员 不受private和public的限制
		cout<<"this :"<<this<<endl;		   //从内部访问访问时，不受private和public的限制
	}							   
};

int main()
{
	Object obj;  
	obj.change();
	obj.Test();
	cout<<obj.Add()<<endl;
	//当Test被调用时，已经把对象obj的指针传给了它
	//编译器内部就是这么执行的，没必要画蛇添足的传一个指针给它

	cout<<"obj : "<<&obj<<endl;  //打印地址printf("obj : %p",&obj);   %p = 地址

/*
	Object obj;
	Object *p = &obj;
	p->change();
	p->Test();
	cout<<obj.Add()<<endl;
*/
return 0;
}
