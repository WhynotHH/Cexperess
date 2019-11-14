#include<stdio.h>
#include<stdlib.h>
int compare (const void * a, const void * b)//系统的qsort需要用到这个函数
{
  return ( *(int*)a - *(int*)b );
}
//建立函数twosum 返回值为:一对数组下标(可用 int*)，传入nums ，和数组长度length，和目标数target 
int* twosum(int* nums,int length,int target){
	
	//因为函数要求返回的是一对数字，所以应该molloc一个长度为2的数组result 
	int* result = (int*)malloc(sizeof(int)*2);//返回值
	
	//先malloc新的数组newnums用于保存原来数组的数据顺序
	int *newnums = (int*)malloc(sizeof(int)*length);
	for(int  i = 0;i < length;i++){//复制数组
		newnums[i] = nums[i];
	}
	
	//对传入的数组进行排序(排序会影响原来数组的顺序)
	qsort(newnums,length,sizeof(int),compare);//快速排序
	//创建变量 low=0，high=length-1分别代表数组的数组的最高位和低位的下标
	int low = 0;
	int high = length - 1;
	//在while循环(条件为low<high)如果low和high对应的值相加大于target(high--)如果小于(low++)如果等于跳出 
	while(low < high){
		if(newnums[low] + newnums[high] < target){
			low++;
		} else if(newnums[low] + newnums[high] > target){
			high--;
		}else{
			break;
		}
	}
	
	if(low < high){//找到了对应的两个的特定数
		//将newnums[low]和high]对应的值，赋予result[2]; 
		result[0] = newnums[low];
		result[1] = newnums[high];
		//free(newnums);
		free(newnums);
		//返回result
		return result;
	}else{
		//free(newnums);
		free(newnums);
		return NULL;
	}
}
int main(){
	//给定一个整数数列，找出其中和为特定值的那两个数。你可以假设每个输入都只会有一种答案，同样的元素不能被重用
	//给定 nums = [2, 7, 11, 15], target = 9因为 nums[0] + nums[1] = 2 + 7 = 9所以返回 [0, 1]
	//双指针法求解
	
	//创建数组nums 放入数据
	int nums[]={2,7,11,15,6,5};
	//计算数组的长度length
	int length = sizeof(nums)/sizeof(int);
	//特定值target
	int target = 18;
	//创建一个变量接收twosum的返回值
	int* result = twosum(nums,length,target);
	
	if(result != NULL){
		//输出两个对应的值
		printf("两个对应的值为%d,%d\n",result[0],result[1]);
		//free(result);
		free(result);
	}else{
	//说明未找到
	printf("未找到对应的值\n");
	//free(result);
	free(result);
	}
	system("pause");
	return 0;
}