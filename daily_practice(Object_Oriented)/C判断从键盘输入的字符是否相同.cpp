#include"stdio.h"¡¡¡¡
int main(void)
{
char a,b;
printf("input a string: ");
b=getchar();
	while((a=getchar())!='\n'){
		if(a==b){
			printf("same character ");
			break;
		}
	}
}
