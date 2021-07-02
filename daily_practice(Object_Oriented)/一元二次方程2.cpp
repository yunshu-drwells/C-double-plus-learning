#include <stdio.h> 
#include <math.h>
int main(void)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int q=b*b-4*a*c;
	if(q>=0){
	double x1=-b+sqrt(b*b-4*a*c)/(2*a);
	double x2=-b-sqrt(b*b-4*a*c)/(2*a);
	if(x1>x2){
		printf("%.2f %.2f",x1,x2);
	}
	else{
		printf("%.2f %.2f",x2,x1);	
	}
	}
	else
	{
		float m=-b/(2*a);
		float n=sqrt(-q)/(2*a);
		printf("%.2f+%.2fi %.2f-%.2fi",m,n,m,n);
	}
 } 
