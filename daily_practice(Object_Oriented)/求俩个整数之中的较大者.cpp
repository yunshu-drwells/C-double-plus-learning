#include <stdio.h>
int main (void)
{
	int a;
	int b;
	while(scanf("%d %d",&a,&b)!=EOF){
	
	if(a<b){
		printf("max=%d\n",b);
	}
	else{
		printf("max=%d\n",a);
	}
    }
}
