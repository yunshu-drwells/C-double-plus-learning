#include <stdio.h>

void swap(int *x,int *y)
{
	int temp;
	
	temp=*x; /* 将这三行换值语句换成   */                        
	*x=*y;   /*用指针访问i和j的值	   */	
	*y=temp; /*并进行赋值*x=45;*y=13 也可以实现相同的功能  */
}
int main()
{
	int i=13,j=45;
	swap(&i,&j);
	printf("i=%d,j=%d",i,j);
}

