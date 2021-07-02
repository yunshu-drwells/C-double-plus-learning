#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int a[10];
		for(int i=0;i<n;i++){
			scanf("%d",a[i]);
		}
		int m=1;
		for(int i=1;i<n;i++){
			if(a[0]>=a[i]){
				m++;
			}
		}
		printf("%d\n",m);
	}
 } 
