#include<iostream>
using namespace std;
class Student
{
	

	public:
		string num;
		int grade;
		void get()
		{
			cin>>num>>grade;
		}		
};
void max(Student *p)
	{
		int max = p->grade;
		for(int i = 0;i < 5;i++)
		{
			if(max < (p+i)->grade)
			{
				max = (p+i)->grade;
			}	
		}
		for(int i = 0;i < 5;i++)
		{
			if(max == (p+i)->grade)
			{
				cout<<(p+i)->num<<" "<<(p+i)->grade;
			}				
		} 
    }
int main()
{
	Student a[5];
	Student *p = a;
	for(int i = 0;i < 5;i++)
	{
		a[i].get();
	}
	max(p);
	
	return 0;
}
