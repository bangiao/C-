#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Swap(int *pArray, int low, int high)
{
	int tmp;
	tmp = pArray[low];
	pArray[low] = pArray[high];
	pArray[high] = tmp;
}
//
int partition(int *pArray, int low, int high)
{
	int pv = pArray[low];

	while (low < high)
	{
		while (low < high && pArray[high] >= pv)
		{
			high--;
		}
		Swap(pArray, low, high);
		while (low < high && pArray[low] <= pv)
		{
			low++;
		}
		Swap(pArray, low, high);
	}
	return low;
}

void Qsort(int *pArray, int low, int high)
{
	if (low < high)
	{
		int pv = partition(pArray, low, high);

		Qsort(pArray, low, pv - 1);

		Qsort(pArray, pv + 1, high);
	}
}

void QuickSort(int *pArray, int len)
{
	Qsort(pArray, 0, len - 1);
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int Array[] = { 12, 5 };
	int len = sizeof(Array) / sizeof(int);

	QuickSort(Array, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", Array[i]);
	}
	
	system("pause");
	return ret;
}