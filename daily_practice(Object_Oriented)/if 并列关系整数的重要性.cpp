#include <stdio.h>
int main ( void )
{

	int grade;
	scanf( "%d",&grade ); 
	
	if ( grade >= 60) {
		puts("Passed");
	}
	else {
		puts("Failed");
	}
}
