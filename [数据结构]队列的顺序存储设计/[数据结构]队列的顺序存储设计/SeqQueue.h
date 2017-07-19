#pragma once

typedef void SeqQueue;

//创建队列
SeqQueue *SeqQueue_Create(int Capacity);
//销毁队列
void SeqQueue_Destroy(SeqQueue *queue);
//清空队列
void SeqQueue_Clear(SeqQueue *queue);
//
int SeqQueue_Push(SeqQueue *queue, void *item);

void *SeqQueue_Pop(SeqQueue *queue);

void *SeqQueue_Front(SeqQueue *queue);

int SeqQueue_Length(SeqQueue *queue);

int SeqQueue_Capacity(SeqQueue *queue);

