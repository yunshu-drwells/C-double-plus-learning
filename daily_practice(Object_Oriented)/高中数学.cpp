#include <stdio.h>
int fun (int n)
{
	if(n==1||n==2){
		return 1;
	}
	else{
		return fun(n-1)+fun(n-2);
	}
}
int main ()
{
	int a ;
	scanf("%d",&a);
		printf("%d\n",fun(a));
 } 
