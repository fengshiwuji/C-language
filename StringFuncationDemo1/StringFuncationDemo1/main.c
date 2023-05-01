#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "mystr.h"

//strcpy���Ժ���
void strcpyTestFun(void)
{
	const char src[] = "helloworld";
	char dst[100];

	char* str1 = my_strcpy(dst,src);
	printf("my_strcpy: %s\r\n", str1);

	char* str2 = strcpy(dst,src);
	printf("strcpy: %s\r\n", str2);
}

//strlen���Ժ���
void strlenTestFun(void)
{
	const char src[] = "helloworld";

	size_t strlen1 = my_strlen(src);
	printf("my_strlen: %zu\r\n", strlen1);

	size_t strlen2 = strlen(src);
	printf("strlen: %zu\r\n", strlen2);
}

//strcmp���Ժ���
void strcmpTestFun(void)
{
	char str1[] = "helloworld";
	char str2[] = "helloworld";

	printf("\r\n============����һ��������̵Ĳ��ԣ�============\r\n");
	int ret1 = my_strcmp((const char*)str1, (const char*)str2);
	printf("my_strcmp: %d\r\n", ret1);
	int ret2 = strcmp((const char*)str1, (const char*)str2);
	printf("strcmp: %d\r\n", ret2);

	printf("\r\n============����һ��str1����str2���̵Ĳ��ԣ�============\r\n");
	my_strcpy(str2,"hello");
	my_strcpy(str1,"world");
	ret1 = my_strcmp((const char*)str1, (const char*)str2);
	printf("my_strcmp: %d\r\n",ret1);
	ret2 = strcmp((const char*)str1, (const char*)str2);
	printf("strcmp: %d\r\n", ret2);
	
	printf("\r\n============����һ��str1С��str2���̵Ĳ��ԣ�============\r\n");
	my_strcpy(str1, "hello");
	my_strcpy(str2, "world");
	ret1 = my_strcmp((const char*)str1, (const char*)str2);
	printf("my_strcmp: %d\r\n", ret1);
	ret2 = strcmp((const char*)str1, (const char*)str2);
	printf("strcmp: %d\r\n", ret2);
}

//strcat���Ժ���
void strcatTestFun(void)
{
	char src[100] = "helloworld";
	char dest[100] = "helloworld";

	char* ret1 = my_strcat(dest,(const char*)src);
	printf("my_strcat: %s\r\n", ret1);

	my_strcpy(src,"helloworld");
	my_strcpy(dest,"helloworld");
	char* ret2 = strcat(dest, (const char*)src);
	printf("strcat: %s\r\n", ret2);
}
//strncpy���Ժ���
void strncpyTestFun(void)
{
	const char src[] = "helloworld";
	char dst[100];

	char* str1 = my_strncpy(dst, src,strlen(src));
	printf("my_strncpy: %s\r\n", str1);

	char* str2 = strncpy(dst, src,strlen(src));
	printf("strncpy: %s\r\n", str2);

	my_strcpy(dst, "\0");
	str1 = my_strncpy(dst, src, 0);
	printf("my_strncpy: %s\r\n", str1);
	my_strcpy(dst, "\0");
	str2 = strncpy(dst, src,0);
	printf("strncpy: %s\r\n", str2);
}

//strncmp���Ժ���
void strncmpTestFun(void)
{
	char str1[] = "helloworld";
	char str2[] = "helloworld";

	printf("\r\n============����һ��������̵Ĳ��ԣ�============\r\n");
	int ret1 = my_strncmp((const char*)str1, (const char*)str2,3);
	printf("my_strncmp: %d\r\n", ret1);
	int ret2 = strncmp((const char*)str1, (const char*)str2,3);
	printf("strncmp: %d\r\n", ret2);

	printf("\r\n============����һ��str1����str2���̵Ĳ��ԣ�============\r\n");
	my_strcpy(str2, "hello");
	my_strcpy(str1, "world");
	ret1 = my_strncmp((const char*)str1, (const char*)str2, 3);
	printf("my_strncmp: %d\r\n", ret1);
	ret2 = strncmp((const char*)str1, (const char*)str2, 3);
	printf("strncmp: %d\r\n", ret2);

	printf("\r\n============����һ��str1С��str2���̵Ĳ��ԣ�============\r\n");
	my_strcpy(str1, "hello");
	my_strcpy(str2, "world");
	ret1 = my_strncmp((const char*)str1, (const char*)str2, 3);
	printf("my_strcmp: %d\r\n", ret1);
	ret2 = strncmp((const char*)str1, (const char*)str2, 3);
	printf("strcmp: %d\r\n", ret2);
}

//strncat���Ժ���
void strncatTestFun(void)
{
	char src[100] = "helloworld";
	char dest[100] = "helloworld";

	char* ret1 = my_strncat(dest, (const char*)src,strlen(src));
	printf("my_strncat: %s\r\n", ret1);

	my_strcpy(src, "helloworld");
	my_strcpy(dest, "helloworld");
	char* ret2 = strncat(dest, (const char*)src, strlen(src));
	printf("strncat: %s\r\n", ret2);
}

//������
int main(void)
{
	//strcpyTestFun();
	//strlenTestFun();
	//strcmpTestFun();
	//strcmpTestFun();
	//strcatTestFun();
	//strncpyTestFun();
	//strncmpTestFun();
	
	strncatTestFun();

	return 0;
}

