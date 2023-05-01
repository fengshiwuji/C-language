#include "memery.h"

/************************************************
�������ܣ�ʵ���ڴ濽������λ���ֽڣ�
����������dest:Ŀ�ĵ�ַ��
		  src :ԭ��ַ��
		  count:����count�ֽڡ�
����ֵ��ԭĿ�ĵ�ַ��dest��
************************************************/
void* my_memcpy(void* dest,const void* src,size_t count)
{
	char* pch1 = (char*)dest;
	char* pch2 = (char*)src;
	while (count--)
	{
		*pch1++ = *pch2++;
	}
	return dest;
}

/************************************************
�������ܣ�ʵ���ڴ�Ƚϣ���λ���ֽڣ�
����������dest:Ŀ�ĵ�ַ��
		  src :ԭ��ַ��
		  count:�Ƚ�count���ֽڡ�
����ֵ��-1,0,1.
************************************************/
int my_memcmp(const void* buff1, const void* buff2, size_t count)
{
	char* pch1 = (char*)buff1;
	char* pch2 = (char*)buff2;
	while (count--)
	{
		if (*pch1 != *pch2)
			return (*pch1 - *pch2);
		pch1++;
		pch2++;
	}
	return 0;
}


/************************************************
�������ܣ�ʵ���ڴ濽������λ���ֽڣ�
����������dest:Ŀ�ĵ�ַ��
		  src :ԭ��ַ��
		  count:����count�ֽڡ�
����ֵ��ԭĿ�ĵ�ַ��dest��
ע�⣺�ú�����memcpy��������memcpyĳ������²�
���Կ�����memmove����ʵ�֡�
************************************************/
void* my_memmove(void* dest, const void* src, size_t count)
{
	char* pch1 = (char*)dest;
	char* pch2 = (char*)src;
	if ((pch1 > pch2) && (pch1 < (pch2 + count)))
	{
		pch1 = pch1 + count - 1;
		pch2 = pch2 + count - 1;
		while (count--)
		{
			*pch1-- = *pch2--;
		}
	}
	else
	{
		while (count--)
		{
			*pch1++ = *pch2++;
		}
	}
	return dest;
}

/************************************************
�������ܣ�ʵ���ڴ����ã���λ���ֽڣ�
����������dest:Ŀ�ĵ�ַ��
		  src :ԭ��ַ��
		  count:����count���ֽڡ�
����ֵ��ԭĿ�ĵ�ַ��dest��
************************************************/
void* my_memset(void* dest, int c, size_t count)
{
	char* pch = (char*)dest;
	while (count--)
		*pch++ = c;
	return dest;
}
