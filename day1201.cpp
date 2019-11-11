#include<stdio.h>
#include<stdlib.h>
/*��д������unsigned int reverse_bit(unsigned int value);
��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
�磺��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�2550136832*/
unsigned int get_avalue(unsigned int  getav){//��getav���ľ���reverse_bit()�����е�i
	//��getav�����ƣ��ӵ�һ����1��(Ҳ��Ψһһ��1)����������λ������1
	for(unsigned int i = 0x80000000;i > 0;i = i >> 1){
		if(i < getav){
			getav = getav | i;
		}
	}
	return getav;
}
unsigned int get_bvalue(unsigned int getbv){//��getbv���ľ���reverse_bit()�����е�i
	
	//��getbv�����ƣ��ӵ�һ��λ���ڡ�1��λ(Ҳ��Ψһһ��1)ȫ����Ϊ���1
	unsigned int getbv1=getbv;
	for(unsigned int i = 0x80000000;i > 0;i = i >> 1){
		if(i > getbv1){
			getbv = getbv | i;
		}else if(i == getbv1){
			getbv = getbv & (~i);
		}
	}
	return getbv;
}
unsigned int reverse_bit(unsigned int value){
	//���ȶ���һ��  ���ڷ�value���һλ�ĵ�ֵ�ı���
	int tem; 
	for(unsigned int i = 0X80000000;i > 1;i = i >> 1){//i�ǿ���ѭ��������iֻ��һλ��1��������ǽ�value����ǰ�����һλ���ڸ�λ����
		unsigned int avalue,bvalue;
		//value�����Ƶ����һλ��tem
		tem = value & 0X00000001;
		//��value��Ϊ avalue��bvalue ��Ϊ��i�ġ�1��λΪҪ�ı��λ����
		//avalue��ָ��i�ġ�1��һ��>>1��λ
		avalue = value & get_avalue(i);
		//bvalue��ָi�ġ�1��ǰ�߲��ö���λ
		bvalue = value & get_bvalue(i);
		//��avalue��ֵ>>1
		avalue = avalue >> 1;
		//��value�����һλ��ֵ����avlue�ģ�i==��1')λ��
		if(tem == 1){
			avalue = avalue | i;
		}
		value = avalue | bvalue;
	}
	return value;
}

int main()
{
	unsigned int a = 25;
	unsigned int b =reverse_bit(a);
	
	printf("%u",b);
	system("pause");
	return 0;
}
