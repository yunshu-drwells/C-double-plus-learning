 #include<iostream>
#include<iomanip>   //setw setfill setbase  setprecision
using namespace std;
int main()
{
	char str[4]={'j','k','l','u'};
	cout << setw(6) << 2545 <<endl;
	
	cout << setfill('@')  << setw(5) << 255 << endl;
	cout << setfill(' ')  << setw(5) << 255 << endl;
	
	cout << setbase(2)  << setw(10) << 1024 <<endl;
	cout << setbase(4)  << setw(10) << 1024 <<endl;
	cout << setbase(8)  << setw(10) << 1024 <<endl;
	cout << setbase(10) << setw(10) << 1024 <<endl;	
	cout << setbase(16) << setw(10) << 1024 <<endl;
	cout << setbase(32) << setw(10) << 1024 <<endl;
	cout << setbase(64) << setw(10) << 1024 <<endl;
//	cout << setbase(2)  << setw(10) << '65' <<endl;
	return 0;
	
}
