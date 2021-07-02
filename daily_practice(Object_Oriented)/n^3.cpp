#include <stdio.h>
#include <math.h>
int main (void)
{
	int n ,sum=0;
	int i=1;
	scanf("%d",&n);
	
	int x=n*n*n;
	int y=log10(x)+1;
	while(i<=y){
		int z=x/pow(10,y-i);
		sum+=z*z*z;
		x-=z*pow(10,y-i);
		i++;
	}
	printf("%d",sum);
 } 
