#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����Ԫ��ֵ�ý���
void FuncSwap(int *pArray, int i, int j)
{
	int tmp;
	tmp = pArray[i];
	pArray[i] = pArray[j];
	pArray[j] = tmp;
}
//��ӡ����
void printArray(int *pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", pArray[i]);
	}
	puts("");
}
//ѡ����������㷨
//����˼����:
//	ɨ��һ��, �ҳ���Сֵ�ñ��, �뵱ǰλ�ý�������.(�����ж೤��ǰλ�þ��м���)
//  �����㷨���ٶȻ��ð��������ٶȻ��һ��
//	ð�������ǽ�С���������һλһ�ζԱ�, ��ÿ�ζԱ�������϶�Ҫ�����ƶ�һ��
// 	��ѡ��������Ȼ, �����Ƚ���������ɨ��һ��, Ȼ�����һ�ν���
void SelectionSort(int *pArray, int len)
{
	int i, j, min;
	
	//ѡ��ǰλ��
	for (i = 0; i < len; i++)
	{
		min = i;
		//���forѭ������ҪĿ����
		//�ҳ���С����ֵ��������
		//���ǽ���ǰλ�������������(��ǰλ�õĺ�һ��λ�ÿ�ʼ)�������Ƚ�
		for (j = i + 1; j < len; j++)
		{
			if (pArray[j] < pArray[min])
			{
				min = j;//�ҳ���
			}
		}
		if (min != i)
			FuncSwap(pArray, i, min);//�������С��ֵ�� i (��ǰλ��)��ֵ���н���
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