#include <stdio.h>
int main (void)
{
	int a ;
	scanf("%d",&a);
	
	for(int j=0;j<a;j++){
		for(int i=1;i<a-j;i++){
		    printf(" ");
	    }
	    for(int i=0;i<2*(j+1)-1;i++){
	    	printf("*");
		}
	    for(int i=1;i<a-j;i++){
		    printf(" ");
	    }
	    printf("\n");
	}
	for(int j=1;j<a;j++){
		for(int i=0;i<j;i++){
		    printf(" ");
	    }
	    for(int i=0;i<2*(a-j)-1;i++){
	    	printf("*");
		}
	    for(int i=0;i<j;i++){
		    printf(" ");
	    }
	    printf("\n");
	}
}
