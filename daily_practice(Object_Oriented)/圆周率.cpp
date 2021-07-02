#include <stdio.h>
#include <math.h>
int main(void)
{
	int n ;
	double sum=0.0,t=1;
	scanf("%d",&n);
	for(int i=1;i<=4*n-1;i=i+2){
		sum+=t/i;
		t=-t;
	}
	printf("%.5f",4*sum);
 } 
