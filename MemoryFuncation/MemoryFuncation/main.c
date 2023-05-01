#include <stdio.h>
#include <assert.h>

/*模拟实现memcpy内存拷贝函数		注：原地址不能与目的地址重合*/
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
/*对my_memcpy函数的测试*/
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
/*模拟实现memmove内存拷贝函数	可化解memcpy函数原地址和目的地址不能重合的缺陷*/
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
/*对函数my_memmove的测试*/
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

/*对函数my_memcmp的测试*/
void Test03(void)
{
	int arr1[10] = { 10,20,30,40,50,70,80 };
	int arr2[10] = { 10,20,30,40,50,60,70 };
	/*当前环境为大端存储模式*/
	int cmp = my_memcmp(arr1, arr2, sizeof(int) * 6);

	printf("\r\n%d\n", cmp);
}
/*模拟实现memset函数*/
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
/*对my_memset函数的测试*/
void Test04(void)
{
	int arr[10] = {10,20,30,50,50,60};
	char str[10] = "abcdefg";

	/*当前环境大端存储模式*/
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

/*主函数*/
int main(void)
{
	/*对my_memcpy函数的测试*/
	Test01();

	printf("\n");
	/*对函数my_memmove的测试*/
	Test02();

	/*对函数my_memcmp的测试*/
	Test03();

	/*对my_memset函数的测试*/
	Test04();

	test20();

	return 0;
}