#include <stdio.h>
#include <string.h> 
#include <assert.h> 


#define Method_One 0

/*模拟实现strlen求字符串长度函数*/
size_t my_strlen(const char* str)
{
#if Method_One
	size_t cnt = 0;
	while (*str++)
	{
		cnt++;
	}
	return cnt;
#else
	const char* pstr = str;
	while (*pstr) pstr++;
	return (size_t)(pstr - str);
#endif
}
/*对my_strlen函数的测试*/
void Test01(void)
{
	const char* pstr = "abcdefg";

	printf("strlen: %u\n", strlen(pstr));
	printf("my_strlen: %u\n", my_strlen(pstr));
}
/*模拟实现strcpy函数字符串拷贝函数*/
char* my_strcpy(char* strDestination, const char* strSource)
{
	char* strDest = strDestination;
	while (*strSource)
	{
		*strDest++ = *strSource++;
	}
	*strDest = *strSource;
	return strDestination;
}

/*对my_strcopy函数的测试*/
void Test02(void)
{
	const char* str1 = "abcdefg";
	char str2[20] = {0};
	char* StrDest = my_strcpy(str2, str1);

	printf("str1:%s\n", str1);
	printf("str2:%s\n", str2);
	printf("StrDest:%s\n", StrDest);
}

/*模拟实现strcat字符串追加函数*/
char* my_strcat(char* strDestination, const char* strSource)
{
	char* StrDest = strDestination;
	/*找strDestination串中的结束符 '\0'*/
	while (*StrDest)StrDest++;

	while (*strSource)
	{
		*StrDest++ = *strSource++;
	}
	*StrDest = *strSource;
	return strDestination;
}

/*对my_strcat字符串追加函数的测试*/
void Test03(void)
{
	const char* str1 = "fengshiwuji";
	char str2[50] = "fswj";

	char* strDest = my_strcat(str2, str1);

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("strDest: %s\n", strDest);
}

/*模拟实现strcmp字符串比较函数*/
int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return *str1 - *str2;
		str1++;
		str2++;
	}
	return (* str1 - *str2);
}

/*对my_strcmp字符串比较函数的测试*/
void Test04(void)
{
	const char arr1[] = "abcdef";
	const char arr2[] = "abcdew";

	int cmp = my_strcmp(arr1, arr2);
	if (cmp > 0)
	{
		printf("arr1 > arr2\n");
	}
	else if (cmp < 0)
	{
		printf("arr1 < arr2\n");
	}
	else
	{
		printf("arr1 == arr2\n");
	}
}

/*模拟实现strncpy长度受限的字符串拷贝函数*/
char* my_strncpy(char* strDest, const char* strSource, size_t count)
{
	char* TempStrDest = strDest;
	while (*strSource && count)
	{
		*TempStrDest++ = *strSource++;
		count--;
	}
	while (count)
	{
		*TempStrDest++ = '0';
		count--;
	}
	*TempStrDest = '\0';
	return strDest;
}

/*对my_strncpy长度受限的字符串拷贝函数的测试*/
void Test05(void)
{
	const char arr1[10] = "abcdef";
	char arr2[20] = "fengshiwuji";

	char* StrDest = my_strncpy(arr2, arr1, 10);

	printf("arr1: %s\n",arr1);
	printf("arr2: %s\n", arr2);
	printf("StrDest: %s\n", StrDest);
}

/*模拟实现stncat长度受限的字符串追加函数*/
char* my_strncat(char* strDest, const char* strSource, size_t count)
{
	char* TempStrDest = strDest;
	while (*TempStrDest) TempStrDest++;
	while (*strSource&&count)
	{
		*TempStrDest++ = *strSource++;
		count--;
	}
	*TempStrDest = '\0';
	return strDest;
}

/*对my_strncat长度受限的字符串追加函数的测试*/
void Test06(void)
{
	const char arr1[] = "abcdef";
	char arr2[20] = "fengshiwuji";

	char* strDest = my_strncat(arr2, arr1, 5);

	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);
	printf("strDest: %s\n", strDest);
}

/*模拟实现strncmp长度受限的字符串比较函数*/
int my_strncmp(const char* str1, const char* str2, size_t count)
{
	/*count必须使用前置--*/
	while (*str1 && *str2 && --count)
	{									
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/*对my_strncmp长度受限的字符串比较函数的测试*/
void Test07(void)
{
	const char arr1[] = "abc";
	const char arr2[] = "abc";

	int cmp = my_strncmp(arr1, arr2, 4);

	if (cmp > 0)
	{
		printf("arr1 > arr2\n");
	}
	else if (cmp < 0)
	{
		printf("arr1 < arr2\n");
	}
	else
	{
		printf("arr1 == arr2\n");
	}
}

/*模拟实现strstr字符串查找子串函数*/
char* my_strstr(const char* string, const char* strCharSet)
{
	char* str1 = (char*)string;
	char* str2 = (char*)strCharSet;
	char* temp = NULL;
	if (my_strlen(strCharSet) == 0)
	{
		return (char*)string;
	}
	while (*str1)
	{
		temp = str1;
		str2 = (char*)strCharSet;
		while (*temp &&*str2&&(*temp ==*str2))
		{
			temp++;
			str2++;
		}
		if (*str2 == '\0')
			return str1;
		str1++;
	}
	return NULL;
}

/*对my_strstr字符串查找子串函数的测试*/
void Test08(void)
{
	const char str1[] = "abc8";
	const char str2[] = "b";
	
	char* str = my_strstr(str1, str2);
	if (str == NULL)
	{
		printf("未找到子串：%s\n",str2);
	}
	else
	{
		printf("找到了：%s\n", str);
	}
}
/*模拟实现strtok字符串切割函数*/
char* my_strtok(char* strToken, const char* strDelimit)
{
	char* str1 = strToken;
	char* temp = NULL;
	char* str2 = (char*)strDelimit;
	static char* pos = NULL;

	if (str1 != NULL)
	{
		while (*str1)
		{
			str2 = (char*)strDelimit;
			while (*str2 != '\0')
			{
				if ((*str1 == *str2))
				{
					if (*(str1 + 1) == '\0')
						pos = NULL;
					else
						pos = str1;
					*str1 = '\0';
					return strToken;
				}
				str2++;
			}
			str1++;
		}
	}
	else
	{
		if (pos != NULL)
		{
			str1 = pos + 1;
			temp = pos + 1;
			while (*str1)
			{
				str2 = (char*)strDelimit;
				while (*str2 != '\0')
				{
					if ((*str1 == *str2))
					{
						pos = str1;
						*str1 = '\0';
						return temp;
					}
					str2++;
				}
				str1++;
			}
			pos = NULL;
			return temp;
		}	
	}
	return NULL;
}

/*对my_strtok字符串切片函数的测试*/
void Test09(void)
{
	char arr[] = "www.baidu.com and 1808743108@qq.com";
	const char* sep = ". @";

	char arrcpy[40];

	printf("The sep is :%s\n", sep);

	/*由于strtok会破坏原字符串的结构，所以通常会拷贝一份用来切割*/
	my_strcpy(arrcpy, arr);
	printf("arrcpy: %s\n", arrcpy);

	printf("--------------------------------------\n");
	char* str = my_strtok(arr, sep);
	if (str != NULL)
		printf("%s\n", str);
	while ((str = my_strtok(NULL, sep)) != NULL)
	{
		printf("%s\n", str);
	}
}
/* strerror example : error list */
#include <errno.h>//必须包含的头文件

/*屏蔽掉来自fopen、strerror函数的不安全警告*/
#pragma warning(disable:4996)

/*对strerror错误信息报告函数的测试*/
void Test10(void)
{
	FILE* pFile;
	pFile = fopen("unexist.ent", "r");
	if (pFile == NULL)
		printf("Error opening file unexist.ent: %s\n", strerror(errno));
	//errno: Last error number
}

/*主函数main*/
int main(void)
{
	/*对my_strlen函数的测试*/
	Test01();

	/*对my_strcopy函数的测试*/
	Test02();

	/*对my_strcat字符串追加函数的测试*/
	Test03();
	
	/*对my_strcmp字符串比较函数的测试*/
	Test04();

	/*对my_strncpy长度受限的字符串拷贝函数的测试*/
	Test05();

	/*对my_strncat长度受限的字符串追加函数的测试*/
	Test06();

	/*对my_strncmp长度受限的字符串比较函数的测试*/
	Test07();

	/*对my_strstr字符串查找子串函数的测试*/
	Test08();

	/*对my_strtok字符串切片函数的测试*/
	Test09();

	/*对strerror错误信息报告函数的测试*/
	Test10();

	return 0;
}