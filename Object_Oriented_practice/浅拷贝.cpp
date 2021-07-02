#include<iostream>
#include<cstring>
using namespace std;
class Test {

public:	
	Test(const char* str)   //构造函数 
	{
		//申请一块内存，保存此字符串
		m_size = strlen(str) + 1;
		m_buf  = new char[m_size];
		strcpy(m_buf,str);
		cout<<&m_buf<<endl;
	}
	Test(const Test& other)   //添加的深度拷贝构造函数 
	{
		m_buf  = other.m_buf;
		cout<<&m_buf<<endl;
		cout<<& other.m_buf<<endl;
	}

	~Test() {
		//释放此字符串
		delete []m_buf;
		cout<<"00"<<endl;
	}
	const char* GetText() {
	return m_buf;
	}
private:
	int m_size;  //申请的内存大小 
	char* m_buf; //内存首地址 
};

int main() 
{
	Test t1("Hellow World !");
	cout<<t1.GetText()<<endl; //printf("t1: %s \n",t1.GetText);
	Test t2(t1);  //如果没有添加17-19行，而是m_buf  = other.m_buf那么对象t2拷贝了t1，t2,m_buf指向了同一块内存。
	//cout<<& t2.m_buf<<endl;
	cout<<t2.GetText()<<endl;
	return 0;
}
/*

对象t1.m_buf指向一块内存，
对象t2拷贝了t1，t2,m_buf指向了同一块内存 

对象t1析构，delete []m_buf;
对象t2析构，delete []m_buf;出错，因为此块内存已经被delete

此错误在Dev c++中看不到 在VC 6.0中可以看到 
*/







