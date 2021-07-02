#include<stdio.h>
#include<math.h>
int main(void)
{
	int a ;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
	float h,n;
	scanf("%f %f",&h,&n);
	printf("%.2f %.2f\n",h*(1-pow(1/2,n-1))/(1-1/2)+h,h/(2*n));
    }
    return 0; 
}
