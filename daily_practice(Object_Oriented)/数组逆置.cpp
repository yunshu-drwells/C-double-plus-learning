#include <stdio.h>
int main (void)
{
	int sum[10];
	for( int t=0;t<=9;t++){
		scanf("%d",&sum[t]);
	}
	
	for(int i=9;i>0;i--){
		printf("%d ",sum[i]);
	}
	printf("%d",sum[0]);
 } 
