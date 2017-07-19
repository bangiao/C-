#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//√∞≈›≈≈–Ú∆’Õ®∞Ê
void BubbleSort(int *pArray, int len)
{
	if (NULL == pArray || len <= 0)
	{
		return;
	}
	int i, j;
	int tmp;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (pArray[i] < pArray[j])
			{
				tmp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = tmp;
			}
		}
	}
}

//√∞≈›≈≈–Ú”≈ªØ∞Ê
void AdvBubbleSort(int *pArray, int len)
{
	if (NULL == pArray || len <= 0)
	{
		return;
	}
	int i, j;
	int tmp;
	int exchange = 1;

	for (i = 0; i < len && exchange; i++)
	{
		exchange = 0;
		for (j = 0; j < len; j++)
		{
			if (pArray[i] > pArray[j])
			{
				tmp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = tmp;
				exchange = 1;
			}
		}
	}
}
//√∞≈›≈≈–Ú”≈ªØ∞Êµƒ”≈ªØ∞Ê
void AdvAdvBubbleSort(int *pArray, int len)
{
	int i, j, tmp;

	int cnt = 0;

	int exchange = 1;


	for (i = 0; i < len - 1 && exchange; i++)
	{
		exchange = 0;
		for (j = 1; j < len; j++)
		{
			if (pArray[j] > pArray[j - 1])
			{
				tmp = pArray[j];
				pArray[j] = pArray[j - 1];
				pArray[j - 1] = tmp;
				exchange = 1;
			}
			cnt++;
			printf("%d:", cnt);
			for (int k = 0; k < len; k++)
			{
				printf("%d\t", pArray[k]);
			}
			puts("");
		}
	}
}

//√∞≈›À„∑®÷’º∂”≈ªØ∞Ê
void AdvAdvAdvBubbleSort(int *pArray, int len)
{
	int i, j, tmp;

	int cnt = 0;

	int exchange = 1;


	for (i = 0; i < len - 1 && exchange; i++)
	{
		exchange = 0;
		for (j = len - 1; j > i; j--)
		{
			if (pArray[j] > pArray[j - 1])
			{
				tmp = pArray[j];
				pArray[j] = pArray[j - 1];
				pArray[j - 1] = tmp;
				exchange = 1;
			}
			cnt++;
			printf("%d:", cnt);
			for (int k = 0; k < len; k++)
			{
				printf("%d\t", pArray[k]);
			}
			puts("");
		}
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int a[] = { 1, 5, 7, 4, 9, 99, 5, 22, 1, 0 };
	int len = sizeof(a) / sizeof(int);


	BubbleSort(a, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	puts("");
	AdvBubbleSort(a, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	puts("");
	
	AdvAdvBubbleSort(a, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	puts("");
	
	
	AdvAdvAdvBubbleSort(a, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	puts("");
	system("pause");
	return ret;
}