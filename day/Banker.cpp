#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int x = 0;//����λ��
int y = 0;
void gotoxy(short y,short x){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Init_data(int***,int***,int**,int*size);//���������Ϣ
bool security_check(int**,int**,int* size,int* avaible,int* secure);//��ȫ�Լ���㷨
void copy_data(int*** ,int **,int* size);//���������󿽱��� work_all,work_need 
void banker(int** allocation,int** need,int* avaible,int* size);//���м��㷨
int Init_request(int* request,int* size);//�������Դ
bool work_bigger_need(int* work,int* need,int* size);//�ж�work �Ƿ񶼴��� need[n];
int main(){
	int** allocation = NULL;//�ѷ���
	int** need = NULL;//��Ҫ
	int* request = NULL;//����
	int* avaible = NULL;//�ɻ��
	int* size = (int*)malloc(2 * sizeof(int));//size[0]���̵ĸ�����size[1]��Դ������
	
	Init_data(&allocation ,&need,&avaible,size);
	banker(allocation,need,avaible,size);
	system("pause");
	return 0;
}
void Init_data(int*** allocation,int*** need,int** avaible,int* size){//���������Ϣ
	int num_program = 0;//������̵ĸ���
	int num_source = 0;//������̵ĸ���
	printf("��������̵ĸ��� ");
	scanf("%d",&num_program);
	printf("��������Դ�ĸ��� ");
	scanf("%d",&num_source);
	size[0] = num_program;
	size[1] = num_source;
	(*allocation) = (int** )malloc(num_program * sizeof(int *));
	(*need) = (int** )malloc(num_source * sizeof(int *));
	(*avaible) = (int*) malloc(num_source * sizeof(int));
	printf("allocation����\n");
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
	for(int p = 0; p < num_program;p++){//����allocation����
		(*allocation)[p] = (int*)malloc(num_source * sizeof(int));
		for(int s = 0; s < num_source;s++){
			y = y + 4; 
			gotoxy(x,y);
			scanf("%d",&(*allocation)[p][s]);
		}
		x++;
		y = 0;
	}
	printf("need����:\n");
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
	for (int p = 0; p < num_program;p++){//����need����
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
	for(int s = 0;s < num_source;s++){//����avaible
		gotoxy(x,y);
		scanf("%d",&(*avaible)[s]);
		y = y + 3;
	}
}
bool work_bigger_need(int* work,int* need,int* size){//work ��ֵ���� need ����true
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
	//����һ������done���ȵ��� ���̵ĸ�����ߴ��(��ʼ��Ϊ0)��ʾ�ý��̶���û�д����
	int* done = (int*)malloc(size[0] * sizeof(int));//����ռ�
	for(int p = 0;p < size[0];p++){//��ʼ��
		done[p] = 0;
	}
	//�������count ��ʾ��ǰ�Ѿ�����Ľ��̸��� ��ֵΪ��
	int count = 0;
	while(1){
		int have = 0;//����while�Ƿ��������
		for(int p = 0;p < size[0];p++){
			if(done[p] == 0 && work_bigger_need(work,work_need[p],size)){
				for(int s = 0;s < size[1];s++){// �ѵ�p���̵�work_allocation ��work���
					work[s] += work_allocation[p][s];
				}
				done[p] = 1;//��p�������Ѿ�������
				have = 1;//���˴��������
				secure[count] = p;
				count++;//�Ѵ�����̼�һ
			}
		}
		if(have == 0){//����û�д��������
			if (count == size[0]){//״̬��ȫ
				return true;
			}else{//�Ѿ�û�н��̿��Դ����� ���ǻ��н���û��������ȫ��
				return false;
			}//Сif
		}//��if
	}
}
int Init_request(int* request,int* size){//������Դ
	int num = 0;
	printf("p");
	x = x +1;
	y = 1;
	gotoxy(x,y);
	scanf("%d",&num);
	printf("request:\n");
	x = x +2;
	y = 0;
	for(int i = 0;i < size[1];i++){//size[1]����Դ����
		gotoxy(x,y);
		scanf("%d",&request[i]);
		y = y + 3;	}
	return num;//�����ǵڼ�����Դ�������
}
void copy_data(int*** p1,int** p2,int* size){//p2���󿽱���p1
	if(*p1 == NULL){//���ڶ�*p1�ĳ�ʼ��
		(*p1) = (int **)malloc(size[0]*sizeof(int*));
		for(int pro = 0; pro < size[0];pro++){
			(*p1)[pro] = (int*)malloc(size[1] * sizeof(int));
			for(int s = 0;s < size[1];s++){
				(*p1)[pro][s] = p2[pro][s];
			}
		}
	}else{//*p1�Ѿ�����
		for(int pro = 0; pro < size[0];pro++){
			for(int s = 0;s < size[1];s++){
				(*p1)[pro][s] = p2[pro][s];
			}
		}
	}
}
bool smaller_av_need(int* need,int* request,int* avaible,int* size){//�ж� request�Ƿ�С�ڵ��ڣ�avaible�͸ý��̵�need
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
	int p = Init_request(request,size);//���صڼ�������������Դ
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
		if(security_check(work_allocation,work_need,size,avaible,secure)){//��ǰ״̬��ȫ
			for(int i = 0;i < size[0];i++){//�����ȫ����
				printf("p%d",secure[i]);
			}
			copy_data(&work_allocation,allocation,size);
			copy_data(&work_need,need,size);
		}else{//��ǰ״̬����ȫ
			printf("�����״̬����ȫ");
		}
	}else{
		printf("���ܷ������Դ");
	}
}