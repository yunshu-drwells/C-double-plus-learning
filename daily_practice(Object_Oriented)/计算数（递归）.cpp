#include<stdio.h>
#include<math.h>


int f(int m, int n)
{
	if(m==1){
		return n;
	}
	else if(n==1){
		return m;
	}
	else if(m>1&&n>1){
		return f(m-1,n)+f(m,n-1);
	}
}

int main()
{
	int T, m, n;
	scanf( "%d\n", &T );
	while(T--){
		scanf( "%d %d", &m, &n );
		printf( "%d\n", f(m,n));
	}
	return 0;
}
