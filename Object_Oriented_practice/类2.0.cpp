#include <iostream>
using namespace std;
class GradeBook
{
public:
	void setcoursename(string coursename)
	{
		Course = coursename;
	}
	void print()
	{
		cout<<Course<<endl;
	}
private:
	string Course;
	string couse;
};
int main ()
{
	GradeBook mine;
	string course;
	getline(cin,course);
	mine.setcoursename(course);
	mine.print();
	return 0;
}
