#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>																					  
// 这是将两个有序的数组合并成一个数组的方法
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
// 	//将剩余的数组再次补充到尾部
// 	while (i < n)
// 	{
// 		c[k++] = a[i++];
// 	}
// 	while (j < m)
// 	{
// 		c[k++] = b[j++];
// 	}
// }

//看看所谓的函数递归是什么?

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


//从上面的函数推演出下面这段函数
//默置
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
	//同上面代码
	//将剩余的数组再次补充到尾部
	while (l <= m)
	{
		des[k++] = src[l++];
	}
	while (i <= high)
	{
		des[k++] = src[i++];
	}
	//这里的作用是 将排序好的数组里面的值整理出来放在src中, 好让函数
	//MSort(src, low, mid, des); 继续调用
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