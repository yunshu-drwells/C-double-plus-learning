#include <stdio.h>
#include <string.h>
int main (void)
{
	int x=1 , t ;
	char a[100];
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]==' '){
			for(t=i;t<100;t++){
				if(a[t]!=' '){
					x+=1;
					break;
				}
			}
		  i=t;
		}
	}
	printf("%d",x);
}
