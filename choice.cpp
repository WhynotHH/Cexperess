#include<stdio.h>
#include<stdlib.h>
/*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
嫌疑犯的一个。以下为4个嫌疑犯的供词。
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。*/
int main(){
	//定义一个4*3的字符数组，存放ABCD四个人认为可能是凶手的人
	char a[4][3]={{'B','C','D'},{'C'},{'D'},{'A','B','C'}};
	//定义一个字符变量 存放真正的凶手
	int num; 
	//定义一个变量，存放是谁说谎
	int b;
	//for循环中每次跳出一个人 剩下的人认为是凶的名单求共有的元素 如果存在既是凶手
	
	int ture =0;//ture表示是否在剩余的 三个字符数组中找到共有的元素（是否找到凶手）
	//for循环中每次跳出一个人 剩下的人认为是凶的名单求共有的元素 如果存在既是凶手
	for(int i = 0;i < 4;i++){
		int i1=i;
		int compare[3];
		
		for(int i2 = 0;i2 < 3;i2++){//将要比较的3组i的下标 分别放在数组compare[3]中
			if(i1 == 3){
				i1=-1;
			}
			i1++;
			compare[i2]=i1;
		}	
		
		for(int j = 0;j < 3;j++){//i=1 这个数组的每个元素遍历一遍 剩下两个数组如果有公共元素
			num = a[compare[0]][j]; 
			for(int jj = 0;jj < 3;jj++){//i=2每个元素
				if(a[compare[1]][jj] == num){
					for(int jjj = 0;jjj < 3;jjj++){
						if(a[compare[2]][jjj] == num){
							ture = 1;//找到凶手 当前的num就是凶手
							break;//找到凶手后跳出
						}
					}
				}
				if(ture == 1){//找到凶手跳出
					break;
				}
			}
			if(ture == 1){//找到凶手跳出
				break;
			}
		}
	if(ture == 1){//如果找到凶手把说谎的人的下标放在b中并跳出
		b=i;
		break;
	}
	
	}
	//如果 求得的交集只有一个元素那么挑出的那个人说了假话 唯一的元素就是凶手
	
	//输出谁说谎
	switch(b){
	case 0:printf("A说谎\n");break;
	case 1:printf("B说谎\n");break;
	case 2:printf("C说谎\n");break;
	case 3:printf("D说谎\n");break;
	}
	//输出凶手
	printf("凶手是%c\n",num);
	system("pause");
	return 0;
}