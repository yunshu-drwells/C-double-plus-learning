#include <stdio.h>
#include <string.h>
int main (void)
{
	char a[100];
	gets(a);
	
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]-=32;
		}
		else if(a[i]>='A'&&a[i]<='Z'){
			a[i]+=32;
		}
		else if(a[i]=='0'){
			a[i]='9';
		}
		else if(a[i]=='1'){
			a[i]='8';
		}
		else if(a[i]=='2'){
			a[i]='7';
		}
		else if(a[i]=='3'){
			a[i]='6';
		}
		else if(a[i]=='4'){
			a[i]='5';
		}
		else if(a[i]=='5'){
			a[i]='4';
		}
		else if(a[i]=='6'){
			a[i]='3';
		}
		else if(a[i]=='7'){
			a[i]='2';
		}
		else if(a[i]=='8'){
			a[i]='1';
		}
		else if(a[i]=='9'){
			a[i]='0';
		}
	}
	for(int i=strlen(a)-1;i>=0;i--){
		printf("%c",a[i]);
	}
 } 
