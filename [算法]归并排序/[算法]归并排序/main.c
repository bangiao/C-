#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(int *src, int *des, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i <= mid) && (j <= high))
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

void MSort(int *src, int *des, int low, int high, int max)
{
	if (low == high)
	{
		des[low] = src[low];
	}
	else
	{
		int mid = (low + high) / 2;
		int *space = (int *)malloc(sizeof(int) * max);

		if (NULL != space)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high);
		}
		free(space);
	}
}

void MergeSort(int *pArray, int len)
{
	MSort(pArray, pArray, 0, len - 1, len);
}

void printArray(int *pArray, int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		printf("%d ", pArray[i]);
	}
	puts("");
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int pArray[] = { 21, 25, 49, 25, 16, 8 };
	int len = sizeof(pArray) / sizeof(int);

	printArray(pArray, len);

	MergeSort(pArray, len);

	printArray(pArray, len);
	
	system("pause");
	return ret;
}