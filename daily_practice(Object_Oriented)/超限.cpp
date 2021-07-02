#include <stdio.h>
int a[10];
int b[10000];
int main()
{
	static int m,n,a,i,j,sum=0;
	while(1){
		if(scanf("%d",&m)==EOF)break;
		for(i=0;i<m;i++){
			sum=0;
			scanf("%d",&n);
		}
			for (j=0;j<n;j++){
				scanf("%d",&a);
				sum=sum+a;	
			}
			printf("%d\n",sum);
	}

return 0;
}
