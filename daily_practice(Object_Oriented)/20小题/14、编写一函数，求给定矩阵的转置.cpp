#include<iostream>
using namespace std;
int main()
{
	int a ;
	cin>>a;
	
	int  x=0;
	int sum[a][a];
	for(x;x<a;x++){
		for(int t=0;t<a;t++){
			cin>>sum[x][t];
		}
	}
	for(int y=0;y<a;y++){
		for(int n=0;n<a;n++){
			cout<<sum[n][y]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
