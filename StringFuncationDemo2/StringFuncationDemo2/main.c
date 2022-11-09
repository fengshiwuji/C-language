#include <stdio.h>
#include <string.h>
#include <assert.h>

#pragma warning(disable:4996)

/**
  * @brief : ���ַ�������.
  * @param : str �����ַ������ַ���ַ.
  * @return : �����ַ����ĳ���.
  **/
size_t my_strlen(const char* str)
{
	assert(str != NULL);
	const char* p = str;
	while (*p) p++;
	return (p - str);
}
/*strlen��������*/
void Test01(void)
{
	char* str = "abcdefgh";
	size_t len = my_strlen(str);
	printf("len: %u\n",len);
}

/**
  * @brief : �ַ�����������
  * @param : StrDes��Ŀ���ַ������ַ���ַ
  * @param : StrSrc��Դ�ַ������ַ���ַ
  * @return : ����Ŀ���ַ������ַ���ַ
  **/
char* my_strcpy(char* StrDes, const char* StrSrc)
{
	assert(StrDes && StrSrc);
	char* pos = StrDes;
	while (*StrDes++ = *StrSrc++);
	return pos;
}

/*�ַ���������������*/
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
  * @brief : �ַ����ȽϺ���
  * @param : str1:���Ƚ��ַ���1
  * @param : str2:���Ƚ��ַ���2
  * @return : ��str1>str2���򷵻�>0����,str1=str2���򷵻�0,str1<str2���򷵻�<0����.
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

/*my_strcmp�Ĳ���*/
void Test03(void)
{
	const char* str1 = "abcdefg";
	const char* str2 = "abcdefg";

	int ret = my_strcmp(str1, str2);

	printf("ret = %d \n",ret);
}

/**
  * @brief : �ַ���׷�Ӻ���
  * @param : DesStr:Ŀ���ַ��������ַ���ַ
  * @param : SrcStr:Դ�ַ��������ַ���ַ
  * @return : ����׷�Ӻ�Ŀ���ַ��������ַ���ַ.
  **/
char* my_strcat(char* DesStr, const char* SrcStr)
{
	assert(DesStr&& SrcStr);
	char* pos = DesStr;
	while (*DesStr)DesStr++;
	while (*DesStr++ = *SrcStr++);
	return pos;
}

/*��my_strcat�����Ĳ���*/
void Test04(void)
{
	char arr[50] = "hello world!";
	const char* str = "��ã�����";

	char* ret = my_strcat(arr, str);

	printf("arr: %s\n",arr);
	printf("ret: %s\n",ret);
}

/**
  * @brief : ��ԭ�ַ�������count���ַ���Ŀ���ַ���
  * @param : strDest.Ŀ���ַ���
  * @param : strSource.Դ�ַ���
  * @param : count.�����ַ�����
  * @return : Ŀ���ַ��������ַ���ַ.
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

/*��my_strncpy�����Ĳ���*/
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
  * @brief : �ַ����ȽϺ���
  * @param : str1.�Ƚ��ַ���1
  * @param : str2.�Ƚ��ַ���2
  * @param : count.Ҫ�Ƚϵ��ַ�����
  * @return : ��str1>str2���򷵻�>0����,str1=str2���򷵻�0,str1<str2���򷵻�<0����..
  **/
int my_strncmp(const char* str1,const char*str2,size_t count)
{
	assert(str1&&str2);
	/*�����Ƚ�ǰcount-1���ַ��Ĵ�С��ϵ*/
	while (--count&&*str1&&*str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2) > 0 ? 1 : (*str1 - *str2) < 0 ? -1 : 0;
		str1++;
		str2++;
	}
	/*�����Ƚ����һ���ַ��Ĵ�С��ϵ*/
	return (*str1 - *str2)>0?1: (* str1 - *str2)<0?-1:0;
}

/*�� my_strncmp�����Ĳ���*/
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
  * @brief : ׷��count���ַ���Ŀ���ַ���
  * @param : StrDest.Ŀ���ַ���1
  * @param : StrSrc.Դ�ַ���2
  * @param : count.Ҫ׷�ӵ��ַ�����
  * @return : Ŀ���ַ��������ַ���ַ.
  **/
char* my_strncat(char* StrDest,const char* StrSrc,size_t count)
{
	assert(StrDest && StrSrc);
	char* pos = StrDest;
	while (*StrDest)StrDest++; //�ҵ�Ŀ���ַ����Ľ�����־ '\0'
	while (count-- && (*StrDest++ = *StrSrc++));
	return pos;
}

/*��my_strncat�����Ĳ���*/
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
  * @brief : �����Ӵ�����
  * @param : string.�ַ���
  * @param : strCharSet.���ַ���
  * @return : ���ַ�����һ����string�ַ����г��ֵ�λ�ã�ָ�룩
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

/*��my_strstr�����Ĳ���*/
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
  * @brief : �ַ����и��
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
	if (str != NULL) //����ǵ�һ�ν��� ִ��if ����ִ��else
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

/*�Ժ���my_strtok�Ĳ���*/
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
  * @brief : ������.
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