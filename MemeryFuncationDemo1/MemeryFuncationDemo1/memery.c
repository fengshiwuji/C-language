#include "memery.h"

/************************************************
函数功能：实现内存拷贝（单位：字节）
函数参数：dest:目的地址。
		  src :原地址。
		  count:拷贝count字节。
返回值：原目的地址：dest。
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
函数功能：实现内存比较（单位：字节）
函数参数：dest:目的地址。
		  src :原地址。
		  count:比较count个字节。
返回值：-1,0,1.
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
函数功能：实现内存拷贝（单位：字节）
函数参数：dest:目的地址。
		  src :原地址。
		  count:拷贝count字节。
返回值：原目的地址：dest。
注意：该函数与memcpy有所区别，memcpy某种情况下不
能自拷，而memmove可以实现。
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
函数功能：实现内存设置（单位：字节）
函数参数：dest:目的地址。
		  src :原地址。
		  count:设置count个字节。
返回值：原目的地址：dest。
************************************************/
void* my_memset(void* dest, int c, size_t count)
{
	char* pch = (char*)dest;
	while (count--)
		*pch++ = c;
	return dest;
}
