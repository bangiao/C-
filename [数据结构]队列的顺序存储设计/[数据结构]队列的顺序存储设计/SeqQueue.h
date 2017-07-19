#pragma once

typedef void SeqQueue;

//��������
SeqQueue *SeqQueue_Create(int Capacity);
//���ٶ���
void SeqQueue_Destroy(SeqQueue *queue);
//��ն���
void SeqQueue_Clear(SeqQueue *queue);
//
int SeqQueue_Push(SeqQueue *queue, void *item);

void *SeqQueue_Pop(SeqQueue *queue);

void *SeqQueue_Front(SeqQueue *queue);

int SeqQueue_Length(SeqQueue *queue);

int SeqQueue_Capacity(SeqQueue *queue);

