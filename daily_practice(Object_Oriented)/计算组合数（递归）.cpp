#include<stdio.h>
#include<math.h>

int C(int n,int m)
{
	if(m==0){
		return 1;
	}
	else if(n==1){
		return 1;
	}
	else if(m==n){
		return 1;
	}
	else{
		return C(n-1,m-1)+C(n-1,m);
	}
}

int main()
{
	int N, n, m;
	scanf( "%d\n", &N );
	while(N--){
		scanf( "%d %d", &n, &m );
		printf( "%d\n", C(n,m) );
	}
	return 0;
}

