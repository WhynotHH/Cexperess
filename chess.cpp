#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define MAX_ROW 15
#define MAX_COL 15
void inte(char chessboard[][MAX_COL]);//���̵ĳ�ʼ��
void print_chess_board(char chessboard[][MAX_COL]);//print������ӡ����
int computer_fall_chess(char chessboard[][MAX_COL]);//��������
int player_fall_chess(char chessboard[][MAX_COL]);//�������
int Is_end(char chessboard[][MAX_COL],int count);//�ж��Ƿ�����������
void play_game(char chessboard[][MAX_COL]);//������Ϸ
void goto_xy(int ,int );
int main(){
	srand(time(0));//��ʱ�����Ϊ�������
	//����15*15�������������
	char chessboard[15][15];
	//inite�����������ʼ��
	inte(chessboard);
	//print������ӡ����
	print_chess_board(chessboard);
	play_game(chessboard);
	system("pause");
	return 0;
}


void play_game(char chessboard[][MAX_COL]){
	//����һ��count������Ӧÿ�����ӵ�λ�ã��Ա����Ƿ�����������
	int count=0;
	//����һ��end������¼��Ϸ�Ƿ����
	int end=0;
	int winner = -1;
	while(1){
		//player_fall_chesswan�������
		count=player_fall_chess(chessboard);
		//��ӡ����
		print_chess_board(chessboard);
		//Is_end�����ǲ�������������
		end=Is_end(chessboard,count);
		if(end){
			winner=1;
			break;
		}

		//��������	player_fall_chess(chessboard);
		count=computer_fall_chess(chessboard);
		//Is_end�����ǲ�������������
		end=Is_end(chessboard,count);
		//��ӡ����
		print_chess_board(chessboard);
		if(end){
			winner=0;
			break;
		}
	}
	if(winner){
	printf("��ϲ����ʤ��\n");
	}else{
	printf("���ź�������\n");
	}
}
int Is_end(char chessboard[][MAX_COL],int count){//�ж��Ƿ�����������
//����count��ֵ�����ϴ����ӵ�λ�������Ա��Ƿ�����������

	//�ҵ��ϴ����ӵ�rowֵ��colֵ
	int ret=0;//����ֵ
	int row=0;
	int col=-1;
	for(int i = 0;i <= count ;i++){
		col++;
		if(col == MAX_COL){
			col = 0;
			row++;
		}
		
	}
	
	int col1 = 0;
	int row1 = 0;
	int cunt=0;
	while(col1 < MAX_COL){//�жϸ� �� �Ƿ����������
		if(chessboard[row][col1] == chessboard[row][col]){
			cunt++;
		}else{
			cunt=0;
		}
		if(cunt == 5){ 
			ret = 1;
			break;
		}
		col1++;
	}

	col1 = col;
	row1 = 0;
	cunt=0;
	while(row1 < MAX_ROW){//�жϸ� �� �Ƿ����������
		if(chessboard[row1][col] == chessboard[row][col]){
			cunt++;
		}else{
			cunt=0;
		}
		if(cunt == 5){ 
			ret = 1;
			break;
		}
		row1++;
	}	
	
	col1=col;
	row1 = row;
	cunt=0;
	while(col1 != 0 && row1 != MAX_ROW-1){//�ҵ���/������߽����½ǵĽ���Ԫ�ص�row colֵ������ col1��row1
			col1=col1-1;
			row1=row1+1;
		}
	while(col1 != MAX_COL && row1 != -1){//����/�����ߴ��������ߣ����������������һ���͸ı䷵��ֵ ���� break
		if(chessboard[row1][col1] == chessboard[row][col]){
			cunt++;
		}else{
			cunt=0;
		}
		if(cunt == 5){ //�������������ͬ
			ret = 1;
			break;
		}
		row1--;//�����½������Ͻ���
		col1++;
	}
	
	col1 = col;
	row1 = row;
	cunt = 0;
	while(col1 != 0 && row1 != 0){//�ҵ���\������߽����ϽǵĽ���Ԫ�ص�row colֵ������ col1��row1
			col1=col1-1;
			row1=row1-1;
		}
	while(col1 != MAX_COL && row1 != MAX_ROW){
		if(chessboard[row1][col1] == chessboard[row][col]){
			cunt++;
		}else{
			cunt=0;
		}
		if(cunt == 5){ 
			ret = 1;
			break;
		}
		row1++;//�����Ͻ������½���
		col1++;
	}
	return ret;
}

void inte(char chessboard[][MAX_COL]){//���̵ĳ�ʼ��

	for(int row = 0;row < MAX_ROW;row++){
		for(int col =0;col < MAX_COL; col++){
			chessboard[row][col]=' ';
		}
	}

}
void print_chess_board(char chessboard[][MAX_COL]){     //����Ϊchar* chessboard,char chessboard[][]�������⣿
	system("cls");
	for(int row = -1;row < MAX_ROW; row++){
		if(row == -1){
			for(int col = -2;col <= MAX_COL;col++){
				
				if(col == -1){
					printf("|");
				}else if(col == -2){
					printf("  ");
				}else if(col == MAX_COL){
					printf("\n");
				}else{
					if(col < 10){
						printf("-%d-|",col);
					}else{
						printf("-%d|",col);
					}
				}//else
			}//for
			for(int col =-2; col <= MAX_COL;col++){
				if(col == -1){
					printf("|");
				}else if(col == -2){
					printf("��");
				}else if(col == MAX_COL){
					printf("\n");
				}else{
					printf("---|");
				}//else
			}
		}else{
			for(int col = -2; col <=MAX_COL; col++){
				if(col == -1){
					printf("|");
				}else if(col == -2){
					if(row < 10){
						printf(" %d",row);
					}else{
						printf("%d",row);
					}
				}else if(col == MAX_COL){
					printf("\n");
				}else{
					printf(" %c |",chessboard[row][col]);
				}
			}
			for(int col = -2;col <= MAX_COL;col++){
				if(col == -1){
					printf("|");
				}else if(col == -2){
					printf("��");
				}else if(col == MAX_COL){
					printf("\n");
				}else{
					printf("---|");
				}
			}
		 }//else
	}//for
}
void goto_xy(int x,int y){
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos ={ x,y };
	SetConsoleCursorPosition(hOut,pos);
}
int player_fall_chess(char chessboard[][MAX_COL]){//l�������
	int x=4,y=2;//���ӵ�λ��
	int col=0,row=0; 
	goto_xy(x,y);
	while(1){
		char position = (char)_getch();
		if(position == 'w'){
			if(y >= 4){
				y-=2;
			}
		}else if(position == 's'){
			if(y <= 28){
				y+=2;
			}
		}else if(position == 'd'){
			if( x<= 56){
				x+=4;
			}
		}else if(position == 'a'){
			if(x >= 8){
				x-=4;
			}
		}else if(position = ' '){
			col=(x/4)-1;
			row=(y-2)/2;
			chessboard[row][col]='O';
			break;
		}
		goto_xy(x,y);
	
	}
	
	
	return 	col+row*MAX_COL;
}
int computer_fall_chess(char chessboard[][MAX_COL]){	//��������
/*	
//�����㷨��Ȼ�򵥵��������ϵ�����Խ�� ���Ӿ���Ҫ�����ѭ��
	while(1){
		row = rand() % 15;
		col = rand() % 15;
		if(chessboard[row][col] == ' '){
			chessboard[row][col] = 'X';
			break;
		}
	}
*/
	
	int row=0,col=0;//���ӵ�λ��
	int empty = 0;//�����Ͽյĸ���
	for(int i = 0; i < MAX_ROW; i++){
		for(int j = 0; j < MAX_COL; j++){
			if(chessboard[i][j] == ' '){
				empty++;
			}
		}
	}
	empty = rand()%empty;//���������ĸ��ո�
		
	int count = -1;//��ʾ��ǰ�ǵڼ����� ��Ԫ��
	int sum = -1;//Ԫ�ؼ�¼���ӵĵط�������ĵڼ���Ԫ�أ����ڲ��forѭ��ÿ����һ�ξͼ�һ��
	for(int row1 = 0; row1 < MAX_ROW; row1++){
		int col1 = 0;
		for(; col1 < MAX_COL; col1++){
			//count����һ�Ρ� ���ͻ��һ
			//countһֱ�ӵ���empty���� �������ӣ�
			//sumÿ��ѭ��һ�ξͻ��һ ����ʾ���㿪ʼ�����ǵڼ���Ԫ�أ�
			
			sum++;//��ǰ�ǵڼ���Ԫ��
			if(chessboard[row1][col1]==' '){
			count++;//��ǰ�ǵڼ�����Ԫ��
			}
			if(chessboard[row1][col1]==' ' && count == empty){
				chessboard[row1][col1]='x';//��������
				break;//�ڵ�empty���� ������ֵ������
			}
		
		}
		
		if(chessboard[row1][col1]=='x' && count == empty){
			break;//�ڵ�empty���� ��Ԫ�ش���ֵ��������
		}
	}
	return sum;	
}

