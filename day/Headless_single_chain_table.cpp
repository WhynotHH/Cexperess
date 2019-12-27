#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//��ͷ�������ʵ��;
typedef int DataType;
typedef struct SListNode{//���
	struct SListNode* next;
	DataType data;
}SListNode,*PListNode;
void SListInit(PListNode* Phead){// �����ʼ��
	(*Phead) = NULL;
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
	if(Phead == NULL){
		printf("���ǿ�����");
	}else{
		PListNode ptr = Phead;
		while(ptr){
			printf("%d->",ptr ->data);
			ptr = ptr ->next;
		}
		printf("\n");
	}
}
void SListPushBack(PListNode* Phead, DataType data){//β��
	assert(Phead);
	if(*Phead == NULL){
		(*Phead) = BuyNewNode(data);
	}else{
		PListNode ptr = (*Phead);
		while(ptr ->next){//�ҵ��������һ��Ԫ��
			ptr  = ptr ->next;
		}
		ptr ->next = BuyNewNode(data);
	}
}
void SListPopBack(PListNode* Phead){//βɾ
	assert(Phead);
	if((*Phead) == NULL){
		printf("û��Ԫ�ؿ���ɾ����");
	}else{//����������һ���ڵ�
		PListNode ptr = *Phead;
		PListNode bptr = NULL;//bptr�ĳ�ʼֵΪ������ڵ� 
		while(ptr ->next){// ʹ�� ptrָ�����һ����� bptr Ϊ�����ڶ����ڵ�
			bptr = ptr;
			ptr = ptr ->next;
		}
		if(bptr){//��������������Ԫ�أ��ı� bptr ->next��
			bptr ->next =NULL;
			free(ptr);
		}else{//����ֻ��һ��Ԫ��(�ı䣨*Phead��)
			(*Phead) = NULL;
			free(ptr);
		}
	}
}
void SListPushFront(PListNode* Phead, DataType data){// ͷ��
	assert(Phead);
	PListNode ptr = BuyNewNode(data);
	ptr ->next = (*Phead);
	(*Phead) = ptr;
}
void SListPopFront(PListNode* Phead){//ͷɾ
	assert(Phead);
	if(*Phead){//������һ��Ԫ��
		PListNode ptr = (*Phead);
		(*Phead) = ptr ->next;
		free(ptr);
	}else{
		printf("û�п���ɾ����Ԫ��");
	}
}
PListNode ListFind(PListNode Phead, DataType data){//����data
	PListNode ptr = Phead;
	while(ptr){// ����ǿ�����ִ��ѭ��������NULL��
		if (ptr ->data == data){
			break;
		}
		ptr = ptr ->next;
	}
	return ptr;
}
bool ListInsert(PListNode* Phead, PListNode pos, DataType data){//��posλ�ò��� data
	
	if((*Phead) == NULL || Phead == NULL){//����Ϊ��
		return false;
	}
	PListNode ptr = *Phead;
	PListNode bptr = ptr;
	if(ptr == pos){//��������ĵ�һ��λ�� ��Ҫ�ı�(*Phead)
		(*Phead) = BuyNewNode(data);
		(*Phead) ->next = ptr;
	}else{
		ptr = ptr ->next;
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
	}
	if(ptr == NULL){//û���ҵ�pos λ��
		return false;
	}else{//����ɹ�
		return true;
	}
}
bool ListErase(PListNode* Phead, PListNode pos){//ɾ��posλ�õĽڵ�
	assert(Phead);
	if(*Phead == NULL){
		return false;
	}
	PListNode ptr = *Phead;
	PListNode bptr = ptr;
	if(ptr == pos){//�����ɾ������ĵ�һ���ڵ�
		*Phead = ptr ->next;
		free(ptr);
	}else{//
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
	}
	if(ptr ==NULL){
		return false;
	}else{
		return true;
	}
}
void ListDestroy(PListNode* Phead){//ɾ������
	if(Phead == NULL|| (*Phead) == NULL){
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

