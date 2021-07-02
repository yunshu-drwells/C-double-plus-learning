#include<iostream>
using namespace std;
class Student
{
	public:
	Student(string n)
	{
		this->num = n;
	}
	Student(int s)
	{
		this->score = s;
	}
	/*max()
	{
		
	}*/
	private:
	string num[9][99];
	int score[99];
};
int main()
{
	string str[9][99];
	int b[99];
	int i = 0;
	
	Student *p;
	Student *t;			//利用Student类名创建指向Student类对象的指针 
	Student studentnum[5]={};
	Student studentscore[5]={};//利用Student创建对象
	p =  &studentnum[5];
	t =  &studentscore[5]		//给指针初始化 
	
	for(i = 0;i<5;i++)
	{
		cin>>str[i][99];
		cin>>b[i];
	}
	for(p,i=0;i<5;p++,i++)
	{
		p->Student(str[i][99]);
	}
	for(t,i=0;i<5;i++,t++)
	{
		t->Student(b[i]);
	}
	/*max = b[0];
	for(int i = 0;i<5;i++)
	{
		if(max<b[i]) 
		{
			max = b[i];
			j = i;
		}
	}
	cout<<str[j][99]<<' '<<max<<endl;
	return 0;*/		
}
