#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circlelist.h"

typedef struct _tag_CircleList
{
	CircleListNode node;	//Linux链表指针
	CircleListNode* slider;	//游标
	int Length;
}TCircleList;

CircleList* LinkList_Create()
{
	TCircleList *list = (TCircleList *)malloc(sizeof(TCircleList));
	if (NULL == list)
	{
		return NULL;
	}
	list->Length = 0;
	list->node.pNext = NULL;
	list->slider = NULL;
	return list;
}

int CircleList_Length(CircleList* list)
{
	TCircleList *tList = (TCircleList *)list;
	if (NULL == tList)
	{
		return -1;
	}
	return (tList->Length);
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	TCircleList *tList = (TCircleList *)list;
	int i = 0;
	CircleListNode *Cur = (CircleListNode *)tList;
	if (NULL == tList || NULL == node || pos < 0 || pos > tList->Length)
	{
		return -1;
	}
	for (i = 0; (i < pos) && (Cur->pNext != NULL); i++)
	{
		Cur = Cur->pNext;
	}
	//链表通用代码 不论是否在第一个位置
	node->pNext = Cur->pNext;	//1
	Cur->pNext = node;			//2

	//若第一次插入节点  游标初始化
	if (0 == tList->Length)
	{
		tList->slider = node;
	}
	tList->Length++;
	if (Cur == (CircleListNode *)tList)
	{
		CircleListNode* last = CircleList_Get(tList, tList->Length - 1);
		last->pNext = Cur->pNext;	
	}
	return 0;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TCircleList *tList = (TCircleList *)list;
	int i = 0;
	CircleListNode *Cur = (CircleListNode *)tList;
	if (NULL == tList || pos < 0 || pos > tList->Length)
	{
		return NULL;
	}
	for (i = 0; (i < pos); i++)
	{
		Cur = Cur->pNext;
	}
	return Cur->pNext;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList* tList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if ((tList != NULL) && (pos >= 0) && (tList->Length > 0))
	{
		CircleListNode* current = (CircleListNode*)tList;
		CircleListNode* last = NULL;

		for (i = 0; i < pos; i++)
		{
			current = current->pNext;
		}

		//若删除第一个元素
		if (current == (CircleListNode*)tList)
		{
			last = (CircleListNode*)CircleList_Get(tList, tList->Length - 1);
		}

		//求要删除的元素
		ret = current->pNext;
		current->pNext = ret->pNext;

		tList->Length--;

		//判断链表是否为空
		if (last != NULL)
		{
			tList->node.pNext = ret->pNext;
			last->pNext = ret->pNext;
		}

		//若删除的元素为游标所指的元素
		if (tList->slider == ret)
		{
			tList->slider = ret->pNext;
		}

		//若删除元素后，链表长度为0
		if (tList->Length == 0)
		{
			tList->node.pNext = NULL;
			tList->slider = NULL;
		}
	}
	return ret;
}

//add  游标 的定义函数

CircleListNode *CircleList_DeleteNode(CircleList *list, CircleListNode *node)
{
	TCircleList* tList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (tList != NULL)
	{
		CircleListNode* current = (CircleListNode*)tList;

		//查找node在循环链表中的位置i
		for (i = 0; i < tList->Length; i++)
		{
			if (current->pNext == node)
			{
				ret = current->pNext;
				break;
			}

			current = current->pNext;
		}

		//如果ret找到，根据i去删除	
		if (ret != NULL)
		{
			CircleList_Delete(tList, i);
		}
	}

	return ret;
}

CircleListNode *CircleList_Reset(CircleList *list)
{
	TCircleList* tList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (tList != NULL)
	{
		tList->slider = tList->node.pNext;
		ret = tList->slider;
	}

	return ret;
}

CircleListNode *CircleList_Current(CircleList *list)
{
	TCircleList* tList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (tList != NULL)
	{
		ret = tList->slider;
	}

	return ret;
}

CircleListNode *CircleList_Next(CircleList *list)
{
	TCircleList* tList = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ((tList != NULL) && (tList->slider != NULL))
	{
		ret = tList->slider;
		tList->slider = ret->pNext;
	}

	return ret;
}

void CircleList_Destroy(CircleList* list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
}

void CircleList_Clear(CircleList* list)
{
	TCircleList* tList = (TCircleList*)list;
	if (tList == NULL)
	{
		return;
	}
	tList->Length = 0;
	tList->node.pNext = NULL;
	tList->slider = NULL;
}