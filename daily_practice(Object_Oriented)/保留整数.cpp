#include  <stdio.h>
#include  <string.h>
int main (void)
{
	int i=0;
	char a[80];
	gets(a);
	
	int len=strlen(a);
	for(i;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			printf("%c",a[i]);
		}
		else{
			for(int b=i+1;b<len;b++){
				if(a[b]>='0'&&a[b]<='9'){
					i=b-1;printf("*");break; 
				}
			}
		}
	}
}
