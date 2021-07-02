#include <stdio.h>
int main (void)
{
	int a ;
	scanf("%d",&a);
	int sum1[a],sum2[a],sum3[a],total[a];
	for(int i=0;i<a;i++){
		scanf("%d %d %d",&sum1[i],&sum2[i],&sum3[i]);
        total[i]=sum1[i]+sum2[i]+sum3[i];
}
	int i, j, temp;
    for(j=0;j<a-1;j++){
        for(i=0;i<a-1-j;i++)
        {
            if(total[i]>total[i+1])
            {
                temp = total[i];
                total[i] = total[i+1];
                total[i+1] = temp;
            }
        }
    }
    for(int i=a-1;i>=0;i--){
    	printf("%d\n",total[i]);
	}
 } 
