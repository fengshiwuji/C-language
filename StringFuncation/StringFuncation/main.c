#include <stdio.h>
#include <string.h> 
#include <assert.h> 


#define Method_One 0

/*ģ��ʵ��strlen���ַ������Ⱥ���*/
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
/*��my_strlen�����Ĳ���*/
void Test01(void)
{
	const char* pstr = "abcdefg";

	printf("strlen: %u\n", strlen(pstr));
	printf("my_strlen: %u\n", my_strlen(pstr));
}
/*ģ��ʵ��strcpy�����ַ�����������*/
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

/*��my_strcopy�����Ĳ���*/
void Test02(void)
{
	const char* str1 = "abcdefg";
	char str2[20] = {0};
	char* StrDest = my_strcpy(str2, str1);

	printf("str1:%s\n", str1);
	printf("str2:%s\n", str2);
	printf("StrDest:%s\n", StrDest);
}

/*ģ��ʵ��strcat�ַ���׷�Ӻ���*/
char* my_strcat(char* strDestination, const char* strSource)
{
	char* StrDest = strDestination;
	/*��strDestination���еĽ����� '\0'*/
	while (*StrDest)StrDest++;

	while (*strSource)
	{
		*StrDest++ = *strSource++;
	}
	*StrDest = *strSource;
	return strDestination;
}

/*��my_strcat�ַ���׷�Ӻ����Ĳ���*/
void Test03(void)
{
	const char* str1 = "fengshiwuji";
	char str2[50] = "fswj";

	char* strDest = my_strcat(str2, str1);

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("strDest: %s\n", strDest);
}

/*ģ��ʵ��strcmp�ַ����ȽϺ���*/
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

/*��my_strcmp�ַ����ȽϺ����Ĳ���*/
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

/*ģ��ʵ��strncpy�������޵��ַ�����������*/
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

/*��my_strncpy�������޵��ַ������������Ĳ���*/
void Test05(void)
{
	const char arr1[10] = "abcdef";
	char arr2[20] = "fengshiwuji";

	char* StrDest = my_strncpy(arr2, arr1, 10);

	printf("arr1: %s\n",arr1);
	printf("arr2: %s\n", arr2);
	printf("StrDest: %s\n", StrDest);
}

/*ģ��ʵ��stncat�������޵��ַ���׷�Ӻ���*/
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

/*��my_strncat�������޵��ַ���׷�Ӻ����Ĳ���*/
void Test06(void)
{
	const char arr1[] = "abcdef";
	char arr2[20] = "fengshiwuji";

	char* strDest = my_strncat(arr2, arr1, 5);

	printf("arr1: %s\n", arr1);
	printf("arr2: %s\n", arr2);
	printf("strDest: %s\n", strDest);
}

/*ģ��ʵ��strncmp�������޵��ַ����ȽϺ���*/
int my_strncmp(const char* str1, const char* str2, size_t count)
{
	/*count����ʹ��ǰ��--*/
	while (*str1 && *str2 && --count)
	{									
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/*��my_strncmp�������޵��ַ����ȽϺ����Ĳ���*/
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

/*ģ��ʵ��strstr�ַ��������Ӵ�����*/
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

/*��my_strstr�ַ��������Ӵ������Ĳ���*/
void Test08(void)
{
	const char str1[] = "abc8";
	const char str2[] = "b";
	
	char* str = my_strstr(str1, str2);
	if (str == NULL)
	{
		printf("δ�ҵ��Ӵ���%s\n",str2);
	}
	else
	{
		printf("�ҵ��ˣ�%s\n", str);
	}
}
/*ģ��ʵ��strtok�ַ����и��*/
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

/*��my_strtok�ַ�����Ƭ�����Ĳ���*/
void Test09(void)
{
	char arr[] = "www.baidu.com and 1808743108@qq.com";
	const char* sep = ". @";

	char arrcpy[40];

	printf("The sep is :%s\n", sep);

	/*����strtok���ƻ�ԭ�ַ����Ľṹ������ͨ���´��һ�������и�*/
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
#include <errno.h>//���������ͷ�ļ�

/*���ε�����fopen��strerror�����Ĳ���ȫ����*/
#pragma warning(disable:4996)

/*��strerror������Ϣ���溯���Ĳ���*/
void Test10(void)
{
	FILE* pFile;
	pFile = fopen("unexist.ent", "r");
	if (pFile == NULL)
		printf("Error opening file unexist.ent: %s\n", strerror(errno));
	//errno: Last error number
}

/*������main*/
int main(void)
{
	/*��my_strlen�����Ĳ���*/
	Test01();

	/*��my_strcopy�����Ĳ���*/
	Test02();

	/*��my_strcat�ַ���׷�Ӻ����Ĳ���*/
	Test03();
	
	/*��my_strcmp�ַ����ȽϺ����Ĳ���*/
	Test04();

	/*��my_strncpy�������޵��ַ������������Ĳ���*/
	Test05();

	/*��my_strncat�������޵��ַ���׷�Ӻ����Ĳ���*/
	Test06();

	/*��my_strncmp�������޵��ַ����ȽϺ����Ĳ���*/
	Test07();

	/*��my_strstr�ַ��������Ӵ������Ĳ���*/
	Test08();

	/*��my_strtok�ַ�����Ƭ�����Ĳ���*/
	Test09();

	/*��strerror������Ϣ���溯���Ĳ���*/
	Test10();

	return 0;
}