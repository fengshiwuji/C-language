#include "mystr.h"

/**************************************************
函数功能：字符串拷贝。
函数参数：strDest:目的字符串的首地址。
          strSrc:原字符串的首地址。
返回值：返回拷贝的字符串的首地址。
**************************************************/
char* my_strcpy(char* strDest, const char* strSrc)
{
	char* temp = strDest;
	while (*strDest++ = *strSrc++);
	return temp;
}

/**************************************************
函数功能：字符串拷贝n字节。
函数参数：strDest:目的字符串的首地址。
		  strSrc:原字符串的首地址。
		  count:拷贝字节数。
返回值：返回拷贝的字符串的首地址。
**************************************************/
char* my_strncpy(char* strDest, const char* strSrc,size_t count)
{
	char* temp = strDest;
	while (count--&&(*strDest++ = *strSrc++));
	if(*(strDest-1))
		*strDest = '\0';
	return temp;
}

/**************************************************
函数功能：字符串长度。
函数参数：str:字符串的首地址。
返回值：返回字符串的长度。
**************************************************/
size_t my_strlen(const char* str)
{
	const char* head = str;
	const char* tail = str;
	while (*tail)tail++;

	return (size_t)(tail-head);
}

/**************************************************
函数功能：字符串比较。
函数参数：str1:字符串1的首地址。
		  str2:字符串2的首地址。
返回值：str1>str2,返回大于0的数。
		str1<str2,返回小于0的数。
		str1==str2,返回等于0的数。
**************************************************/
int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 != '\0'|| *str2 != '\0')
	{
		if (*str1 != *str2)			//判断不相等直接返回
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return 0; //能执行到这里说明两个字符串相等
}

/**************************************************
函数功能：字符串比较n字节。
函数参数：str1:字符串1的首地址。
		  str2:字符串2的首地址。
		  count:比较的字节数。
返回值：str1>str2,返回大于0的数。
		str1<str2,返回小于0的数。
		str1==str2,返回等于0的数。
**************************************************/
int my_strncmp(const char* str1, const char* str2,size_t count)
{
	while (count--&&(*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)			//判断不相等直接返回
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return 0; //能执行到这里说明两个字符串相等
}


/**************************************************
函数功能：字符串追加。
函数参数：strDest:目的字符串的首地址。
		  strSrc:源字符串的首地址。
返回值：追加后的字符串的首地址
**************************************************/
char* my_strcat(char* strDest, const char* strSrc)
{
	char* str = strDest;
	//找尾
	while (*strDest)strDest++;

	while (*strDest++ = *strSrc++);
	return str;
}

/**************************************************
函数功能：字符串追加n个字节。
函数参数：strDest:目的字符串的首地址。
		  strSrc:源字符串的首地址。
		  count:追加的字节数。
返回值：追加后的字符串的首地址
**************************************************/
char* my_strncat(char* strDest, const char* strSrc,size_t count)
{
	char* str = strDest;
	//找尾
	while (*strDest)strDest++;

	while (count--&&(*strDest++ = *strSrc++));
	if (*(strDest - 1))
		*strDest = '\0';
	return str;
}