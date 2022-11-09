#include <stdio.h>
#include <string.h>
#include <assert.h>

#pragma warning(disable:4996)

/**
  * @brief : 求字符串长度.
  * @param : str 输入字符串首字符地址.
  * @return : 返回字符串的长度.
  **/
size_t my_strlen(const char* str)
{
	assert(str != NULL);
	const char* p = str;
	while (*p) p++;
	return (p - str);
}
/*strlen函数测试*/
void Test01(void)
{
	char* str = "abcdefgh";
	size_t len = my_strlen(str);
	printf("len: %u\n",len);
}

/**
  * @brief : 字符串拷贝函数
  * @param : StrDes：目的字符串首字符地址
  * @param : StrSrc：源字符串首字符地址
  * @return : 返回目的字符串首字符地址
  **/
char* my_strcpy(char* StrDes, const char* StrSrc)
{
	assert(StrDes && StrSrc);
	char* pos = StrDes;
	while (*StrDes++ = *StrSrc++);
	return pos;
}

/*字符串拷贝函数测试*/
void Test02(void)
{
	char arr1[50] = "abcdefgh";
	const char* str = "hello";
	char* DesStr = strcpy(arr1,str);
	printf("DesStr:%s\n", DesStr);
	printf("arr1:%s\n", arr1);

	char arr2[50] = "abcdefgh";
	DesStr = my_strcpy(arr2, str);
	printf("DesStr:%s\n", DesStr);
	printf("arr2:%s\n", arr2);
}

/**
  * @brief : 字符串比较函数
  * @param : str1:待比较字符串1
  * @param : str2:待比较字符串2
  * @return : 若str1>str2，则返回>0的数,str1=str2，则返回0,str1<str2，则返回<0的数.
  **/
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/*my_strcmp的测试*/
void Test03(void)
{
	const char* str1 = "abcdefg";
	const char* str2 = "abcdefg";

	int ret = my_strcmp(str1, str2);

	printf("ret = %d \n",ret);
}

/**
  * @brief : 字符串追加函数
  * @param : DesStr:目的字符串的首字符地址
  * @param : SrcStr:源字符串的首字符地址
  * @return : 返回追加后目的字符串的首字符地址.
  **/
char* my_strcat(char* DesStr, const char* SrcStr)
{
	assert(DesStr&& SrcStr);
	char* pos = DesStr;
	while (*DesStr)DesStr++;
	while (*DesStr++ = *SrcStr++);
	return pos;
}

/*对my_strcat函数的测试*/
void Test04(void)
{
	char arr[50] = "hello world!";
	const char* str = "你好，世界";

	char* ret = my_strcat(arr, str);

	printf("arr: %s\n",arr);
	printf("ret: %s\n",ret);
}

/**
  * @brief : 从原字符串拷贝count个字符到目的字符串
  * @param : strDest.目的字符串
  * @param : strSource.源字符串
  * @param : count.拷贝字符个数
  * @return : 目的字符串的首字符地址.
  **/
char* my_strncpy(char* strDest, const char* strSource, size_t count)
{
	assert(strSource&&strDest);
	char* pos = strDest;
	while (count&& *strSource)
	{
		*strDest++ = *strSource++;
		count--;
	}
	return pos;
}

/*对my_strncpy函数的测试*/
void Test05(void)
{
	char arr1[50] = "hello world!";
	const char* str = "abcdefghijklmnopqretuvwxyz";

	char* ret = my_strncpy(arr1,str,5);

	printf("my_strncpy-> ret: %s\n", ret);
	printf("my_strncpy-> arr1: %s\n", arr1);

	char arr2[50] = "hello world!";
	
	ret = my_strncpy(arr2, str, 5);

	printf("my_strncpy-> ret: %s\n", ret);
	printf("my_strncpy-> arr2: %s\n", arr2);
}

/**
  * @brief : 字符串比较函数
  * @param : str1.比较字符串1
  * @param : str2.比较字符串2
  * @param : count.要比较的字符个数
  * @return : 若str1>str2，则返回>0的数,str1=str2，则返回0,str1<str2，则返回<0的数..
  **/
int my_strncmp(const char* str1,const char*str2,size_t count)
{
	assert(str1&&str2);
	/*用来比较前count-1个字符的大小关系*/
	while (--count&&*str1&&*str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2) > 0 ? 1 : (*str1 - *str2) < 0 ? -1 : 0;
		str1++;
		str2++;
	}
	/*用来比较最后一个字符的大小关系*/
	return (*str1 - *str2)>0?1: (* str1 - *str2)<0?-1:0;
}

/*对 my_strncmp函数的测试*/
void Test06(void)
{
	const char arr1[20] = "abbe";
	const char arr2[20] = "abde";

	int cmp = my_strncmp(arr1,arr2,5);
	printf("my_strncmp: %d\n", cmp);

	cmp = strncmp(arr1, arr2, 5);
	printf("strncmp: %d\n", cmp);
}

/**
  * @brief : 追加count个字符到目的字符串
  * @param : StrDest.目的字符串1
  * @param : StrSrc.源字符串2
  * @param : count.要追加的字符个数
  * @return : 目的字符串的首字符地址.
  **/
char* my_strncat(char* StrDest,const char* StrSrc,size_t count)
{
	assert(StrDest && StrSrc);
	char* pos = StrDest;
	while (*StrDest)StrDest++; //找到目的字符串的结束标志 '\0'
	while (count-- && (*StrDest++ = *StrSrc++));
	return pos;
}

/*对my_strncat函数的测试*/
void Test07(void)
{
	char arr1[50] = "abcdefgh";
	const  char* str = "hello world";

	char* ret = my_strncat(arr1,str,20);
	printf("my_strncat-> ret: %s\n",ret);
	printf("my_strncat-> arr1: %s\n", arr1);
	
	char arr2[50] = "abcdefgh";
	ret = strncat(arr2, str, 20);
	printf("strncat-> ret: %s\n", ret);
	printf("strncat-> arr2: %s\n", arr2);
}

/**
  * @brief : 查找子串函数
  * @param : string.字符串
  * @param : strCharSet.子字符串
  * @return : 子字符串第一次在string字符串中出现的位置（指针）
  **/
char* my_strstr(const char* string, const char* strCharSet)
{
	assert(string && strCharSet);
	const char* posSet = NULL;
	const char* posStr = NULL;
	if (0 == my_strlen(strCharSet))
		return (char*)string;
	while (*string)
	{
		posStr = string;
		posSet = strCharSet;
		while (*posStr==*posSet)
		{
			posSet++;
			posStr++;
			if (*posSet == '\0')
				return (char*)string;
		}
		string++;
	}
	return NULL;
}

/*对my_strstr函数的测试*/
void Tset08(void)
{
	const char* string = "aaabcabcdefdefg";
	const char* strSet = "abcdef";

	char* ret = my_strstr(string, strSet);
	if (ret != NULL)
		printf("ret : %s\n", ret);
	else
		printf("None.strCharSet in string!\n");
}

/**
  * @brief : 字符串切割函数
  * @param : strToken.String containing token(s)
  * @param : strDelimit.Set of delimiter characters
  * @return : All of these functions return a pointer to the next token found in strToken.
  **/
char* my_strtok(char* strToken, const char* strDelimit)
{
	char* str = strToken;
	const char* limit = strDelimit;
	static char* pos = NULL;
	char* temp = NULL;
	if (str != NULL) //如果是第一次进来 执行if 仿真执行else
	{
		while (*str)
		{
			limit = strDelimit;
			while (*limit)
			{
				if (*limit == *str)
				{
					if (*(str + 1) != '\0')
						pos = str;
					else
						pos = NULL;
					*str = '\0';
					return strToken;
				}
				limit++;
			}
			str++;
		}
	}
	else 
	{
		if (pos != NULL)
		{
			str = pos + 1;
			temp = pos + 1;
			while (*str)
			{
				limit = strDelimit;
				while (*limit)
				{
					if (*limit == *str)
					{
						pos = str;
						*str = '\0';
						return temp;
					}
					limit++;
				}
				str++;
			}
			pos = NULL;
			return temp;
		}
	}
	return NULL;
}

/*对函数my_strtok的测试*/
void Test09(void)
{
	char arr[20] = "1808743108@qq.com";
	const char* str = ".@";

	char* ret = my_strtok(arr,str);
	if (ret != NULL)
		printf("ret = %s\n",ret);
	while (NULL !=  (ret = my_strtok(NULL, str)))
	{
		printf("ret: %s\n", ret);
	}
}

/**
  * @brief : 主函数.
  * @param : void.
  * @return : None.
  **/
int main(void)
{
	//Test01();

	//Test02();
	
	//Test03();

	//Test04();

	//Test05();

	//Test06();

	//Test07();

	//Tset08();

	Test09();

	return 0;
}