#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[100];
	int i, len;
	gets(a);
	len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]>='a'&&a[i]<='z'){
			printf("%c",a[i]-32);
		}
		else if(a[i]>='A'&&a[i]<='Z'){
			printf("%c",a[i]+32);
		}
	}
	return 0;
}
