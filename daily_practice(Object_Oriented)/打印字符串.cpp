#include <iostream>
using namespace std;
class GradeBook
{
public:
	string coursename;
	void give(string String)
	{
		cout<<String<<endl;
	}
};
int main ()
{
	GradeBook mine;
	string course;
	getline(cin,course);
	mine.give(course);
	return 0;
}
