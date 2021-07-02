#include <stdio.h>
int main (void)
{
	int a,b,c,t,n;
	while(scanf("%d,%d,%d",&a,&b,&c)!=EOF){
		if(a>b){
			t=a;
		}
		else{
			t=b;
		}
		if(t>c){
			n=t;
		}
		else{
			n=c;
		}
		printf("max=%d\n",n);
    }
    return 0;
}
