#include<iostream>
using namespace std;
int main()
{
	int a[99];
	a[0] = 1;
	a[1] = 1;
	
	for(int j = 2;j<99;j++)
	{
		a[j] = a[j-1] + a[j];
		cout<<a[j]<<"   ";
	}
	/*for(int j=1;j<=a;j++){
		for(int i=1;i<=a-j;i++){
		    printf(" ");
	    }
	    for(int i=1;i<=j;i++){
	    	printf("%d ",i);
		}
		for(int i=j-2;i>0;i--){
	    	printf("%d",i);
		}
	    for(int i=1;i<a-j;i++){
		    printf(" ");
	    }
	    printf("\n");
	}	*/
}
