#include "sort.h"


/************************************************************************
函数功能：交换变量的值。
函数参数：arr1：指向第一个变量。
		  arr2: 指向第二个变量。
返回值：None.
************************************************************************/
static void myswap(void* arr1, void* arr2,size_t width)
{
	char* pch1 = (char*)arr1;
	char* pch2 = (char*)arr2;

	while (width--)
	{
		*pch1 = *pch1 ^ *pch2;
		*pch2 = *pch1 ^ *pch2;
		*pch1 = *pch1 ^ *pch2;
		pch1++;
		pch2++;
	}
}

/************************************************************************
函数功能：利用冒泡排序模拟实现 库函数：qsort。
函数参数：base:待排序数组的基地址。
		  num: 待排序元素的个数。
		  width:每个元素的大小。
		  compare:一个指向比较函数的指针，比较函数由用户自己实现。
返回值：None.
************************************************************************/
void QsortByBubbleSort(void* base,size_t num,size_t width,int(* compare)(const void* elem1, const void* elem2))
{
	int i = 0,j = 0;
	char* pch = (char*)base;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (compare(pch + j * width, pch + (j + 1) * width) > 0)
			{
				myswap(pch + j * width, pch + (j + 1) * width,width);
			}
		}
	}

}