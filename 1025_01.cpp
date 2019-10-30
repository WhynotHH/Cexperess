#include<stdio.h>
#include<stdlib.h>
/*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果A选手说：B第二，我第三；B选手说：我第二，E第四；
C选手说：我第一，D第二；D选手说：C最后，我第三；E选手说：我第四，A第一；比赛结束后，每位选手都说对了一半，
请编程确定比赛的名次。*/
int main(){
	char right[5]={' ',' ',' ',' ',' '};//最终的比赛名次
	//二维数组表示ABCDE预测的顺序，没有预测的位置用‘ ’表示
	char squence[5][5]={{' ','B','A',' ',' '},{' ','B',' ','E',' '},{'C','D',' ',' ',' '},{' ',' ','D',' ','C'},{'A',' ',' ','E',' '}};
	
	
	//每个人都预测了两个结果，用0表示抽取某个人预测第一个结果,1表示抽取某人预测的第二个结果。
	//用一个choice变量的二进制后五位，表示从五个人的，两个结果抽取一个组并成一个顺序序列
	//他的二进制表示为 ......00000 后五位分别表示ABCDE预测的第1个结果正确（因为初值都是0）
	//choice每加一就会指定一组不同的序列
	int choice = 0;//初始的二进制后五位为00000表示抽取五个人与此结果的第一种并组成一个比赛序列 
	while(1){ //直到choice指定的序列正确就结束
		int count = 0;//用于检查每次choice指定的序列是否将right[]填满 
		int ture = 1;//用于检查每次choice指定的序列是否每一位的元素都不同
		int bite=1;//......00001
		
		//抽取五个人每两种结果的一个，放在right[]组成一种序列 
		for(int i =0;i < 5;i++){//i表示第几个人
		
			 if((bite << i) & choice){//结果大于0表示取第二个结果()
				 for(int j=4;j >= 0;j--){
					 if(squence[i][j] != ' '){
						right[j] = squence[i][j]; 
						break;
					 }
				 }
			 }else{//结果等于0表示取第1个结果
				 for(int j = 0;j < 5;j++){
					 if(squence[i][j] != ' '){
						right[j] = squence[i][j]; 
						break;
					 }
				 }
			 }//else
		}//大for
		//查看最终的right数组是否排满（既是没有‘ ’）
		for(int j = 0;j < 5;j++){
			 if(right[j] ==' '){//如果right[]中有一个为‘ ’那么这组choice序列错误，将right[]全部置为‘ ’然后跳出for循环
				 for(int i = 0;i < 5;i++){
					right[i]=' ';
				 }
				break;
			 }else{
			 count++;//如果right[]没有‘ ’那么 for循环完了后count=5
			 }
		}
		//查看right[]数组中是否每个元素和其他元素都不同
		for(int i = 0;i < 5;i++){
			for(int j = i+1;j < 5;j++){
				 if(right[i]==right[j]){
					ture = 0;//表示right[]有元素是相同的
				 }
			 }
		 }
		
		 if(count == 5 && ture == 1){//如果count==5（填满)并且ture==1（right[]数组中每个元素都不相同）那么跳出while循环
			 break;//跳出while循环
		 }else{//否则choice++,进入下一个choice指定序列的检测
			choice++;
		 }
		
	}//while
	//输出正确的排序
	for(int i = 0;i < 5;i++){
		printf("%c",right[i]);
	}
	system("pause");
	return 0;
}