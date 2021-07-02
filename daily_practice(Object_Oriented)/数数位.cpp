#include <stdio.h>
int main (void)
{
	int a ;
	scanf("%d",&a);
	a/=10;
	
	int n=1 ;
	while(a>0){
		n+=1; 
		a/=10;
	}
	printf("%d",n);
}
