#include<iostream>
using std::cout;
using std::endl;

void tryToModifyArray(const int []); 

int main()
{
	int a[] = {10,20,30};
	tryToModifyArray( a );
	cout<< a[0] <<' '<< a[1] << ' ' <<a[2]<<endl;
	return 0 ;
}
