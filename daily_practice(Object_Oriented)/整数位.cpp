#include <stdio.h>
#include <math.h>
int main (void)
{
	int a ;
	scanf("%d",&a);
	int b=log10(a)+1;
	printf("%d\n",b);
		int sum[b];
	for(int i=0;i<b;i++){
		sum[i]=a%10;
		a=a/10;
	}
	for(int i=b-1;i>=0;i--){
		printf("%d ",sum[i]);
	}
	printf("\n");
	for(int x=0;x<b;x++){
		printf("%d ",sum[x]);
	}
}
