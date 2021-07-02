#include<iostream>
 using namespace std;
inline int max(int x,int y)
{
	return (x>y)?x:y;
}
int main()
 {
     cout<<max(3,4)<<endl;
     cout<<max(6,5)<<endl;
     return 0;
 } 
