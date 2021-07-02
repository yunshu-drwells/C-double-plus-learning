#include<iostream>
using namespace std;
class Student
{
	public:
		char no[100];
		int score;
};
Student a[5];

void max(Student *&p)
{
	int i;
	int max = a[0].score;
	for(i = 0;i<5;i++)
	{
		if(a[i].score > max)
		{
			max= a[i].score;
			p = &a[i];
		}
	}
}
int main()
{
	int i;
	for(i=0;i<5;i++)
	cin>>a[i].no>>a[i].score;
	
	Student *p = &a[0];
	max(p);
	
	cout<<p->no<<" "<<p->score<<endl;
	return 0 ;
}
/*
01 89
02 78
03 56
04 92
05 76
*/ 



