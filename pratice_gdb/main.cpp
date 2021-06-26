
#include "sort.h"

int main(){
	vector<int> array = {12, 27, 55, 22, 67};
	bubbleSort(array);

	cout<<"冒泡排序之后的数组是："<<endl;
	for(int i=0; i<array.size(); ++i)
		cout<<array[i]<<" ";
	cout<<endl;

	cout<<"------------------------"<<endl;
	
	vector<int> array2 = {25, 47, 36, 80, 11};
	selectSort(array2);
	cout<<"选择排序之后的数组是："<<endl;
	for(int i=0; i<array2.size(); ++i)
		cout<<array2[i]<<" ";
	cout<<endl;
	
	return 0;
}
