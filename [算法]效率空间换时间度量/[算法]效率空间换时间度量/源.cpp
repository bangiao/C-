/*
��һ����1 - 1000 ����Ȼ����ɵ�ĳ��С��������  ����ִ�����������Ϊʲô?�Ƕ���?
*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��δ������Ҫ˼·��:
/*
1. ��������ı��Ҳ���� int a[N] ����� N ������ ����������Ϊ��1 - 1000�е�Ԫ��
	����һ����СΪ 1000 ��Ԫ��  Ϊ���ܹ���� 1000��Ԫ��
2. ������ı�ŵ�����Ȼ����ֻҪ������������Ӧ��ֵ��������Ȼ�����ֵĴ����Ϳ��Դﵽ
	�����ռ�����Ч�ʵĹ���
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