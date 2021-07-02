#include <stdio.h>
int main (void)
{
	int a ;
	double  x=2.0 , y , n=1.0 , t ;
	scanf("%d",&a);
	
	double b=0.0 ;
	for(int i=1;i<=a;i++){
		b=b+x/n;
		t=n;
		n=x;
		x=x+t;
	}
	printf("%.6f",b);
 } 
