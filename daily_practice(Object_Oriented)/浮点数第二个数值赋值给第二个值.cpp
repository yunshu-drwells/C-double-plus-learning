#include <stdio.h>
int main (void)
{
	double firstNumber,secondNumber,temporaryVariable;
	
	printf("Enter firstNumber: ");
	scanf("%lf",&firstNumber);
	
	printf("Enter secondNumber； "); 
	scanf("%lf",&secondNumber);
	
	temporaryVariable = firstNumber;
	
	firstNumber = secondNumber;
	
	secondNumber = temporaryVariable;
	
	printf("\n交换后，firstNumber = %lf\n",firstNumber);
	printf("交换后，secondNumber = %lf",secondNumber);
	
	return 0;
	
 } 
