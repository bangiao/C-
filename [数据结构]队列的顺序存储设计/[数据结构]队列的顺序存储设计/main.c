#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqQueue.h"
//顺序存储
int main(int argc, char *argv[])
{
	int ret = 0;
	int a[5] = { 0 };
	int i = 0;
	SeqQueue *queue = NULL;
	queue = SeqQueue_Create(10);
	if (NULL == queue)
	{
		printf("func SeqQueue_Create() err line:%d, file :%s\n", __LINE__, __FILE__);
		goto End;
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		ret = SeqQueue_Push(queue, &a[i]);
		if (0 != ret)
		{
			printf("func SeqQueue_Append() err line:%d, file:%s\n", __LINE__, __FILE__);
			return -2;
		}
	}

	printf("len:%d\n", SeqQueue_Length(queue));

	printf("front:%d\n", *((int *)SeqQueue_Front(queue)));

	printf("Capacity:%d\n", SeqQueue_Capacity(queue));

	while (SeqQueue_Length(queue) > 0)
	{
		int num = *((int *)SeqQueue_Pop(queue));
		printf("num:%d\n", num);
	}

	/*

//创建队列
SeqQueue *SeqQueue_Create(int Capacity);
//销毁队列
void SeqQueue_Destroy(SeqQueue *queue);
//清空队列
void SeqQueue_Clear(SeqQueue *queue);
//
int SeqQueue_Append(SeqQueue *queue, void *item);

void *SeqQueue_Retrieve(SeqQueue *queue);

void *SeqQueue_Header(SeqQueue *queue);

int SeqQueue_Length(SeqQueue *queue);

int SeqQueue_Capacity(SeqQueue *queue);
	*/
End:
	SeqQueue_Destroy(queue);
	system("pause");
	return ret;
}