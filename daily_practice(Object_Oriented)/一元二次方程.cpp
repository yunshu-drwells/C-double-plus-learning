#include <stdio.h>
#include <math.h>
int main (void)
{
    int a, b , c ;
    double x1 ,x2 , M ;
    scanf("%d %d %d",&a,&b,&c);
    M=sqrt(b*b-4*a*c);
    x1=(-b+M)/(2.0*a);
    x2=(-b-M)/(2.0*a);
    printf("%.2f %.2f",x1,x2);
} 
