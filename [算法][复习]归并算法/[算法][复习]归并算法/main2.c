#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>																					  
// ���ǽ��������������ϲ���һ������ķ���
// void MemeryArray(int *a, int n, int *b, int m, int *c)
// {
// 	int i, j, k;
// 	i = j = k = 0;
// 	while (i < n && j < m)
// 	{
// 		if (a[i] < b[j])
// 		{
// 			c[k++] = a[i++];
// 		}
// 		else
// 		{
// 			c[k++] = b[j++];
// 		}
// 	}
// 	//��ʣ��������ٴβ��䵽β��
// 	while (i < n)
// 	{
// 		c[k++] = a[i++];
// 	}
// 	while (j < m)
// 	{
// 		c[k++] = b[j++];
// 	}
// }

//������ν�ĺ����ݹ���ʲô?

// int add(int a)
// {
// 	int w = 1;
// 	if (a == w)
// 	{
// 		return w;
// 	}
// 	else
// 	{
// 		return add(a - 1) + a;
// 	}
// }
// 
// int add1(int a)
// {
// 	int w = 1;
// 	if (a == w)
// 	{
// 		return w;
// 	}
// 	else
// 	{
// 		return add2(a - 1) + a;
// 	}
// }
// 
// int add2(int a)
// {
// 	int w = 1;
// 	if (a == w)
// 	{
// 		return w;
// 	}
// 	else
// 	{
// 		return add1(a - 1) + a;
// 	}
// }


//������ĺ������ݳ�������κ���
//Ĭ��
void Merge(int *src, int low, int mid, int high, int *des)
{
	int l = low;
	int m = mid;
	int h = high;
	int i = mid + 1;
	int k = 0;

	while (l <= m && i <= h)
	{
		if (src[l] <= src[i])
		{
			des[k++] = src[l++];
		}
		else
		{
			des[k++] = src[i++];
		}
	}
	//ͬ�������
	//��ʣ��������ٴβ��䵽β��
	while (l <= m)
	{
		des[k++] = src[l++];
	}
	while (i <= high)
	{
		des[k++] = src[i++];
	}
	//����������� ������õ����������ֵ�����������src��, ���ú���
	//MSort(src, low, mid, des); ��������
	for (int n = 0; n < k; n++)
	{
		src[low + n] = des[n];
	}
}

void MSort(int *src, int low, int high, int *des)
{
	if (low < high)
	{
		int mid;
		mid = (low + high) / 2;
		MSort(src, low, mid, des);
		MSort(src, mid + 1, high, des);
		Merge(src, low, mid, high, des);
	}
}

void MergeSort(int *pArray, int len)
{
	int *p = NULL;
	p = (int *)malloc(sizeof(int) * len);
	if (NULL == p)
	{
		return;
	}
	MSort(pArray, 0, len - 1, p);
	free(p);
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
	//int sum = add1(10);
	//printf("sum = %d\n", sum);
	int buf[] = { 5, 64, 531, 23, 15, 3, 2, 1, 53, 4, 8, 6, 5, 31, 2, 38, 4 };
	int len = sizeof(buf) / sizeof(buf[0]);
	printArray(buf, len);
	MergeSort(buf, len);
	printArray(buf, len);
	system("pause");
	return ret;
}