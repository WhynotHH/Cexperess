#include<stdio.h>
#include<stdlib.h>
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ����ҳ�������֡���ʹ��λ���㣩
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