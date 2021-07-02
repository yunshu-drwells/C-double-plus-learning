#include <stdio.h>
int main (void)
{
	int a ;
	scanf ("%d",&a);
	
	for(int j=1;j<=a;j++){
		for(int i=1;i<=a-j;i++){
		    printf("  ");
	    }
	    for(int i=1;i<=j;i++){
	    	printf("%d ",i);
		}
		for(int i=j-1;i>0;i--){
	    	printf("%d ",i);
		}
	    if(j!=a){
	    	printf("\n"); 
		}
	}
} 
