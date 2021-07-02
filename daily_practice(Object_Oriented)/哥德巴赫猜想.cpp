#include <stdio.h>
#include <string.h>
int fun(int y)
{
	for(int n=1;n<y;n++){
	    if(y%n!=0){
	        return 1;
	    }
    }
 } 
 int sum(int n)
 {
 	int b;
 	for(int i=7;i<n;i++){
 		b=n-i;
 		if(fun(i)==1&&fun(b)==1){
 			return i;
		}
	}
 }
 int main ()
 {
 	int a;
 	scanf("%d",&a);
 	printf("%d=%d+%d",a,sum(a),a-sum(a));
 }
