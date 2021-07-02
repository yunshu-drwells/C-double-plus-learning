#include <stdio.h>
int main ( void )
{
	printf("Enter two integer,and i will tell you\n");
	printf("the raletionship they satify: ");
	
	int num1;
	int num2;
	
	scanf( "%d %d",&num1,&num2 );
	
	if ( num1==num2 ) {
		printf("%d is equal to %d\n", num1,num2) ;
	}
	
	if ( num1!=num2) {
		printf("%d is not equal to %d\n", num1,num2);
	}
	
	if ( num1 < num2) {
		printf("%d is less than %d\n", num1,num2);
	}
	
	if ( num1 > num2) {
		printf("%d is greater than %d\n", num1,num2);
	}
	
	if ( num1 <= num2) {
		printf("%d is less than or  not equal to %d\n", num1,num2);
	}
	
	if ( num1 >= num2){
		printf("%d is greater than or  not equal to %d\n", num1,num2);
	}
	
} 

