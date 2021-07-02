#include<iostream>
using namespace std;
int main()
{
	int *a = new int (4);  /* 使用new运算符动态配置的空间，在整个程序结束后不会自动还
给系统，因此需要自己使用delete归还内存空间。*/
			       
	cout <<*a<<endl<<endl; //开辟一个int型指针赋值给a，并地址中的内容赋值为4
	delete a;              /*释放单个int的空间  delete a;只是释放*a中
	的内容，而不改变指针p本身，p存放的依然是申请空间时的地址。 */
					       
	int j,k,l;				       
	for(j=0;j<4;j++)
	cout <<*(a+j)<<endl;   //只开辟了一个内存空间 

	
	int *b = new int[4];   //开辟一个大小为100的整型数组空间。
	for(k = 0;k<4;k++)
	cin >>*(b+k); 
	
	for(l = 0;l<4;l++)       
	cout <<*(b+l)<<endl;
	delete []a;            //释放int数组空间
	return 0;
}
