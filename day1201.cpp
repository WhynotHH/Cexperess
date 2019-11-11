#include<stdio.h>
#include<stdlib.h>
/*编写函数：unsigned int reverse_bit(unsigned int value);
这个函数的返回值是value的二进制位模式从左到右翻转后的值。
如：在32位机器上25这个值包含下列各位：
00000000000000000000000000011001翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：2550136832*/
unsigned int get_avalue(unsigned int  getav){//给getav传的就是reverse_bit()函数中的i
	//将getav二进制，从第一个‘1’(也是唯一一个1)起往后所有位都变变成1
	for(unsigned int i = 0x80000000;i > 0;i = i >> 1){
		if(i < getav){
			getav = getav | i;
		}
	}
	return getav;
}
unsigned int get_bvalue(unsigned int getbv){//给getbv传的就是reverse_bit()函数中的i
	
	//将getbv二进制，从第一个位到第‘1’位(也是唯一一个1)全部变为变成1
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
	//首先定义一个  用于放value最后一位的的值的变量
	int tem; 
	for(unsigned int i = 0X80000000;i > 1;i = i >> 1){//i是控制循环函数，i只有一位是1，代表的是将value右移前的最后一位放在该位处。
		unsigned int avalue,bvalue;
		//value二进制的最后一位给tem
		tem = value & 0X00000001;
		//将value分为 avalue和bvalue 因为（i的‘1’位为要改变的位。）
		//avalue是指和i的‘1’一起>>1的位
		avalue = value & get_avalue(i);
		//bvalue是指i的‘1’前边不用动的位
		bvalue = value & get_bvalue(i);
		//将avalue的值>>1
		avalue = avalue >> 1;
		//将value的最后一位的值放在avlue的（i==‘1')位处
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
