#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<cassert>
size_t mystrlen (const char* str){
	assert(str != NULL);//参数为NULL会产生中断
	size_t length = 0;
	while(*str++){ //*str++
		length++;
	}
	return length;
}
char* mystrcpy (char* destination, const char* source){
	assert(destination != NULL);
	assert(source != NULL);
	char *result = destination;//保存destination字符串的首地址，并作为返回值
	while(*destination++ = *source++);//赋值表达式的返回值为左边的值既是(*destination++)；
	return result;
}
char* mystrcat (char* destination, const char* source){
	assert(destination != NULL);
	assert(source != NULL);
	char* result = destination;
	while(*destination){
		destination++; 
	};//使得destination指向字符串字符为'\0'处
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
	//mystrcmp1的易读性比较差，代码短，
	//mystrcmp1的易读性比较好，代码长，
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
	char *result = destination;//保存destination字符串的首地址，并作为返回值
	while((*destination++ = *source++) && num--){
		if(num == 0){
			*destination = '\0';
			break;
		}
	};//赋值表达式的返回值为左边的值既是(*destination++)；
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
		//跳出后的两种原因
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
void* mymemcpy ( void* destination, const void* source, size_t count ) {//memcpy 接受的是任意类型指针
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
	//memove 是为了解决 memcpy的内存重叠问题 
	assert(destination);
	assert(source);
	char* dest = (char*) destination;
	char* sour = (char*) source;
	if(dest <= sour){ //目标空间首地址<=原空间首地址(可能前重叠，或不重叠)
		for(size_t i = 0;i < count; i++){//从前往后拷贝
			*(dest + i) = *(sour + i);
		}
	}else{//目标空间首地址>原空间首地址(可能后重叠，或不重叠)
		for(size_t i = count - 1;i >= 0; i++){//从后往前拷贝
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