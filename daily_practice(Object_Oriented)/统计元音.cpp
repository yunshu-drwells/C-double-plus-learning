#include <stdio.h>
#include <string.h>
int main (void) 
{
	int a;
	scanf("%d",&a);
	getchar();
	for(int i=0;i<a;i++){
		char y[100];
		gets(y);
		int a=0,e=0,q=0,o=0,u=0;
		for(int i=0;i<strlen(y);i++){
			if(y[i]=='a'){
				a++;
			}
			if(y[i]=='e'){
				e++;
			}
			if(y[i]=='i'){
				q++;
			}
			if(y[i]=='o'){
				o++;
			}
			if(y[i]=='u'){
				u++;
			}
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n\n",a,e,q,o,u);
	}
}
