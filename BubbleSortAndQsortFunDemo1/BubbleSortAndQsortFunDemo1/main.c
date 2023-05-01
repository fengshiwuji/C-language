#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "sort.h"

//整型比较函数
int cmp_int(const void* dat1, const void* dat2)
{
	return (* ((int*)dat1) - *((int*)dat2));
}

//字符比较函数
int cmp_char(const void* dat1, const void* dat2)
{
	return (*((char*)dat1) - *((char*)dat2));
}

//float 比较函数
int cmp_float(const void* dat1, const void* dat2)
{
	float* pf1 = (float*)dat1;
	float* pf2 = (float*)dat2;
	float ret = *pf1 - *pf2;

	if (ret > -0.000001 && ret < 0.000001)
		return 0;
	else if (ret > 0)
		return 1;
	else
		return 0;
}


//QsortByBubbleSort函数测试
void QsortByBubbleSortTestFun(void)
{
	int i = 0;
	char str[20] = "fedcba";
	int arr[10] = { 9,6,7,0,8,3,2,5,4,1 };
	float fdata[10] = {1.0,2.0,8.0,3.0,5.1,1.101,1.110,0.0001,1.00001,2.10005};

	size_t len = strlen((const char*)str);
	size_t size = sizeof(arr) / sizeof(arr[0]);

	QsortByBubbleSort((void*)arr,size,sizeof(arr[0]),cmp_int);
	QsortByBubbleSort((void*)str,len, sizeof(char), cmp_char);
	QsortByBubbleSort((void*)fdata, 10, sizeof(fdata[0]), cmp_float);
	for (i = 0; i < size; i++)
		printf("%d\t", arr[i]);
	printf("\r\nstr: %s\r\n", str);

	for (i = 0; i < 10; i++)
		printf("%f\t", fdata[i]);
}

//如何比较一个浮点数是否等于0
void cmpFloatZeroTest(void)
{
	int input = 0;
	float input1 = 0;
	float input2 = 0;
	do 
	{
		printf("请输入第一个浮点数:");
		scanf("%f",&input1);
		printf("\r\n请输入第二个浮点数:");
		scanf("%f", &input2);
		float ret = input1-input2;
		if (ret > -0.000001 && ret < 0.000001)
			printf("\r\ninput1==input2\r\n");
		else
			printf("\r\ninput1!=input2\r\n");
		printf("是否继续1/0:");
		scanf("%d",&input);
	} while (input);
}

//主函数
int main(void)
{
	//QsortByBubbleSortTestFun();
	cmpFloatZeroTest();

	return 0;
}
