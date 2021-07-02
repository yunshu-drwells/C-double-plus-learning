#include <stdio.h>
#include <string.h>
int main (void)
{
	char a[100];
	gets(a);
	int len=strlen(a);
	int b ;
	scanf("%c",&b);
	
	for(int i=0;i<len;i++){
		if(a[i]!=b){
			printf("%c",a[i]);
		}
	}
} 
