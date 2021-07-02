#include<iostream>
using namespace std;
class DATE 
{
	public:
	DATE() //没有参数的构造函数 = 缺省函数 = 缺省的构造器 
	{
		month = day = year = 0;
		cout<< "缺省构造器被调用。"<< endl;
//		cout<< "构造器被调用"<< day << endl; 
	}
	DATE(int m,int d,int y)
	{
		this->month = m;
		this->day = d;
		this->year = y;
		cout<< "构造器被调用"<< day << endl; 
	}
	~DATE()
	{
		cout<< "析构器被调用"<< day<<endl; 
	 } 
	void Print() const //公有成员函数 即方法 =常成员 (不能对数据成员进行修改，只能做输出)
	{
		cout<< "Month = "<< month << "Day = "<< day <<"Year = "<<year<<endl;
	 } 
	
	private:
	int year,month,day; //数据成员 
	
}; 
int main()  //构造相当于分配内存（出生）构析相当于释放内存 （死亡） 
{
	DATE dates[5] = {DATE(10,1,2000),DATE(10,2,2000),DATE(10,3,2000)}; 
//用花括号对对象数组进行初始化,使用了DATE构造器进行构造 
//有5个对象，但只给了3个对象后面那两个对象便会调用缺省构造函数

	dates[3] = DATE(10,4,2000);	//赋值会产生临时匿名对象(36,37)
	//DATE temp = DATE(10,4,2000);   temp 是变量（临时匿名对象）  ，“DATE(10,4,2000)”是构造的对象 
	//dates[3] = temp;   变量赋给数组元素 
	dates[4] = DATE(10,5,2000);	//赋值会产生临时匿名对象
	//DATE temp = DATE(10,5,2000);   temp 是变量（临时匿名对象）  ，“DATE(10,5,2000)”是构造的对象 
	//dates[4] = temp;   变量赋给数组元素 
	cout<< "成功"<<endl;
	return 0; 	
}



