#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublelist.h"
//doublelist.c
typedef struct _tag_DoubleList
{
	DoubleListnode node;
	DoubleListnode *slider;
	int Length;
}TList;

vDoubleList* DoubleList_Create()
{
	TList *tList = (TList *)malloc(sizeof(TList));
	if (NULL == tList)
	{
		return NULL;
	}
	tList->Length = 0;
	tList->node.pNext = NULL;
	tList->node.pPre = NULL;
	tList->slider = NULL;
	return (vDoubleList*)tList;
}

void DoubleList_Destroy(vDoubleList* list)
{
	TList *tList = (TList *)list;
	if (NULL != tList)
	{
		free(tList);
	}
}

void DoubleList_Clear(vDoubleList* list)
{
	TList *tList = (TList *)list;
	if (NULL == tList)
	{
		return;
	}
	tList->Length = 0;
	tList->node.pNext = NULL;
	tList->node.pPre = NULL;
	tList->slider = NULL;
}

int DoubleList_Length(vDoubleList* list)
{
	TList *tList = (TList *)list;
	if (NULL == tList)
	{
		return -1;
	}
	return (tList->Length);
}

int DoubleList_Insert(vDoubleList* list, DoubleListnode* node, int pos)
{
	TList *tList = (TList *)list;
	DoubleListnode *Cur = (DoubleListnode *)list;
	DoubleListnode *Next = NULL;
	int ret = 0;
	int i = 0;
	if (NULL == tList || NULL == node || pos < 0)
	{
		return -1;
	}

	for (i = 0; i < pos && Cur->pNext != NULL; i++)
	{
		Cur = Cur->pNext;
	}
	Next = Cur->pNext;

	Cur->pNext = node;			//pNext
	node->pNext = Cur->pNext;	//新数据的pNext
	node->pPre = Cur;			//新数据的pPre
	if (NULL != Next)
	{
		Next->pPre = node;		//后一个数据pPre
	}
	if (0 == tList->Length)
	{
		tList->slider = node;
	}
	tList->Length++;
	if (Cur == (DoubleListnode *)tList)
	{
		DoubleListnode *last = DoubleList_Get(list, tList->Length - 1);
		last->pNext = Cur->pNext;
	}
	return 0;
}

DoubleListnode* DoubleList_Get(vDoubleList* list, int pos)
{
	TList *tList = (TList *)list;
	int i = 0;
	DoubleListnode *Cur = (DoubleListnode *)list;
	if (NULL == tList || pos < 0 || tList->Length < pos)
	{
		return NULL;
	}
	for (i = 0; i < pos && tList->Length > pos; i++)
	{
		Cur = Cur->pNext;
	}
	Cur = Cur->pNext;
	return (DoubleListnode*)Cur;
}

DoubleListnode* DoubleList_Delete(vDoubleList* list, int pos)
{
	int i = 0;
	if (list == NULL)
	{
		return NULL;
	}
	TList * tlist = (TList *)list;
	//位置判断
	if (pos<0 || pos > tlist->Length)
	{
		return NULL;
	}
	//普通情况处理
	//定义两个变量 
	DoubleListnode * pPrior = &tlist->node, *pCurrent = tlist->node.pNext, *pNext = NULL;
	for (i = 0; i < pos; i++)
	{
		pPrior = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	pNext = pCurrent->pNext;
	pPrior->pNext = pNext;
	if (pNext != NULL)
	{
		pNext->pPre = pPrior;
		//判断删除的是否是第0个元素
		if (pPrior == &tlist->node)
		{
			pNext->pPre = NULL;
		}
	}
	tlist->Length--;
	return pCurrent;
}

//add

DoubleListnode* DoubleList_DeleteNode(vDoubleList* list, DoubleListnode* node)
{
	int i = 0;
	if (list == NULL || node == NULL)
	{
		return NULL;
	}
	TList * tlist = (TList *)list;
	DoubleListnode * pCur = &tlist->node;
	for (i = 0; i < tlist->Length; i++)
	{
		pCur = pCur->pNext;
		if (pCur == node)
		{
			break;
		}
	}
	return DoubleList_Delete(list, i);
}

DoubleListnode* DoubleList_Reset(vDoubleList* list)
{
	if (list == NULL)
	{
		return NULL;
	}
	TList * tlist = (TList *)list;
	tlist->slider = tlist->node.pNext;
	return tlist->slider;
}

DoubleListnode* DoubleList_Current(vDoubleList* list)
{
	if (list == NULL)
	{
		return NULL;
	}
	TList * tlist = (TList *)list;
	return tlist->slider;
}

DoubleListnode* DoubleList_Next(vDoubleList* list)
{
	if (list == NULL)
	{
		return NULL;
	}
	TList * tlist = (TList *)list;
	if (tlist->slider == NULL)
	{
		return NULL;
	}
	tlist->slider = tlist->slider->pNext;
	return tlist->slider;
}

DoubleListnode *DoubleList_Pre(vDoubleList *list)
{
	if (list == NULL)
	{
		return NULL;
	}
	TList * tlist = (TList *)list;
	if (tlist->slider == NULL)
	{
		return NULL;
	}
	tlist->slider = tlist->slider->pPre;
	return tlist->slider;
}