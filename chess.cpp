#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define MAX_ROW 15
#define MAX_COL 15
void inte(char chessboard[][MAX_COL]);//棋盘的初始化
void print_chess_board(char chessboard[][MAX_COL]);//print函数打印棋盘
int computer_fall_chess(char chessboard[][MAX_COL]);//电脑落子
int player_fall_chess(char chessboard[][MAX_COL]);//玩家落子
int Is_end(char chessboard[][MAX_COL],int count);//判断是否五子连成线
void play_game(char chessboard[][MAX_COL]);//进入游戏
void goto_xy(int ,int );
int main(){
	srand(time(0));//把时间戳设为随机种子
	//首先15*15的数组代表棋盘
	char chessboard[15][15];
	//inite函数给数组初始化
	inte(chessboard);
	//print函数打印棋盘
	print_chess_board(chessboard);
	play_game(chessboard);
	system("pause");
	return 0;
}


void play_game(char chessboard[][MAX_COL]){
	//定义一个count变量反应每次落子的位置，以便检测是否五子连成线
	int count=0;
	//定义一个end变量记录游戏是否结束
	int end=0;
	int winner = -1;
	while(1){
		//player_fall_chesswan玩家落子
		count=player_fall_chess(chessboard);
		//打印棋盘
		print_chess_board(chessboard);
		//Is_end检验是不是五子连成线
		end=Is_end(chessboard,count);
		if(end){
			winner=1;
			break;
		}

		//电脑落子	player_fall_chess(chessboard);
		count=computer_fall_chess(chessboard);
		//Is_end检验是不是五子连成线
		end=Is_end(chessboard,count);
		//打印棋盘
		print_chess_board(chessboard);
		if(end){
			winner=0;
			break;
		}
	}
	if(winner){
	printf("恭喜你获得胜利\n");
	}else{
	printf("很遗憾你输了\n");
	}
}
int Is_end(char chessboard[][MAX_COL],int count){//判断是否五子连成线
//借助count的值，在上次落子得位置找他旁边是否五子连成线

	//找到上次落子的row值和col值
	int ret=0;//返回值
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
	while(col1 < MAX_COL){//判断该 行 是否有五个连等
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
	while(row1 < MAX_ROW){//判断该 列 是否有五个连等
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
	while(col1 != 0 && row1 != MAX_ROW-1){//找到该/划线与边界左下角的交点元素的row col值并赋予 col1，row1
			col1=col1-1;
			row1=row1+1;
		}
	while(col1 != MAX_COL && row1 != -1){//沿着/该条线从下往上走，碰到连续五个棋子一样就改变返回值 并且 break
		if(chessboard[row1][col1] == chessboard[row][col]){
			cunt++;
		}else{
			cunt=0;
		}
		if(cunt == 5){ //连续五个棋子相同
			ret = 1;
			break;
		}
		row1--;//从左下角往右上角走
		col1++;
	}
	
	col1 = col;
	row1 = row;
	cunt = 0;
	while(col1 != 0 && row1 != 0){//找到该\划线与边界左上角的交点元素的row col值并赋予 col1，row1
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
		row1++;//从左上角往右下角走
		col1++;
	}
	return ret;
}

void inte(char chessboard[][MAX_COL]){//棋盘的初始化

	for(int row = 0;row < MAX_ROW;row++){
		for(int col =0;col < MAX_COL; col++){
			chessboard[row][col]=' ';
		}
	}

}
void print_chess_board(char chessboard[][MAX_COL]){     //参数为char* chessboard,char chessboard[][]出现问题？
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
					printf("—");
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
					printf("—");
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
int player_fall_chess(char chessboard[][MAX_COL]){//l玩家落子
	int x=4,y=2;//落子的位置
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
int computer_fall_chess(char chessboard[][MAX_COL]){	//电脑落子
/*	
//这种算法虽然简单但是棋盘上的棋子越多 落子就需要更多的循环
	while(1){
		row = rand() % 15;
		col = rand() % 15;
		if(chessboard[row][col] == ' '){
			chessboard[row][col] = 'X';
			break;
		}
	}
*/
	
	int row=0,col=0;//落子的位置
	int empty = 0;//棋盘上空的个数
	for(int i = 0; i < MAX_ROW; i++){
		for(int j = 0; j < MAX_COL; j++){
			if(chessboard[i][j] == ' '){
				empty++;
			}
		}
	}
	empty = rand()%empty;//电脑落在哪个空格处
		
	int count = -1;//表示当前是第几个‘ ’元素
	int sum = -1;//元素记录落子的地方是数组的第几个元素；（内层的for循环每进行一次就加一）
	for(int row1 = 0; row1 < MAX_ROW; row1++){
		int col1 = 0;
		for(; col1 < MAX_COL; col1++){
			//count碰到一次‘ ’就会加一
			//count一直加到第empty个‘ ’处落子；
			//sum每内循环一次就会加一 （表示从零开始现在是第几个元素）
			
			sum++;//当前是第几个元素
			if(chessboard[row1][col1]==' '){
			count++;//当前是第几个空元素
			}
			if(chessboard[row1][col1]==' ' && count == empty){
				chessboard[row1][col1]='x';//电脑落子
				break;//在第empty个‘ ’处赋值后跳出
			}
		
		}
		
		if(chessboard[row1][col1]=='x' && count == empty){
			break;//在第empty个‘ ’元素处赋值后跳出。
		}
	}
	return sum;	
}

