#include "CircleList.h"
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct _tag_CircleListNode
{
struct _tag_CircleListNode * next;
}CircleListNode;
*/

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
} TCircleList;

CircleList* CircleList_Create()
{
	TCircleList *tlist = (TCircleList *)malloc(sizeof(TCircleList));
	if (NULL == tlist)
	{
		printf("func CircleList_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	memset(tlist, 0, sizeof(TCircleList));
	return tlist;
}

void List_Destroy(CircleList* list)
{
	TCircleList *tlist = list;
	if (NULL == tlist)
	{
		printf("func List_Destroy() err line:%d, file:%s\n", __LINE__, __FILE__);
		return ;
	}
	memset(tlist, 0, sizeof(TCircleList));
	free(tlist);
	list = NULL;
	return ;
}

void CircleList_Clear(CircleList* list)
{
	TCircleList *tlist = list;
	if (NULL == tlist)
	{
		printf("func CircleList_Clear() err line:%d, file:%s\n", __LINE__, __FILE__);
		return;
	}
	memset(list, 0, sizeof(TCircleList));
	return ;
}

int CircleList_Length(CircleList* list)
{
	TCircleList *tlist = list;
	if (NULL == tlist)
	{
		printf("func CircleList_Length() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	return tlist->length;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	TCircleList *tlist = list;
	int i = 0;
	CircleListNode *pCur = NULL;
	if (NULL == tlist || NULL == node || pos < 0)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	pCur = (CircleListNode *)list;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	node->next = pCur->next;			//1
	pCur->next = node;					//2
	tlist->length++;
	if (pCur == (CircleListNode*)tlist)
	{
		//获取最后一个元素
		CircleListNode* last = CircleList_Get(tlist, tlist->length - 1);
		last->next = pCur->next;		//3
	}
	return 0;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TCircleList *tlist = list;
	int i = 0;
	CircleListNode *pCur = NULL;
	if (NULL == list || pos < 0)
	{
		printf("func CircleList_Get() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	pCur = (CircleListNode *)list;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	return pCur->next;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList *tlist = list;
	int i = 0;
	CircleListNode *pCur = NULL;
	CircleListNode *pNext = NULL;
	CircleListNode *last = NULL;

	if (NULL == list || pos < 0)
	{
		printf("func CircleList_Get() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	pCur = (CircleListNode *)list;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	if (pCur == (CircleListNode *)list)
	{
		last = CircleList_Get(list, tlist->length - 1);
	}
	pNext = pCur->next;
	pCur->next = pNext->next;
	tlist->length--;
	if (NULL != last)
	{
		last->next = pNext->next;
	}
	if (tlist->slider == pNext)
	{
		tlist->slider = pNext->next;
	}
	if (0 == tlist->length)
	{
		tlist->header.next = NULL;
		tlist->slider = NULL;
	}
	return pNext;
}

//add

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	CircleListNode *pCur = NULL;
	TCircleList *tlist = NULL;
	CircleListNode *ret = NULL;
	int i = 0;
	if (NULL == list || NULL == node)
	{
		printf("func CircleList_DeleteNode() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	tlist = (TCircleList *)list;
	pCur = (CircleListNode *)list;
	for (i = 0; i < tlist->length; i++)
	{
		if (pCur->next == node)
		{
			ret = pCur->next;
			break;
		}
		pCur = pCur->next;
	}
	if (NULL != ret)
	{
		CircleList_Delete(list, i);
	}
	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
	if (NULL == list)
	{
		printf("func CircleList_Reset() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	TCircleList *tlist = (TCircleList*)list;
	tlist->slider = tlist->header.next;
	return tlist->slider;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	if (NULL == list)
	{
		printf("func CircleList_Current() err line:%d, flie:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	TCircleList *tlist = (TCircleList *)list;

	return tlist->slider;
}

CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode *ret = NULL;
	if (NULL == list || NULL == tlist->slider)
	{
		printf("func CircleList_Current() err line:%d, flie:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	ret = tlist->slider;
	tlist->slider = tlist->slider->next;
	return ret;
}