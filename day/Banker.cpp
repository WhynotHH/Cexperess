#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int x = 0;//光标的位置
int y = 0;
void gotoxy(short y,short x){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Init_data(int***,int***,int**,int*size);//输入矩阵信息
bool security_check(int**,int**,int* size,int* avaible,int* secure);//安全性检查算法
void copy_data(int*** ,int **,int* size);//将两个矩阵拷贝给 work_all,work_need 
void banker(int** allocation,int** need,int* avaible,int* size);//银行家算法
int Init_request(int* request,int* size);//请求的资源
bool work_bigger_need(int* work,int* need,int* size);//判断work 是否都大于 need[n];
int main(){
	int** allocation = NULL;//已分配
	int** need = NULL;//需要
	int* request = NULL;//请求
	int* avaible = NULL;//可获得
	int* size = (int*)malloc(2 * sizeof(int));//size[0]进程的个数，size[1]资源个数。
	
	Init_data(&allocation ,&need,&avaible,size);
	banker(allocation,need,avaible,size);
	system("pause");
	return 0;
}
void Init_data(int*** allocation,int*** need,int** avaible,int* size){//输入矩阵信息
	int num_program = 0;//输入进程的个数
	int num_source = 0;//输入进程的个数
	printf("请输入进程的个数 ");
	scanf("%d",&num_program);
	printf("请输入资源的个数 ");
	scanf("%d",&num_source);
	size[0] = num_program;
	size[1] = num_source;
	(*allocation) = (int** )malloc(num_program * sizeof(int *));
	(*need) = (int** )malloc(num_source * sizeof(int *));
	(*avaible) = (int*) malloc(num_source * sizeof(int));
	printf("allocation矩阵\n");
	for(int s = 0; s < size[1];s++){
		if(s == 0){
			printf("    ");
			printf("s%d",s);
		}else{
			printf("  ");
			printf("s%d",s);	
		}
	}
	x = 4;
	y = 0;
	gotoxy(x,y);
	for(int p = 0;p < size[0];p++){
		printf("p%d\n",p);
	}
	for(int p = 0; p < num_program;p++){//输入allocation矩阵
		(*allocation)[p] = (int*)malloc(num_source * sizeof(int));
		for(int s = 0; s < num_source;s++){
			y = y + 4; 
			gotoxy(x,y);
			scanf("%d",&(*allocation)[p][s]);
		}
		x++;
		y = 0;
	}
	printf("need矩阵:\n");
	for(int s = 0; s < size[1];s++){
		if(s == 0){
			printf("    ");
			printf("s%d",s);
		}else{
			printf("  ");
			printf("s%d",s);	
		}
	}
	x = x + 2;
	y = 0;
	gotoxy(x,y);
	for(int p = 0;p < size[0];p++){
		printf("p%d\n",p);
	}
	for (int p = 0; p < num_program;p++){//输入need矩阵
		(*need)[p] = (int*)malloc(num_source * sizeof(int));
		for(int s = 0; s < num_source;s++){
			y = y +4;
			gotoxy(x,y);
			scanf("%d",&(*need)[p][s]);
		}
		x++;
		y = 0;
	}
	
	printf("avaible:\n");
	x = x + 1;
	y = 0;
	for(int s = 0;s < num_source;s++){//输入avaible
		gotoxy(x,y);
		scanf("%d",&(*avaible)[s]);
		y = y + 3;
	}
}
bool work_bigger_need(int* work,int* need,int* size){//work 的值大于 need 返回true
	bool result = false;
	int s = 0;
	for(;s < size[1];s++){
		if(work[s] < need[s]){
			break;
		}
	}
	if(s == size[1]){
		return true;
	}else{
		return false;
	}
}

bool security_check(int** work_allocation,int** work_need,int* size,int* avaible,int* secure){
	int* work = (int*)malloc(size[1] * sizeof(int));
	for(int s = 0;s < size[1];s++){
		work[s] = avaible[s]; 
	}
	//定义一个数组done长度等于 进程的个数里边存放(初始都为0)表示该进程都还没有处理过
	int* done = (int*)malloc(size[0] * sizeof(int));//申请空间
	for(int p = 0;p < size[0];p++){//初始化
		done[p] = 0;
	}
	//定义变量count 表示当前已经满足的进程个数 初值为零
	int count = 0;
	while(1){
		int have = 0;//该趟while是否处理过进程
		for(int p = 0;p < size[0];p++){
			if(done[p] == 0 && work_bigger_need(work,work_need[p],size)){
				for(int s = 0;s < size[1];s++){// 把第p进程的work_allocation 与work相加
					work[s] += work_allocation[p][s];
				}
				done[p] = 1;//第p个进程已经被处理
				have = 1;//该趟处理过进程
				secure[count] = p;
				count++;//已处理进程加一
			}
		}
		if(have == 0){//该趟没有处理过进程
			if (count == size[0]){//状态安全
				return true;
			}else{//已经没有进程可以处理了 可是还有进程没处理（不安全）
				return false;
			}//小if
		}//大if
	}
}
int Init_request(int* request,int* size){//请求资源
	int num = 0;
	printf("p");
	x = x +1;
	y = 1;
	gotoxy(x,y);
	scanf("%d",&num);
	printf("request:\n");
	x = x +2;
	y = 0;
	for(int i = 0;i < size[1];i++){//size[1]是资源个数
		gotoxy(x,y);
		scanf("%d",&request[i]);
		y = y + 3;	}
	return num;//返回是第几个资源提出请求
}
void copy_data(int*** p1,int** p2,int* size){//p2矩阵拷贝到p1
	if(*p1 == NULL){//用于对*p1的初始化
		(*p1) = (int **)malloc(size[0]*sizeof(int*));
		for(int pro = 0; pro < size[0];pro++){
			(*p1)[pro] = (int*)malloc(size[1] * sizeof(int));
			for(int s = 0;s < size[1];s++){
				(*p1)[pro][s] = p2[pro][s];
			}
		}
	}else{//*p1已经存在
		for(int pro = 0; pro < size[0];pro++){
			for(int s = 0;s < size[1];s++){
				(*p1)[pro][s] = p2[pro][s];
			}
		}
	}
}
bool smaller_av_need(int* need,int* request,int* avaible,int* size){//判断 request是否小于等于，avaible和该进程的need
	bool result = false;
	int s = 0;
	for(; s < size[1];s++){
		if(!(request[s] <= need[s] && request[s] <=avaible[s])){
			break;
		}
	}
	if(s == size[1]){
		result = true;
	}else{
		result = false;
	}
	return result;
}
void banker(int** allocation,int** need,int* avaible,int* size){
	int* request = (int*)malloc(size[1]*sizeof(int));
	int p = Init_request(request,size);//返回第几个进程请求资源
	int** work_allocation = NULL;
	int** work_need = NULL;
	copy_data(&work_allocation,allocation,size);
	copy_data(&work_need,need,size);
	int* secure = (int*)malloc(size[0]*sizeof(int)); 
	if(smaller_av_need(need[p],request,avaible,size)){
		for(int s = 0;s < size[1];s++){// 
			work_allocation[p][s] += request[s];
			work_need[p][s] -= request[s];
			avaible[s] -= request[s];
		}
		if(security_check(work_allocation,work_need,size,avaible,secure)){//当前状态安全
			for(int i = 0;i < size[0];i++){//输出安全序列
				printf("p%d",secure[i]);
			}
			copy_data(&work_allocation,allocation,size);
			copy_data(&work_need,need,size);
		}else{//当前状态不安全
			printf("分配后状态不安全");
		}
	}else{
		printf("不能分配该资源");
	}
}