#include <stdio.h> 
int main()
{
	static int m=55,n=66;
	m-=1;
	n+=1;
	printf("%d\n%d",m,n);
}
