#include<iostream>
using namespace std;
int main()
{
int ch = 1;
	switch(ch) //整形
	{
	case 1:    //case必须是常量
		cout<<"Go to office!"<<endl;
		break;
	case 2:
	case 3:
		cout<<"Stay at home!"<<endl;
		break;
	default:
		cout<<"Do nothing!"<<endl;
		break;
	}
	return 0;
}