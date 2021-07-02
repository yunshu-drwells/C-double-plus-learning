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
		this->num = n; 
		this->score = s;
	}
	/*int read()
	{
		return score;
	}
	max()
	{
		
	}*/
	private:
	string num;
	int score;
};
int main()
{
	string str[9][99];
	int b[99];
	int max;
	int j;
	Student students[5]={};
//	Student *p;
//	p = &students[5];
	for(int i = 0;i<5;i++)
	{
		cin>>str[i][99];
		cin>>b[i];
	}
	for(int i = 0;i<5;i++)
	{
		students[i]=Student(str[i][99],b[i]);
	}
	max = b[0];
	for(int i = 0;i<5;i++)
	{
		if(max<b[i]) 
		{
			max = b[i];
			j = i;
		}
	}
	cout<<str[j][99]<<' '<<max<<endl;
	return 0;		
}
