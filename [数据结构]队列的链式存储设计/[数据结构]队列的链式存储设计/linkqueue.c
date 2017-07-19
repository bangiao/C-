#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"
#include "linklist.h"

typedef struct _tag_LinkStack 
{
	TLinkListNode node;
	void *item;
}TLinkStack;

LinkQueue *LinkQueue_Create()
{
	return Linklist_Create();
}

void LinkQueue_Destroy(LinkQueue *queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue *queue)
{
	TLinkStack *tmp = NULL;
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Pop(queue);
	}
	LinkList_Clear(queue);
}

int LinkQueue_Push(LinkQueue *queue, void *item)
{
	TLinkStack *tmp = NULL;
	int ret = 0;
	tmp = (TLinkStack *)malloc(sizeof(TLinkStack));
	if (NULL == tmp)
	{
		printf("func LinkQueue_Push() err line:%d, file:%s\n", __LINE__, __FILE__);
		return 0;
	}
	memset(tmp, 0, sizeof(TLinkStack));
	tmp->item = item;
	ret = LinkList_Insert(queue, (TLinkListNode*)tmp, LinkQueue_Length(queue));
	if (0 != ret)
	{
		printf("func LinkList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		if (NULL != tmp)
		{
			free(tmp);
		}
		return ret;
	}
	return 0;
}

void *LinkQueue_Pop(LinkQueue *queue)
{
	void *item = NULL;
	TLinkStack *tmp = NULL;
	tmp = (TLinkStack *)LinkList_Delete(queue, 0);
	if (NULL == tmp)
	{
		printf("func LinkList_Delete() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	item = tmp->item;
	if (NULL != tmp)
		free(tmp);
	return item;
}

void *LinkQueue_Front(LinkQueue *queue)
{
	TLinkStack *tmp = NULL;
	tmp = (TLinkStack *)LinkList_Get(queue, 0);
	if (NULL == tmp)
	{
		printf("func LinkQueue_Front() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	return tmp->item;
}

int LinkQueue_Length(LinkQueue *queue)
{
	return LinkList_Length(queue);
}