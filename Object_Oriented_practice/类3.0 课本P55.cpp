#include <iostream>
using namespace std;
class GradeBook
{
public:
	void setCoursename(string name)
	{
		coursename = name;
	}
	string getCoursename() const
	{
			return coursename;
    }
	void displayMessage() const
	{
		cout << "Welcome to the grade book for\n" << getCoursename() <<"!"<< endl;
	}
private:
//public:
	string coursename;
};
int main()
{
	string nameofCourse;
	GradeBook myGadeBook;
	
	cout << "Inital course name is :"<< myGadeBook.getCoursename() << endl;
	
	cout << "\nPlease enter the course name :" <<endl;
	
	getline(cin,nameofCourse);
	
	myGadeBook.setCoursename(nameofCourse);
	
	cout<<endl;
	
	myGadeBook.displayMessage();
	
	return 0 ;
}
