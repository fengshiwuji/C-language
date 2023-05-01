#include <stdio.h>
#include <assert.h>

/*ģ��ʵ��memcpy�ڴ濽������		ע��ԭ��ַ������Ŀ�ĵ�ַ�غ�*/
void* my_memcpy(void* dest, const void* src, size_t count)
{
	void* temp = dest;
	assert(dest&& src);
	while (count--)
	{
		*(char*)dest = *(char*)src;
		(char*)dest = (char*)dest + 1;
		(char*)src = (char*)src + 1;
	}
	return temp;
}
/*��my_memcpy�����Ĳ���*/
void Test01(void)
{
	int arr1[6] = {10,50,6,80,90,40};
	int arr2[6] = {0};

	int* parr = (int*)my_memcpy(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < (sizeof(arr1) / 4); i++)
	{
		printf("%d ",*parr++);
		printf("%d ", arr2[i]);
	}
}
/*ģ��ʵ��memmove�ڴ濽������	�ɻ���memcpy����ԭ��ַ��Ŀ�ĵ�ַ�����غϵ�ȱ��*/
void* my_memmove(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	assert(dest&&src);

	if (dest<=src)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		dest = (char*)dest + count-1;
		src = (char*)src + count -1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			--(char*)dest;
			--(char*)src;
		}
	}
	return ret;
}
/*�Ժ���my_memmove�Ĳ���*/
void Test02(void)
{
	int arr[20] = { 0,0,0,0,0,0,0,0,0,0,10,20,30,40,50,60,70,80,90,100};

	my_memmove(arr, arr+10, sizeof(int) * 10);

	for (int i = 0; i < 20; i++)
	{
		printf("%d ", arr[i]);
	}
}

int my_memcmp(const void* buf1, const void* buf2, size_t count)
{
	while (count--)
	{
		if (*(char*)buf1 != *(char*)buf2)
			return (*(char*)buf1 - *(char*)buf2);
		++(char*)buf1;
		++(char*)buf2;
	}
	return 0;
}

/*�Ժ���my_memcmp�Ĳ���*/
void Test03(void)
{
	int arr1[10] = { 10,20,30,40,50,70,80 };
	int arr2[10] = { 10,20,30,40,50,60,70 };
	/*��ǰ����Ϊ��˴洢ģʽ*/
	int cmp = my_memcmp(arr1, arr2, sizeof(int) * 6);

	printf("\r\n%d\n", cmp);
}
/*ģ��ʵ��memset����*/
void* my_memset(void* dest, int c, size_t count)
{
	assert(dest);
	void* ret = dest;
	while(count--)
	{
		*((char*)dest)++ = c;
	}
	return ret;
}
/*��my_memset�����Ĳ���*/
void Test04(void)
{
	int arr[10] = {10,20,30,50,50,60};
	char str[10] = "abcdefg";

	/*��ǰ������˴洢ģʽ*/
	my_memset(arr + 3, 40, 1);
	my_memset(str + 3, '*', 3);

	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\r\n%s\n",str);
}

void test20(void)
{
	unsigned char temp = 0x10;
	int num = (int)(temp - 0x01);
	printf("%d",num);
}

/*������*/
int main(void)
{
	/*��my_memcpy�����Ĳ���*/
	Test01();

	printf("\n");
	/*�Ժ���my_memmove�Ĳ���*/
	Test02();

	/*�Ժ���my_memcmp�Ĳ���*/
	Test03();

	/*��my_memset�����Ĳ���*/
	Test04();

	test20();

	return 0;
}