/*
在一个由1 - 1000 的自然数组成的某大小的数组中  求出现次数最多的数字为什么?是多少?
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这段代码的主要思路是:
/*
1. 利用数组的标号也就是 int a[N] 这里的 N 这个标号 将这个标号作为从1 - 1000中的元素
	定义一个大小为 1000 的元素  为了能够存放 1000个元素
2. 将数组的标号当做自然数后只要将数组标号所对应的值标称这个自然数出现的次数就可以达到
	牺牲空间满足效率的功能
*/

void searchNum(int *Array, int ArrayLen)
{
	int i = 0;
	int buf[1000] = { 0 };
	int Index = 0;
	int nMax = 0;
	if (NULL == Array || 0 == ArrayLen)
	{
		system("pause");
		return ;
	}
	for (i = 0; i < ArrayLen; i++)
	{
		Index = Array[i] - 1;
		if (0 > Index)
		{
			continue;
		}
		else
		{
			buf[Index]++;
		}
	}

	for (i = 0; i < 1000; i++)
	{
		if (nMax < buf[i])
		{
			nMax = buf[i];
		}
	}

	for (i = 0; i < 1000; i++)
	{
		if (nMax == buf[i])
		{
			printf("%d\n", i + 1);
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int Array[32] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 6, 8, 5, 3, 5, 3, 3, 6, 3, 3 };
	
	searchNum(Array, sizeof(Array) / sizeof(int));
	system("pause");
	return ret;
}