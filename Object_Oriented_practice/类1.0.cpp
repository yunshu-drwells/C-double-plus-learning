#include <iostream>
using namespace std;
class GradeBook
{
public:
	int number;
	int weight;
	void dissplayMessage() const     //方法，函数，行为
	{
		cout <<"Welcom to the grade book!" << endl;
	}
	
};

int main()
{
	GradeBook myGradebook;
	myGradebook.dissplayMessage();
	GradeBook lisi;
	cout <<lisi.weight<<endl;
		 
}
