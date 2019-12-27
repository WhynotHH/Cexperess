#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//无头单链表的实现;
typedef int DataType;
typedef struct SListNode{//结点
	struct SListNode* next;
	DataType data;
}SListNode,*PListNode;
void SListInit(PListNode* Phead){// 链表初始化
	(*Phead) = NULL;
}
PListNode BuyNewNode(DataType data){//创建一个新节点 
	PListNode PNode = (PListNode)malloc(sizeof(SListNode));
	if(PNode){//申请成功
		PNode ->data = data;
		PNode ->next = NULL;
		return PNode;
	}else{
		printf("BuyNewNode failed\n");
		return NULL;
	}

}
void PrintfList(PListNode Phead){//打印链表
	if(Phead == NULL){
		printf("这是空链表");
	}else{
		PListNode ptr = Phead;
		while(ptr){
			printf("%d->",ptr ->data);
			ptr = ptr ->next;
		}
		printf("\n");
	}
}
void SListPushBack(PListNode* Phead, DataType data){//尾插
	assert(Phead);
	if(*Phead == NULL){
		(*Phead) = BuyNewNode(data);
	}else{
		PListNode ptr = (*Phead);
		while(ptr ->next){//找到链表最后一个元素
			ptr  = ptr ->next;
		}
		ptr ->next = BuyNewNode(data);
	}
}
void SListPopBack(PListNode* Phead){//尾删
	assert(Phead);
	if((*Phead) == NULL){
		printf("没有元素可以删除了");
	}else{//链表至少有一个节点
		PListNode ptr = *Phead;
		PListNode bptr = NULL;//bptr的初始值为第零个节点 
		while(ptr ->next){// 使得 ptr指向最后一个结点 bptr 为倒数第二个节点
			bptr = ptr;
			ptr = ptr ->next;
		}
		if(bptr){//链表至少有两个元素（改变 bptr ->next）
			bptr ->next =NULL;
			free(ptr);
		}else{//链表只有一个元素(改变（*Phead）)
			(*Phead) = NULL;
			free(ptr);
		}
	}
}
void SListPushFront(PListNode* Phead, DataType data){// 头插
	assert(Phead);
	PListNode ptr = BuyNewNode(data);
	ptr ->next = (*Phead);
	(*Phead) = ptr;
}
void SListPopFront(PListNode* Phead){//头删
	assert(Phead);
	if(*Phead){//至少有一个元素
		PListNode ptr = (*Phead);
		(*Phead) = ptr ->next;
		free(ptr);
	}else{
		printf("没有可以删除的元素");
	}
}
PListNode ListFind(PListNode Phead, DataType data){//查找data
	PListNode ptr = Phead;
	while(ptr){// 如果是空链表不执行循环，返回NULL；
		if (ptr ->data == data){
			break;
		}
		ptr = ptr ->next;
	}
	return ptr;
}
bool ListInsert(PListNode* Phead, PListNode pos, DataType data){//在pos位置插入 data
	
	if((*Phead) == NULL || Phead == NULL){//链表为空
		return false;
	}
	PListNode ptr = *Phead;
	PListNode bptr = ptr;
	if(ptr == pos){//插入链表的第一个位置 需要改变(*Phead)
		(*Phead) = BuyNewNode(data);
		(*Phead) ->next = ptr;
	}else{
		ptr = ptr ->next;
		while(ptr){ //为空代表 没有找到pos
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
	if(ptr == NULL){//没有找到pos 位置
		return false;
	}else{//插入成功
		return true;
	}
}
bool ListErase(PListNode* Phead, PListNode pos){//删除pos位置的节点
	assert(Phead);
	if(*Phead == NULL){
		return false;
	}
	PListNode ptr = *Phead;
	PListNode bptr = ptr;
	if(ptr == pos){//如果是删除链表的第一个节点
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
void ListDestroy(PListNode* Phead){//删除链表
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
	*Phead = NULL;         //如果忘记*Phead 会变成野指针
}
int main(){
	PListNode Phead;
	system("pause");

}

