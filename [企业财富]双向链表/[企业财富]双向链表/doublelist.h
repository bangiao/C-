#pragma once 
//doublelist.h
typedef void vDoubleList;

typedef struct _linux_list 
{
	struct _linux_list *pPre;
	struct _linux_list *pNext;
}DoubleListnode;

vDoubleList* DoubleList_Create();

void DoubleList_Destroy(vDoubleList* list);

void DoubleList_Clear(vDoubleList* list);

int DoubleList_Length(vDoubleList* list);

int DoubleList_Insert(vDoubleList* list, DoubleListnode* node, int pos);

DoubleListnode* DoubleList_Get(vDoubleList* list, int pos);

DoubleListnode* DoubleList_Delete(vDoubleList* list, int pos);


//add

DoubleListnode* DoubleList_DeleteNode(vDoubleList* list, DoubleListnode* node);

DoubleListnode *DoubleList_Pre(list);

DoubleListnode* DoubleList_Reset(vDoubleList* list);

DoubleListnode* DoubleList_Current(vDoubleList* list);

DoubleListnode* DoubleList_Next(vDoubleList* list);