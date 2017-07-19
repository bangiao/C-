#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1 元素拿出来
//2 符合条件的元素后移(比较大的元素往后移)

void InsertionSort(int *pArray, int len)
{
	int i, j;
	int k;
	int temp;
	if (NULL == pArray || len <= 0)
	{
		return;
	}
	for (i = 1; i < len; i++)
	{
		k = i;	//待插入的位置
		temp = pArray[k];
		for (j = i - 1; (j >= 0) && (pArray[j] > temp); j--)
		{
			pArray[j + 1] = pArray[j];	//元素后移
			k = j;	//需要插入的位置
		}
		pArray[k] = temp;	//元素插入
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int pArray[] = { 12, 5, 33, 65, 15555, 1 };
	int len = sizeof(pArray) / sizeof(int);

	InsertionSort(pArray, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", pArray[i]);
	}
	puts("");
	system("pause");
	return ret;
}