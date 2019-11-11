#include<stdio.h>
#include<stdlib.h>
//有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student".
//要求：不能使用库函数。
int strlenn(char *str){
	int length = 0;
	for(int i = 0;str[i] != '\0';i++ ){
		length++;
	}
	return length;
}
void inputij_to_str(char* str,char* strr,int i,int j,int length){
	
	for(int stri = i + 1;stri < j;stri++){//将str（i，j）的元素放入strr中
		for(int strri = 0;strri < length+1;strri++){
			if(strr[strri] == '\0'){//找到第一个'\0'赋值并跳出；
				strr[strri] = str[stri];
				break;
			}
		}
	}
	for(int strri = 0;strri < length+1;strri++){//将str（i，j）的元素放入strr后根据情况放入‘ ’
			if(strr[strri] == '\0' && strri != length){//找到第一个‘\0’看情况赋值并挑出
				strr[strri] = ' ';
				break;
			}

	}
}
int main(){
	//定义一个字符型数组 存放字符串
	char str[]="student a am i";
	//用一个函数计算出字符数组的长度
	int length = strlenn(str);
	//在申请一个同样长度的字符数组
	char* strr = (char *)malloc((length+1) * sizeof(char));
	for(int i = 0;i < length+1;i++){
		strr[i] = '\0';
	}
	//设置两个变量i，j都代表原字符数组的下标，str将(i,j)之间的元素给strr
	for(int i = length - 1,j = length;i >= -1;i--){
		if(str[i] == ' ' || i == -1){
			inputij_to_str(str,strr,i,j,length);//str将(i,j)之间的元素给strr		
			j=i;
		}
	}
	//将strr[]的值全部给str；然后释放掉strr的空间
	for(int i = 0;i <= length;i++){
		str[i]=strr[i];
	}
	free(strr);
	printf("%s",str);
	system("pause");
	return 0;
}