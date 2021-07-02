#include<stdio.h>
int main (void)
{
	int x , y , m , n , z ;
	scanf("%d %d",&x,&y);
	m=x;n=y;
	
	while(y!=0){
		z=x%y;
		x=y;
		y=z;
	}
	printf("%d %d",m*n/x,x);
 } 
