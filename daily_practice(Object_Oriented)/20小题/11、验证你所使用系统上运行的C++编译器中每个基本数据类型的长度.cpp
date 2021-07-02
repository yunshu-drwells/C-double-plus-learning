#include<iostream>
using namespace std;
int main()
{
	double doubleType;
	float  floatType;
	char   charType;	
	int    integerType;
	printf("Size of double: %ld bytes\n",sizeof(doubleType));
	printf("Size of float:  %ld bytes\n",sizeof(floatType));
	printf("Size of char:   %ld bytes\n",sizeof(charType));	
	printf("Size of int£»   %ld bytes\n",sizeof(integerType));
	return 0;	
}
