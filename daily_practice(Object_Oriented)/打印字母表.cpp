#include<iostream>
using namespace  std;
void print_assic()
{
	for(int i = 1;i<127;i++)
	{
		printf("%d->%c\n",i,i);
	}
}
int main()
{
	print_assic();
	return 0;
}