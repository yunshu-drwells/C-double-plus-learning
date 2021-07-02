#include <iostream>

//1. const对象可以调用非const成员函数吗？
//2. 非const对象可以调用const成员函数吗？
//3. const成员函数内可以调用其它的非const成员函数吗？
//4. 非const成员函数内可以调用其它的const成员函数吗？


class Test
{
public:
	Test(int data = 0)
	{
		m_data = data;
	}
	Test FunConst(const Test &t)const
	{
		//t.Fun(t);  //3.const成员函数内不可以调用其它的非const成员函数
		return Test(m_data + t.m_data);
	}
	Test Fun(const Test& t)
	{
		t.FunConst(t);  //4.非const成员函数内可以调用其它的const成员函数
		m_data = m_data * 2;
		return Test(m_data + t.m_data);
	}
private:
	int m_data;
};


int main()
{
	Test t(20);
	Test t1;
	const Test T2;
	//T2.Fun(t);  //1.const对象不可以调用非const成员函数  (有可能对数成员的访问权限变大)
	t1.FunConst(t);  //2.非const对象可以调用const成员函数

	return 0;
}