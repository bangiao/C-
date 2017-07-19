#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqQueue.h"
#include "seqlist.h"

//��������
SeqQueue *SeqQueue_Create(int Capacity)
{
	return List_Create(Capacity);
}
//���ٶ���
void SeqQueue_Destroy(SeqQueue *queue)
{
	List_Destory(&queue);
	return ;
}
//��ն���
void SeqQueue_Clear(SeqQueue *queue)
{
	List_Clear(queue);
	return ;
}
//
int SeqQueue_Push(SeqQueue *queue, void *item)
{
	return List_Insert(queue, item, SeqQueue_Length(queue));;
}

void *SeqQueue_Pop(SeqQueue *queue)
{
	return List_Delete(queue, 0);
}

void *SeqQueue_Front(SeqQueue *queue)
{
	return List_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue *queue)
{
	return List_Length(queue);
}

int SeqQueue_Capacity(SeqQueue *queue)
{
	return  List_Capacity(queue);
}