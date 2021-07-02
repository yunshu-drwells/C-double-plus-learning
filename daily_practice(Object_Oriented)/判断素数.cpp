#include <stdio.h>
int main (void)
{
	int a, n ;
	scanf("%d",&a);
	if(a==1) printf("This is not a prime.");
	if(a==2) printf("This is a prime.");
	for(n=2;n<a;n++){
	     if(a%n==0){
	        printf("This is not a prime.");break;
	    }	  	
     }
    if(a==n)
	printf("This is a prime.");
 } 
