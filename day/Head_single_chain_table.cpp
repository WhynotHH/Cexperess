#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//有头单链表的实现;
typedef int DataType;
typedef struct SListNode{// 结构体SListNode用来描述：无头单链表的每个节点（节点的数据 ，下一个节点的地址）；
	struct SListNode* next;
	DataType data;
}SListNode,*PListNode;
void SListInit(PListNode* list){// 链表初始化
	*list = (PListNode)malloc(sizeof(SListNode));//头结点
	(*list) ->next = NULL;
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
	assert(Phead);
	PListNode ptr = Phead ->next;
	if(ptr == NULL){
		printf("这是一个空链表");
	}else{
		while(ptr){
			printf("%d->",ptr ->data);
			ptr = ptr ->next;
		}
		printf("\n");
	}
}
void SListPushBack(PListNode Phead, DataType data){//尾插
	assert(Phead);
	while(Phead ->next){//找到最后一个元素
		Phead = Phead ->next;
	}
	Phead ->next = BuyNewNode(data);
}
void SListPopBack(PListNode Phead){//尾删
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
	}else{//链表为空
		printf("没有元素可以删除了");
	}	
}
void SListPushFront(PListNode Phead, DataType data){// 头插
	assert(Phead);
	PListNode ptr = BuyNewNode(data);
	ptr ->next = Phead ->next;
	Phead ->next = ptr;
}
void SListPopFront(PListNode Phead){//头删
	assert(Phead);
	if(Phead ->next){
		PListNode ptr = Phead ->next;
		Phead ->next = ptr ->next;
		free(ptr);
	}else{
		printf("没有可以删除的元素");
	}
}
PListNode ListFind(PListNode Phead, DataType data){//查找data
	PListNode ptr = Phead ->next;
	while(ptr){// 如果是空链表不执行循环，返回NULL；
		if (ptr ->data == data){
			break;
		}
		ptr = ptr ->next;
	}
	return ptr;
}
bool ListInsert(PListNode Phead, PListNode pos, DataType data){//在pos位置插入 data
	if(Phead == NULL || Phead ->next == NULL){//链表为空
		return false;
	}
	PListNode ptr = Phead ->next;
	PListNode bptr = Phead;
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
	
	if(ptr == NULL){//没有找到pos 位置
		return false;
	}else{//插入成功
		return true;
	}
	
}
bool ListErase(PListNode Phead, PListNode pos){//删除pos位置的节点
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
void ListDestroy(PListNode* Phead){//删除链表
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
	*Phead = NULL;         //如果忘记*Phead 会变成野指针
}
int main(){
	PListNode Phead;
   system("pause");
}