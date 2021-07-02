#include <stdio.h>
#include <math.h>
int main (void)
{
	int a ;
	scanf("%d",&a);
	
	for(int i=0;i<a;i++){
		int n ;
		scanf("%d",&n);
		if(n>0&&n<10){
			printf("%.2f\n",log2(n));
		}
		if(n<0){
			printf("%.2f\n",-n+sin(n));
		}
		if(n>=10){
			printf("%.2f\n",pow(n,2));
		}
		if(n==0){
			printf("%.2f\n",0.0*n);
		}
	}
 } 
