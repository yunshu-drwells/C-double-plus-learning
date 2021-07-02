#include<stdio.h>
int main (void)
{
	int a ;
	while(scanf("%d",&a)&&a!=0){
	int sum[a];
	for(int i=0;i<a;i++){
		scanf("%d",&sum[i]);
	}
	int x ;
	for(int n=0;n<a;n++){
		for(int i=0;i<a-1-n;i++){
		    if(sum[i]<sum[i+1]){
		    	x=sum[i+1];
		    	sum[i+1]=sum[i];
		    	sum[i]=x;
			}
	    }
	}
	for(int i=a-1;i>=0;i--){
		printf("%d ",sum[i]);
	}
	printf("\n");
	}
}
  
