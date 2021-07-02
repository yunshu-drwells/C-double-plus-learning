#include <stdio.h>
int main (void)
{
	int a , b , c;
	scanf("%d %d %d",&a,&b,&c);
	
	if (a<b){
		int x=a;
		a=b;
		b=x;
	}
	else;
	if (b<c){
		int y=b;
		b=c;
		c=y;
	}
	else;
	if(a<b){
		int t=a;
		a=b;
		b=t	;
	}
	else;
	printf("%d %d %d ",a,b,c);
 } 
