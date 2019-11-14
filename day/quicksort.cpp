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
	while(low != high){ //���low==high˵�� �ô���������Ӧ��basic���� nums[low/high]��
		while(nums[high] >= basic && low != high){ 
			high--;
		}//�ú���������ʱ��nums[high] < basic
		nums[low] = nums[high];

		while(nums[low] <= basic && low != high){
			low++;
		}//��ѭ������nums[low] > basic 
		nums[high] = nums[low];
	}
	nums[low] = basic;//������ӵ�������
	quicksort(nums,left,low-1); //�ݹ鴦�����
	quicksort(nums,low+1,right);//�ݹ鴦���Ҳ�
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