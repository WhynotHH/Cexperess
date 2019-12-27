#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//��ͷ�������ʵ��;
typedef int DataType;
typedef struct SListNode{// �ṹ��SListNode������������ͷ�������ÿ���ڵ㣨�ڵ������ ����һ���ڵ�ĵ�ַ����
	struct SListNode* next;
	DataType data;
}SListNode,*PListNode;
void SListInit(PListNode* list){// �����ʼ��
	*list = (PListNode)malloc(sizeof(SListNode));//ͷ���
	(*list) ->next = NULL;
}
PListNode BuyNewNode(DataType data){//����һ���½ڵ� 
	PListNode PNode = (PListNode)malloc(sizeof(SListNode));
	if(PNode){//����ɹ�
		PNode ->data = data;
		PNode ->next = NULL;
		return PNode;
	}else{
		printf("BuyNewNode failed\n");
		return NULL;
	}

}
void PrintfList(PListNode Phead){//��ӡ����
	assert(Phead);
	PListNode ptr = Phead ->next;
	if(ptr == NULL){
		printf("����һ��������");
	}else{
		while(ptr){
			printf("%d->",ptr ->data);
			ptr = ptr ->next;
		}
		printf("\n");
	}
}
void SListPushBack(PListNode Phead, DataType data){//β��
	assert(Phead);
	while(Phead ->next){//�ҵ����һ��Ԫ��
		Phead = Phead ->next;
	}
	Phead ->next = BuyNewNode(data);
}
void SListPopBack(PListNode Phead){//βɾ
	assert(Phead);
	PListNode ptr = Phead;
	PListNode bptr = NULL;
	while(ptr ->next){
		bptr = ptr;
		ptr = ptr ->next;
	}
	if(bptr){
		bptr ->next = NULL;
		free(ptr);
	}else{//����Ϊ��
		printf("û��Ԫ�ؿ���ɾ����");
	}	
}
void SListPushFront(PListNode Phead, DataType data){// ͷ��
	assert(Phead);
	PListNode ptr = BuyNewNode(data);
	ptr ->next = Phead ->next;
	Phead ->next = ptr;
}
void SListPopFront(PListNode Phead){//ͷɾ
	assert(Phead);
	if(Phead ->next){
		PListNode ptr = Phead ->next;
		Phead ->next = ptr ->next;
		free(ptr);
	}else{
		printf("û�п���ɾ����Ԫ��");
	}
}
PListNode ListFind(PListNode Phead, DataType data){//����data
	PListNode ptr = Phead ->next;
	while(ptr){// ����ǿ�����ִ��ѭ��������NULL��
		if (ptr ->data == data){
			break;
		}
		ptr = ptr ->next;
	}
	return ptr;
}
bool ListInsert(PListNode Phead, PListNode pos, DataType data){//��posλ�ò��� data
	if(Phead == NULL || Phead ->next == NULL){//����Ϊ��
		return false;
	}
	PListNode ptr = Phead ->next;
	PListNode bptr = Phead;
	while(ptr){ //Ϊ�մ��� û���ҵ�pos
		if(ptr == pos){
			bptr ->next = BuyNewNode(data);
			bptr = bptr ->next;
			bptr ->next = ptr;
			break;
		}
		bptr = ptr;
		ptr = ptr ->next;
	}
	
	if(ptr == NULL){//û���ҵ�pos λ��
		return false;
	}else{//����ɹ�
		return true;
	}
	
}
bool ListErase(PListNode Phead, PListNode pos){//ɾ��posλ�õĽڵ�
	if(Phead == NULL || Phead ->next ==NULL){
		return false;
	}
	PListNode ptr = Phead ->next;
	PListNode bptr = Phead;
	while(ptr){
		if(ptr == pos){
			bptr ->next = ptr ->next;
			free(ptr);
			break;
		}else{
			bptr = ptr;
			ptr =ptr ->next;	
		}
	}
	if(ptr == NULL){
		return false;
	}else{
		return true;
	}
	
}
void ListDestroy(PListNode* Phead){//ɾ������
	assert(Phead);
	if((*Phead) == NULL){
		return ;
	}
	PListNode ptr = *Phead;
	PListNode pdestory = ptr;
	while(ptr){
		ptr = ptr ->next;
		free(pdestory);
		pdestory = ptr;
	}
	*Phead = NULL;         //�������*Phead ����Ұָ��
}
int main(){
	PListNode Phead;
   system("pause");
}