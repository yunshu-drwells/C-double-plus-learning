// 选择排序
#include "sort.h"


void selectSort(vector<int>& array){
	for(int i=0; i<array.size()-1; ++i){
		int min_index = i+1;
		for(int j=i+2; j<array.size(); ++j) //选择最小的
			min_index = array[min_index] > array[j]	? j : min_index;
		if(array[min_index] < array[i]){
			int temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;
		}
	}
}
