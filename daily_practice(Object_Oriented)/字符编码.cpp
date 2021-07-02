#include <stdio.h>
#include <stdlib.h>
int main (void) 
{
	char a[6];
	gets(a);
	for(int i=0;i<5;i++){
		if(a[i]>='a'&&a[i]<'w'){
			a[i]=a[i]+4;
		}
		else if(a[i]>='A'&&a[i]<'W'){
			a[i]=a[i]+4;
		}
	}
	printf("password is ");
	for(int i=0;i<5;i++){
		printf("%c",a[i]);
	}
}
