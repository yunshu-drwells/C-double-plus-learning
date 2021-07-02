#include <stdio.h>
int main (void)
{
	int a ;
	scanf("%d",&a);
	
	int b[a];
	for(int i=0;i<a;i++){
		scanf("%d",&b[i]);
	}
	int t ;
	for(int i=0;i<a;i++){
		t=b[i];
		b[i]=b[a-1-i];
	for(int i=0;i<a;i++){
		printf("%d",b[i]);
	}
}
}
