#include <stdio.h>
#include <string.h>
int main (void) 
{
	char a[100];
	gets(a);
	
	int x=strlen(a)-1;
	for(int i=0;i<strlen(a);i++){
		if(a[i]==a[x]){
			if(i>=x){
				printf("yes");break;
			}
			x--; 
		}
		else{
			printf("no");break;
		}
	}
}
