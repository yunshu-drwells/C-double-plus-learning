#include <stdio.h>
int main (void)
{
	int dividend,divisor,quotient,remainder;
	
	printf("Enter an dividend: ");
	scanf("%d",&dividend);
	
	printf("Enter an divisor: ");
	scanf("%d",&divisor);
	
	quotient = dividend / divisor;
	remainder = dividend % divisor;
	
	printf("ษฬ = %d\n",quotient);
	printf("ำเสý = %d",remainder);
	
	return 0; 
}
