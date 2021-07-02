#include <iostream>
using namespace std;
class GradeBook
{
private:
	
public:
	int number;                      //属性，特征 
	int weight;
	void setnumber(int m ,int n)
	{
		m = number;
		n = weight;
	}
	void dissplayMessage() const     //方法，函数，行为(成员函数） 
	{
		cout <<"Welcom to the grade book!" << endl;
	}
	void function() 
	{
		cout <<weight<<endl;
	}
	
};

int main()
{
	GradeBook myGradebook;
	myGradebook.dissplayMessage();
	
	cout <<myGradebook.number<<endl;
	cout <<myGradebook.weight<<endl; 
	
	myGradebook.setnumber(1,87);
	cout <<myGradebook.number<<endl;
	cout <<myGradebook.weight<<endl; 
	
	GradeBook lisi;
	lisi.setnumber(2,65);
	cout <<lisi.number<<endl;
	cout <<lisi.weight<<endl; 
	return 0;
}
