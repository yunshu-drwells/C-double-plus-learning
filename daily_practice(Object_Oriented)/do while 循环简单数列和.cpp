#include<stdio.h>
int main()
{
	int i,sum=0;
	i=1;
	do{
		sum+=i;
		i++;
	}
	while(i<=100);
	printf("%d\n",sum);	
} 
