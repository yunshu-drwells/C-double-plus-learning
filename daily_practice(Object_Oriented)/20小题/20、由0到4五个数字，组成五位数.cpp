#include<iostream>
using namespace std;
int main()
{
	int a[4]={1,2,3,4};
	int b[5]={0,1,2,3,4};
	int c[4]={0,1,2,4};
	int d[4]={0,1,2,4};
	int e[5]={0,1,2,3,4};
	
	int i;
	int j;
	int k;
	int l;
	int m;
	
	for(i=0;i<4;i++)
	{
		cout<<a[i];
		for(j=0;j<5;j++)
		{
			cout<<b[j];
			for(k=0;k<4;k++)
			{
				cout<<c[k];

				for(l=0;l<4;l++)
				{
					cout<<d[l];

					for(m=0;m<5;m++)
					{
						cout<<e[m];							
					}
				}
			}
		}
	}
	return 0;	
}
