#include <stdio.h>
int main (void)
{
	int a ;
	scanf("%d",&a);
	
	int  x=0;
	int sum[a][a];
	for(x;x<a;x++){
		for(int t=0;t<a;t++){
			scanf("%d",&sum[x][t]);
		}
	}
	for(int y=0;y<a;y++){
		for(int n=0;n<a;n++){
			printf("%d ",sum[n][y]);
		}
		printf("\n");
	}
 } 
