#include <stdio.h>
#include <math.h>
int main (void)
{
	int x,n;
	scanf("%d %d",&x,&n);
	float a=sqrt(1+x);
	for(int i=2;i<=n;i++){
		a=sqrt(a+i);
	}
	printf("%.2f",a);
}
