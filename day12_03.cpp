#include<stdio.h>
#include<stdlib.h>
//��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student".
//Ҫ�󣺲���ʹ�ÿ⺯����
int strlenn(char *str){
	int length = 0;
	for(int i = 0;str[i] != '\0';i++ ){
		length++;
	}
	return length;
}
void inputij_to_str(char* str,char* strr,int i,int j,int length){
	
	for(int stri = i + 1;stri < j;stri++){//��str��i��j����Ԫ�ط���strr��
		for(int strri = 0;strri < length+1;strri++){
			if(strr[strri] == '\0'){//�ҵ���һ��'\0'��ֵ��������
				strr[strri] = str[stri];
				break;
			}
		}
	}
	for(int strri = 0;strri < length+1;strri++){//��str��i��j����Ԫ�ط���strr�����������롮 ��
			if(strr[strri] == '\0' && strri != length){//�ҵ���һ����\0���������ֵ������
				strr[strri] = ' ';
				break;
			}

	}
}
int main(){
	//����һ���ַ������� ����ַ���
	char str[]="student a am i";
	//��һ������������ַ�����ĳ���
	int length = strlenn(str);
	//������һ��ͬ�����ȵ��ַ�����
	char* strr = (char *)malloc((length+1) * sizeof(char));
	for(int i = 0;i < length+1;i++){
		strr[i] = '\0';
	}
	//������������i��j������ԭ�ַ�������±꣬str��(i,j)֮���Ԫ�ظ�strr
	for(int i = length - 1,j = length;i >= -1;i--){
		if(str[i] == ' ' || i == -1){
			inputij_to_str(str,strr,i,j,length);//str��(i,j)֮���Ԫ�ظ�strr		
			j=i;
		}
	}
	//��strr[]��ֵȫ����str��Ȼ���ͷŵ�strr�Ŀռ�
	for(int i = 0;i <= length;i++){
		str[i]=strr[i];
	}
	free(strr);
	printf("%s",str);
	system("pause");
	return 0;
}