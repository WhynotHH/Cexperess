#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<cassert>
size_t mystrlen (const char* str){
	assert(str != NULL);//����ΪNULL������ж�
	size_t length = 0;
	while(*str++){ //*str++
		length++;
	}
	return length;
}
char* mystrcpy (char* destination, const char* source){
	assert(destination != NULL);
	assert(source != NULL);
	char *result = destination;//����destination�ַ������׵�ַ������Ϊ����ֵ
	while(*destination++ = *source++);//��ֵ���ʽ�ķ���ֵΪ��ߵ�ֵ����(*destination++)��
	return result;
}
char* mystrcat (char* destination, const char* source){
	assert(destination != NULL);
	assert(source != NULL);
	char* result = destination;
	while(*destination){
		destination++; 
	};//ʹ��destinationָ���ַ����ַ�Ϊ'\0'��
	while(*destination++ = *source++);
	return result;
}
int mystrcmp1 ( const char* destination, const char * source ){
	 int ret = 0 ;   
	 assert(source != NULL);      
	 assert(destination != NULL);
	 while(!(ret = *((unsigned char*) destination) - *((unsigned char*) source)) && * destination){
		 destination++;
		 source++;
	 }
	 if(ret > 0){
		return 1;
	 }else if(ret < 0){
		return -1;
	 }else{
		return ret;
	 }
} 
int mystrcmp2 ( const char* destination, const char * source ){
	//mystrcmp1���׶��ԱȽϲ����̣�
	//mystrcmp1���׶��ԱȽϺã����볤��
	 assert(source != NULL);      
	 assert(destination != NULL);
	 unsigned char* str1 = (unsigned char*)destination;
	 unsigned char* str2 = (unsigned char*)source;
	 while(*str1 && *str2){
		 if(*str1 > *str2){
			return 1;
		 }else if(*str1 <*str2){
			return -1;
		 }else{
			str1++;
			str2++;
		 }
	 }
	if(*str1 > *str2){
		return 1;
	 }else if(*str1 < *str2){
		return -1;
	 }else{
		return 0;
	 }
}
char* mystrncpy (char* destination, const char* source,int num){
	assert(destination != NULL);
	assert(source != NULL);
	char *result = destination;//����destination�ַ������׵�ַ������Ϊ����ֵ
	while((*destination++ = *source++) && num--){
		if(num == 0){
			*destination = '\0';
			break;
		}
	};//��ֵ���ʽ�ķ���ֵΪ��ߵ�ֵ����(*destination++)��
	return result;
}
char* mystrstr(const char* destination,const char* source){
	while(*destination != '\0'){
		const char* dest = destination;
		const char* sour =source;
		while( ( *sour != '\0') ){
			if(*dest != *sour){
			break;
			}
			dest++;
			sour++;
		}
		//�����������ԭ��
		//(1)*dest != *sour 
		//(2)*sour == '\0'
		
		if((*sour) == '\0'){//(2)*sour == '\0'
			return (char*)destination;
		}else{//(1)*dest != *sour 
			destination++;
		}
	
	}
	return NULL;
}
typedef struct student{
	char name[10];
	int age;
}student;
void* mymemcpy ( void* destination, const void* source, size_t count ) {//memcpy ���ܵ�����������ָ��
	assert(destination);
	assert(source);
	char* dest = (char*) destination;
	char* sour = (char*) source;
	for(size_t i = 0;i < count; i++){
		*(dest+i) = *(sour + i);
	}
	return destination;
}
void* mymemmove ( void* destination, const void* source, size_t count ){
	//memove ��Ϊ�˽�� memcpy���ڴ��ص����� 
	assert(destination);
	assert(source);
	char* dest = (char*) destination;
	char* sour = (char*) source;
	if(dest <= sour){ //Ŀ��ռ��׵�ַ<=ԭ�ռ��׵�ַ(����ǰ�ص������ص�)
		for(size_t i = 0;i < count; i++){//��ǰ���󿽱�
			*(dest + i) = *(sour + i);
		}
	}else{//Ŀ��ռ��׵�ַ>ԭ�ռ��׵�ַ(���ܺ��ص������ص�)
		for(size_t i = count - 1;i >= 0; i++){//�Ӻ���ǰ����
			*(dest + i) = *(sour + i);
		}
	}
	return destination;
}
int main(){
	char str1[] = "abcd";
	char str2[] = "aaaabc";
	char str3[]="";
	student s1 = {"abcd",18};
	student s2;
	//mystrncpy(str1,str2,2);
	//mystrcat(str1,str2);
	//printf("%d\n",mystrcmp1 (str1,str2));
	//printf("%d\n",mystrcmp2 (str1,str2));
	//printf("%s",str1);
	//printf("%p",mystrstr(str2,str3));
	mymemmove(&s2, &s1, sizeof(student));
	system("pause");
	return 0;
 }