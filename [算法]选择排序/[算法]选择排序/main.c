#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数组元素值得交换
void FuncSwap(int *pArray, int i, int j)
{
	int tmp;
	tmp = pArray[i];
	pArray[i] = pArray[j];
	pArray[j] = tmp;
}
//打印数组
void printArray(int *pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", pArray[i]);
	}
	puts("");
}
//选择排序核心算法
//核心思想是:
//	扫描一遍, 找出最小值得标号, 与当前位置交换即可.(数组有多长当前位置就有几个)
//  这种算法的速度会比冒泡排序的速度会快一点
//	冒泡排序是将小的数字与后一位一次对比, 且每次对比如果符合都要往后移动一次
// 	而选择排序则不然, 它会先将整个数据扫描一遍, 然后进行一次交换
void SelectionSort(int *pArray, int len)
{
	int i, j, min;
	
	//选择当前位置
	for (i = 0; i < len; i++)
	{
		min = i;
		//这个for循环的主要目的是
		//找出最小的数值的数组标号
		//就是将当前位置与这个数组中(当前位置的后一个位置开始)依次作比较
		for (j = i + 1; j < len; j++)
		{
			if (pArray[j] < pArray[min])
			{
				min = j;//找出来
			}
		}
		if (min != i)
			FuncSwap(pArray, i, min);//将这个最小的值和 i (当前位置)的值进行交换
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int pArray[] = { 22, 1111, 2223, 44445, 333, 5555555 };
	SelectionSort(pArray, sizeof(pArray) / sizeof(int));
	printArray(pArray, sizeof(pArray) / sizeof(int));
	system("pause");
	return ret;
}