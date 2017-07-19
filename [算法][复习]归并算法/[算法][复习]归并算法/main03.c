#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//默置
void Merge(int *src, int *des, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while (i <= mid && j <= high)
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)
	{
		des[k++] = src[i++];
	}
	while (j <= high)
	{
		des[k++] = src[j++];
	}
}

//分组
void MSort(int *src, int *des, int low, int high, int max)
{
	int *tmp = NULL;
	int mid = 0;

	if (low == high)
	{
		des[low] = src[low];
	}
	else
	{
		mid = (low + high) / 2;
		tmp = (int *)malloc(sizeof(int) * max);
		if (NULL != tmp)
		{
			MSort(src, tmp, low, mid, max);
			MSort(src, tmp, mid + 1, high, max);
			Merge(tmp, des, low, mid, high);
		}
		free(tmp);
	}
}

//归并排序
void MergeSort(int *pArray, int len)
{
	MSort(pArray, pArray, 0, len - 1, len);
}

//输出数组
void printA(int *pArray, int len)
{
	int i = 0; 
	for (i = 0; i < len; i++)
	{
		printf("%d\t", pArray[i]);
	}
	puts("");
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int buf[] = { 1, 2, 13, 2, 32, 43, 4, 345, 34, 3, 43, 5, 345, 34, 655, 65, 76, 57, 6, 867, 9, 645, 6 };

	int len = sizeof(buf) / sizeof(buf[0]);

	printA(buf, len);
	MergeSort(buf, len);
	printA(buf, len);
	system("pause");
	return ret;
}