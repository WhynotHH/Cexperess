#include<stdio.h>
#include<stdlib.h>
#define length 6
void quicksort(int* nums,int left,int right){
	
	if(left > right){
		return;
	}
	int low = left;
	int high = right;
	int basic = nums[left];
	while(low != high){ //如果low==high说明 该处是中心轴应将basic放在 nums[low/high]处
		while(nums[high] >= basic && low != high){ 
			high--;
		}//该函数结束的时候nums[high] < basic
		nums[low] = nums[high];

		while(nums[low] <= basic && low != high){
			low++;
		}//该循环结束nums[low] > basic 
		nums[high] = nums[low];
	}
	nums[low] = basic;//中心轴加到数组里
	quicksort(nums,left,low-1); //递归处理左侧
	quicksort(nums,low+1,right);//递归处理右侧
}
int main(){
	int nums[length]={19,97,9,17,1,8,};
	quicksort(nums,0,length-1);
	for(int i = 0;i < length;i++){
		printf("%d ",nums[i]);
	}
	system("pause");
	return 0;
}