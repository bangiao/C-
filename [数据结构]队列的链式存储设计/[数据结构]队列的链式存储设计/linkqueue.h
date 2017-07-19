#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

typedef void LinkQueue;

LinkQueue *LinkQueue_Create();

void LinkQueue_Destroy(LinkQueue *queue);

void LinkQueue_Clear(LinkQueue *queue);

int LinkQueue_Push(LinkQueue *queue, void *item);

void *LinkQueue_Pop(LinkQueue *queue);

void *LinkQueue_Front(LinkQueue *queue);

int LinkQueue_Length(LinkQueue *queue);

#endif