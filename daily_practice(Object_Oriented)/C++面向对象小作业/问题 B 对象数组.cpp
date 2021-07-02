#include<iostream>
using namespace std;
class Student
{
	public:
	Student()
	{
		
	}
	Student(string n,int s)
	{
		this->num = n;   /*当对一个对象调用成员
函数时，编译程序先将对象的地址赋给this指针，然后调用成员
函数。每次成员函数存取数据成员时，C++编译器将根据this指
针所指向的对象来确定应该引用哪一个对象的数据成员*/ 
		this->score = s;
		cout<<num<<' '<<score<<endl;
	}
	private:
	string num;
	int score;
};
int main()
{
	string str[9][99];
	int b[99];
	int N;
	cin>>N;
	Student students[99]={};
	
	for(int i = 0;i<N;i++)
	{
		cin>>str[i][99];
		cin>>b[i];
	}
	for(int i = 0;i<N;i++)
	{
		students[i]=Student(str[i][99],b[i]);
	}
	return 0;
		
}
/*样例输入
5
01 89
02 78
03 56
04 92
05 76


样例输出
01 89
02 78
03 56
04 92
05 76
*/
