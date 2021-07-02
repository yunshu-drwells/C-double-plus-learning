#include<iostream>
using namespace std;
int main()
{
	const int n=4;
	int a[n][n];
	int i,j;
	for( i=0;i<=n-1;i++)
	{
		
		for( j=0;j<=i;j++)
		{
			
			if(j==0||j==i)
			{
				a[i][j]=1;
			}
			else 
				a[i][j]=a[i-1][j-1]+a[i-1][j];
				if(j==0&&i<=4)
				{
					for(int l=0;l<14-i;l++)
					cout<<" ";
				}
				if(j==0&&i>=5)
				{
					for(int l=0;l<13-i;l++)
					cout<<" ";
				}
					
				cout<<a[i][j]<<" ";		
		}	
		cout<<"\n";
	}
	return 0;
}
