#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���ȶ��㷨
//ͻ�ƴ� O (n ^ 2)

void printBuf(int *pArray, int len)
{
	int i = 0;
	if (NULL == pArray || 0 >= len)
	{
		printf("func err printBuf line:%d, file :%s\n", __LINE__, __FILE__);
		return;
	}

	for (i = 0; i < len; i++)
	{
		printf("%d\t", pArray[i]);
	}
	puts("");
}

//�Ѵ��������ŵ�����
void ShellSort01(int *pArray, int len)
{
	int i, j, k, tmp;
	int gap = len;

	do 
	{
		gap = gap / 3 + 1;
		for (i = gap; i < len; i += gap)
		{
			k = i;
			tmp = pArray[k];
			//								tmp > pArray[j] ������ںŴ����������Ӵ�С���Ǵ�С����
			for (j = i - gap; j >= 0 && tmp > pArray[j]; j -= gap)
			{
				pArray[j + gap] = pArray[j];
				k = j;
			}
			pArray[k] = tmp;
		}
	} while (gap > 1);
}

void ShellPort02(int *pArray, int len)
{
	int i, j, k, tmp;
	int gap = len;

	do 
	{
		gap = gap / 3 + 1;
		for (i = gap; i < len; i += gap)
		{
			k = i;
			tmp = pArray[k];
			for (j = i - gap; j >= 0 && tmp < pArray[j]; j -= gap)
			{
				pArray[j + gap] = pArray[j];
				k = j;
			}
			pArray[k] = tmp;
		}
	} while (gap > 1);
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int buf[] = { 45, 12, 654, 23, 8932, 9, 532, 213, 987, 3, 5, 546, 354 };
	int i = 0;
	int len = sizeof(buf) / sizeof(buf[0]);

	//�Ӵ�С
	ShellSort01(buf, len);
	//��С����
	//ShellPort02(buf, len);
	printBuf(buf, len);
	system("pause");
	return ret;
}