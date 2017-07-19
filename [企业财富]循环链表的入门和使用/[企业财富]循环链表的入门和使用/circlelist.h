#pragma once 

typedef void CircleList;

typedef struct _tag_linklist
{
	struct _tag_linklist *pNext;
}CircleListNode;

CircleList* LinkList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

//add  游标 的定义函数

CircleListNode *CircleList_DeleteNode(CircleList *list, CircleListNode *node);

CircleListNode *CircleList_Reset(CircleList *list);

CircleListNode *CircleList_Current(CircleList *list);

CircleListNode *CircleList_Next(CircleList *list);