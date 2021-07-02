#include <string.h>
#include <stdio.h>
//用于存放double类型的对象 
class Array
{
public:
	Array(int capacity = 4)
	{
		m_buffer = new double[capacity];
		m_capacity = capacity;
		m_size = 0;
	}
	void PushBack(double val) // 
	{
		
	}
private:
	double *m_buffer; //创建一个叫*m_buffer缓冲区 
	int m_capacity;   //容量 
	int m_size;       //已经存放的对象的个数 
};

int main()
{
	Array a;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);
	a.PushBack(5);
}

