#include "mystr.h"

/**************************************************
�������ܣ��ַ���������
����������strDest:Ŀ���ַ������׵�ַ��
          strSrc:ԭ�ַ������׵�ַ��
����ֵ�����ؿ������ַ������׵�ַ��
**************************************************/
char* my_strcpy(char* strDest, const char* strSrc)
{
	char* temp = strDest;
	while (*strDest++ = *strSrc++);
	return temp;
}

/**************************************************
�������ܣ��ַ�������n�ֽڡ�
����������strDest:Ŀ���ַ������׵�ַ��
		  strSrc:ԭ�ַ������׵�ַ��
		  count:�����ֽ�����
����ֵ�����ؿ������ַ������׵�ַ��
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
�������ܣ��ַ������ȡ�
����������str:�ַ������׵�ַ��
����ֵ�������ַ����ĳ��ȡ�
**************************************************/
size_t my_strlen(const char* str)
{
	const char* head = str;
	const char* tail = str;
	while (*tail)tail++;

	return (size_t)(tail-head);
}

/**************************************************
�������ܣ��ַ����Ƚϡ�
����������str1:�ַ���1���׵�ַ��
		  str2:�ַ���2���׵�ַ��
����ֵ��str1>str2,���ش���0������
		str1<str2,����С��0������
		str1==str2,���ص���0������
**************************************************/
int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 != '\0'|| *str2 != '\0')
	{
		if (*str1 != *str2)			//�жϲ����ֱ�ӷ���
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return 0; //��ִ�е�����˵�������ַ������
}

/**************************************************
�������ܣ��ַ����Ƚ�n�ֽڡ�
����������str1:�ַ���1���׵�ַ��
		  str2:�ַ���2���׵�ַ��
		  count:�Ƚϵ��ֽ�����
����ֵ��str1>str2,���ش���0������
		str1<str2,����С��0������
		str1==str2,���ص���0������
**************************************************/
int my_strncmp(const char* str1, const char* str2,size_t count)
{
	while (count--&&(*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)			//�жϲ����ֱ�ӷ���
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return 0; //��ִ�е�����˵�������ַ������
}


/**************************************************
�������ܣ��ַ���׷�ӡ�
����������strDest:Ŀ���ַ������׵�ַ��
		  strSrc:Դ�ַ������׵�ַ��
����ֵ��׷�Ӻ���ַ������׵�ַ
**************************************************/
char* my_strcat(char* strDest, const char* strSrc)
{
	char* str = strDest;
	//��β
	while (*strDest)strDest++;

	while (*strDest++ = *strSrc++);
	return str;
}

/**************************************************
�������ܣ��ַ���׷��n���ֽڡ�
����������strDest:Ŀ���ַ������׵�ַ��
		  strSrc:Դ�ַ������׵�ַ��
		  count:׷�ӵ��ֽ�����
����ֵ��׷�Ӻ���ַ������׵�ַ
**************************************************/
char* my_strncat(char* strDest, const char* strSrc,size_t count)
{
	char* str = strDest;
	//��β
	while (*strDest)strDest++;

	while (count--&&(*strDest++ = *strSrc++));
	if (*(strDest - 1))
		*strDest = '\0';
	return str;
}