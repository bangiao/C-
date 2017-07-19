#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seqlist.h"

typedef struct _tag_LinkList 
{
	LinkListNode Tnode;
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *tList = (TLinkList *)malloc(sizeof(TLinkList));
	if (NULL == tList)
	{
		return NULL;
	}
	tList->Tnode.pNext = NULL;
	tList->length = 0;
	return (LinkList*)tList;
}

void LinkList_Destroy(LinkList* list)
{
	if (NULL != list)
	{
		free(list);
	}
	return ;
}


void LinkList_Clear(LinkList* list)
{
	TLinkList *tList = (TLinkList *)list;
	if (NULL == tList)
	{
		return;
	}
	tList->length = 0;
	return ;
}


int LinkList_Length(LinkList* list)
{
	TLinkList *tList = (TLinkList *)list;
	if (NULL == tList)
	{
		return -1;
	}
	return (tList->length);
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList *tList = (TLinkList *)list;
	LinkListNode *Cur = NULL;
	if (NULL == tList || NULL == node || pos < 0 || pos > tList->length)
	{
		return -1;
	}
	Cur = (LinkListNode *)list;
	for (int i = 0; i < pos || Cur->pNext != NULL; i++)
	{
		Cur = Cur->pNext;
	}
	node->pNext = Cur->pNext;
// 	�����Cur����ָ��ǰ�ڵ���������ڵ��pNextָ��ĵ�ַ����һ��Ԫ�صĵ�ַ
// 	Ϊ�˲����µ�����������Ԫ��node������Ҫ�������Cur->pNext
// 	Ȼ�󽫵�ǰ�ڵ����һ����ַ�ĳ��µ����ݵ�ַnode�����Ļ� 
// 	�µĽڵ�ͳ��׼ӽ�����node�ĵ�ַ��ǰһ����ַ��pNext
// 	node��pNext����һ���ڵ�ĵ�ַ
	Cur->pNext = node;
	tList->length++;
	return 0;
}


LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	TLinkList *tList = (TLinkList *)list;
	LinkListNode *Cur = NULL;
	Cur = (LinkListNode *)list;
	if (NULL == list || pos < 0 || tList->length < pos)
	{
		return NULL;
	}
	for (int i = 0; i < pos; i++)
	{
		Cur = Cur->pNext;
	}
	return (Cur->pNext);
}


LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList *tList = (TLinkList *)list;
	LinkListNode *pPr = NULL;
	LinkListNode *Cur = NULL;
	pPr = (LinkListNode *)list;
	Cur = pPr->pNext;
	if (NULL == list || pos < 0 || tList->length < pos)
	{
		return NULL;
	}
	for (int i = 0; i < pos - 1; i++)
	{
		pPr = pPr->pNext;
		Cur = Cur->pNext;
	}
	pPr->pNext = Cur->pNext;
	// ���˸� length --
	return (LinkListNode* )list;
}
