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
//char* mystrstr(const char* destination,const char* source){
//	while(*destination != '\0'){
//		const char* dest = destination;
//		const char* sour =source;
//		while( (*dest == *sour) ){
//			if(*sour == '\0'){
//			break;
//			}
//			dest++;
//			sour++;
//		}
//		//(1)*dest != *sour 
//		//(2)*sour == '\0'
//		
//		if((*sour) == '\0'){//(2)*sour == '\0'
//			if((dest != destination)){
//				return (char*)destination;
//			}else{
//				 destination++;
//			}
//		}else{//(1)*dest != *sour 
//			destination++;
//		}
//	
//	}
//	return NULL;
//}
int main(){
	char str1[] = "abcd";
	char str2[] = "a";
	char str3[]="";
	//mystrncpy(str1,str2,2);
	//mystrcat(str1,str2);
	//printf("%d\n",mystrcmp1 (str1,str2));
	//printf("%d\n",mystrcmp2 (str1,str2));
	//printf("%s",str1);
	//printf("%p",mystrstr(str2,str3));
	system("pause");
	return 0;
 }