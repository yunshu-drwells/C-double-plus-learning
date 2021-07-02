#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[100] ,x=0;
	gets(a);
	
	int len=strlen(a);
	for(int i=0;i<len;i++){
		switch(a[i]){
			case'0':x+=0;break;
			case'2':x+=2;break;
			case'4':x+=4;break;
		    case'6':x+=6;break;
			case'8':x+=8;break;
		}
	}
	printf("%d",x);
 } 
