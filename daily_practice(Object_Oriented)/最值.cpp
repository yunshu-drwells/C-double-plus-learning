#include<stdio.h>
int main (void)
{
	int b ;
	scanf("%d",&b);
	
	int a[b];
	for(int i=0;i<b;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1] , k=1 ;
	for(int i=2;i<b;i++){
		if(a[i]>x){
			x=a[i];
			k=i;
		}
	}
	int y=a[1] , z=1 ;
	for(int i=2;i<b;i++){
		if(a[i]<y){
			y=a[i];
			z=i;
		}
	}
	int q=a[0];
	int p=a[b-1];
	a[b-1]=a[k];
	a[0]=a[z];
	a[k]=p;
	a[z]=q;
	for(int i=0;i<b;i++){
		printf("%d ",a[i]);
	}
}

