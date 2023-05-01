#include <stdio.h>
#include "memery.h"

//memcpyº¯Êý²âÊÔ
void memcpyTestFun(void)
{
	int i = 0;
	int arr1[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr2[10];
	int size = sizeof(arr1);
	
	int*parr = (int*)my_memcpy(arr2,arr1,size);

	for (i = 0; i < 10; i++)
		printf("%d\t", parr[i]);
	printf("\n");
}

//memcmpº¯Êý²âÊÔ
void memcmpTestFun(void)
{
	int arr1[10] = {9,8,7,6,5,4,3,2,1,0 };
	int arr2[10] = {9,8,7,6,5,0,1,2,3,4};
	int size = sizeof(arr1);

	int ret = my_memcmp(arr2, arr1, size);

	printf("%d\t", ret);
	
	printf("\n");
}

//memmoveº¯Êý²âÊÔ
void memmoveTestFun(void)
{
	int i = 0;
	char arr[20] = "hello world";
	
	my_memmove(arr,arr,strlen(arr));

	printf("%s\n", arr);
}

//memsetº¯Êý²âÊÔ
void memsetTestFun(void)
{
	int i = 0;
	char arr[20] = "hello world";

	my_memset(arr,'*', strlen(arr));

	printf("%s\n", arr);
}

//Ö÷º¯Êý
int main(void)
{
	//memcpyTestFun();
	//memcmpTestFun();
	//memmoveTestFun();
	memsetTestFun();

	return 0;
}
