#include<stdio.h> 
#include<string.h>
#include<math.h>  
int main(void)
{
	char a[15];
	char b[15];
	gets(a);
	gets(b);
	
	int y=strcmp(a,b);
	if(y<0){
		printf("%s<%s",a,b);
	}
	else if(y>1){
		printf("%s>%s",a,b);
	}
	else if(y==0){
		printf("%s=%s",a,b);
 } 
 }
