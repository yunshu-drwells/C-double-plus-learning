#include <stdio.h>
int main (void)
{
	int n ;
	scanf("%d",&n);
	
	int a[n],b[n],c[n];
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	}
	for(int i=0;i<n;i++){
		if((a[i]%4==0&&a[i]%100!=0)||(a[i]%400==0)){
			if(b[i]==1){
				printf("%d",c[i]);
			}
			else if(b[i]==2){
				printf("%d",29+c[i]);
			}
			else if(b[i]==3){
				printf("%d",29+31+c[i]);
			}
			else if(b[i]==4){
				printf("%d",29+31+30+c[i]);
			}
			else if(b[i]==5){
				printf("%d",29+31+30+31+c[i]);
			}
			else if(b[i]==6){
				printf("%d",29+31+30+31+30+c[i]);
			}
			else if(b[i]==7){
				printf("%d",29+31+30+31+30+31+c[i]);
			}
			else if(b[i]==8){
				printf("%d",29+31+30+31+30+31+31+c[i]);
			}
			else if(b[i]==9){
				printf("%d",29+31+30+31+30+31+30+30+c[i]);
			}
			else if(b[i]==10){
				printf("%d",29+31+30+31+30+31+30+31+31+c[i]);
			}
			else if(b[i]==11){
				printf("%d",29+31+30+31+30+31+30+31+30+30+c[i]);
			}
			else if(b[i]==12){
				printf("%d",29+31+30+31+30+31+30+31+30+30+31+c[i]);
			}
		}
		else{
			if(b[i]==1){
				printf("%d",c[i]);
			}
			else if(b[i]==2){
				printf("%d",28+c[i]);
			}
			else if(b[i]==3){
				printf("%d",28+31+c[i]);
			}
			else if(b[i]==4){
				printf("%d",28+31+30+c[i]);
			}
			else if(b[i]==5){
				printf("%d",28+31+30+31+c[i]);
			}
			else if(b[i]==6){
				printf("%d",28+31+30+31+30+c[i]);
			}
			else if(b[i]==7){
				printf("%d",28+31+30+31+30+31+c[i]);
			}
			else if(b[i]==8){
				printf("%d",28+31+30+31+30+31+31+c[i]);
			}
			else if(b[i]==9){
				printf("%d",28+31+30+31+30+31+30+30+c[i]);
			}
			else if(b[i]==10){
				printf("%d",28+31+30+31+30+31+30+31+31+c[i]);
			}
			else if(b[i]==11){
				printf("%d",28+31+30+31+30+31+30+31+30+30+c[i]);
			}
			else if(b[i]==12){
				printf("%d",28+31+30+31+30+31+30+31+30+30+31+c[i]);
			}
			printf("\n");
		}
	}
 } 
