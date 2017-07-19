#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

typedef struct _tag_LinkList 
{
	TLinkListNode node;
	int Length;
}TLinkList;

LinkList *LinkList_Create()
{
	TLinkList *list = NULL;
	list = (TLinkList *)malloc(sizeof(TLinkList));
	if (NULL == list)
	{
		printf("func LinkList_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	list->Length = 0;
	list->node.next = NULL;
	return list;
}

void LinkList_Destroy(LinkList *list)
{
	if (NULL != list)
	{
		free(list);
	}
}

void LinkList_Clear(LinkList *list)
{
	memset(list, 0, sizeof(list));
}

int LinkList_Length(LinkList *list)
{
	TLinkList *tlist = NULL;
	if (NULL == list)
	{
		printf("func LinkList_Length() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	tlist = list;
	return tlist->Length;
}

TLinkListNode *LinkList_Get(LinkList *list, int pos)
{
	TLinkList *tlist = NULL;
	TLinkListNode *ret;
	TLinkListNode *pCur;
	int i = 0;

	if (NULL == list)
	{
		printf("func LinkList_Length() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	tlist = list;
	pCur = (TLinkListNode *)list;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	ret = pCur->next;
	return ret;
}

TLinkListNode *LinkList_Delete(LinkList *list, int pos)
{
	TLinkList *tlist = NULL;
	TLinkListNode *ret;
	TLinkListNode *pCur;
	int i = 0;

	if (NULL == list || pos < 0)
	{
		printf("func LinkList_Length() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	tlist = list;
	pCur = (TLinkListNode *)list;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	ret = pCur->next; //获取当前要删除的节点
	pCur->next = ret->next;//把1号位置的节点的next域指向下下一个节点的地址也就是下一个节点的next域
	tlist->Length--;
	return ret;
}

int LinkList_Insert(LinkList *list, TLinkListNode *Node, int pos)
{
	TLinkList *tlist = NULL;
	TLinkListNode *pCur;
	int i = 0;

	if (NULL == list || pos < 0)
	{
		printf("func LinkList_Length() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	tlist = list;
	pCur = (TLinkListNode *)list;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	Node->next = pCur->next;
	pCur->next = Node;
	tlist->Length++;
	return 0;
}