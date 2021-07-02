#include <stdio.h>
int fun(int a)
{
	if(a==1){
		return 2;
	}
	if(a==2){
		return 3;
	}
	if(a==3){
		return 5;
	}
	else{
		return fun(a-1)+fun(a-2)-fun(a-3);
	}
}
int main ()
{
	int n ;
	scanf("%d",&n);
	printf("%d",fun(n));
}
