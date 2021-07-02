#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,len ;
	int a[10], i;
    scanf("%d", &n);
    len=log10(n)+1;
    for(i = 0; i <len ; i++)
    {
        a[i] = n % 10;
        n = n / 10;
    } 
    for(i=len-1; i>0;i--)
    {
       printf("%d ", a[i]);
        }
        printf("%d",a[0]); 
    return 0;
}
