#include "sort.h"


/************************************************************************
�������ܣ�����������ֵ��
����������arr1��ָ���һ��������
		  arr2: ָ��ڶ���������
����ֵ��None.
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
�������ܣ�����ð������ģ��ʵ�� �⺯����qsort��
����������base:����������Ļ���ַ��
		  num: ������Ԫ�صĸ�����
		  width:ÿ��Ԫ�صĴ�С��
		  compare:һ��ָ��ȽϺ�����ָ�룬�ȽϺ������û��Լ�ʵ�֡�
����ֵ��None.
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