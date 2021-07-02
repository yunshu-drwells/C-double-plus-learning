#include <stdio.h>

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void bubbleSort(int array[],int size)
{
	//两个for循环的时间复杂度 
	//  n-1,n-2,n-3,…,1    (n-1)*n/2 
	//F(n) = (n-1)*n/2 )  = 1/2n^2 - n/2
	//O(n^2)
	
	//改进：  ；判断是否已经有序（9 - 16） 
	int index = 1;
	
	for(int i = 0;i < size;i++){
	if(array[i] > array[i+1])
	index--;
	}
	
	for(int i = 0;i < size;i++) //循环了size次 
	{
		//
		if(index == 1)
		 	break;
		 	
		 	
		 //假设已经有序了 
		 int orderd = 1; 
		 
		 for(int j = 0;j <= size - 2 - i;j++)  //  for(int j = 0;j < size - 1 - i;j++)
		 if(array[j] > array[j+1]){
		 swap(array,j,j+1);
		 orderd = 0;
		 } 
		 if(orderd == 1)
		 	break;
	}
}


int main()
{
	int num;
	printf("请输入要冒泡排序的数字的个数：\n");
	scanf("%d",&num);
	int array[num];
	int i = 0;
	while(i < num){	
		scanf("%d",&array[i]);
		i++;
	}
	bubbleSort(array,num);
	int size = num;     //sizeof(array)/sizeof(int); 
	
//打印冒泡排序后的数组
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}

/*
1	2	3	4	5
0	1	2	3	4	size

1	2	3	4	
0	1	2	3	size



*/


