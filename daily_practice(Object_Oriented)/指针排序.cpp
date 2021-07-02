#include <stdio.h>
int main(void)
{
	int m,n,a[100],temp,*p;
	scanf("%d %d",&m,&n);
	p=a;
	
	for(int i=0;i<m;i++){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int j=0;j<n;j++){
		    for(int i=1+j;i<n;i++){
		    	if(a[j]>a[i]){
		    		temp=*(p+i);
		    		*(p+i)=*(p+j);
		    		*(p+j)=temp;
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
 } 
