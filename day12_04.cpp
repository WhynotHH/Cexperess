#include<stdio.h>
#include<stdlib.h>
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。请找出这个数字。（使用位运算）
int main(){

	int array[] = { 3,4,5,1,1,5,4 };
	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 1; i < len; ++i) {
		array[0] = array[0] ^ array[i];
	}
	printf("%d\n", array[0]);
	system("pause");
	return 0;
}