#include<stdio.h>
#include<math.h>
int main(void)
{
	int a ;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
	float h;int n;
	scanf("%f %d",&h,&n);
	float s=h,l=h/2;
    for(int i=2;i<=n;i++){
    	s+=l*2;
    	l-=l/2;
	}
		printf("%.2f %.2f\n",s,l);
    }
}
