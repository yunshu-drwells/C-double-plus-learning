#include<iostream>
using namespace std;
int main()
{
	int count = 0;
	
	for(int i = 0;i<=100;i++)
	{
	if(i%2)  //i%2 = 0
		continue;   //后面的语句被跳过
	count++;
	cout<<"even : "<<i<<endl;
	}
	cout<<"total :"<<count<<endl;
return 0;
}