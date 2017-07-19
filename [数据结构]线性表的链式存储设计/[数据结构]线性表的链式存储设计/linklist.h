#pragma once

//���ݽṹ�ķ�װ
typedef void LinkList;

//����һ���ڵ�
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode *pNext;
}TLinkListNode;

LinkList *Linklist_Create();

void LinkList_Destroy(LinkList *list);

int PrintV(LinkList *list);

void LinkList_Clear(LinkList *list);

int LinkList_Length(LinkList *list);

int LinkList_Insert(LinkList *list, TLinkListNode *node, int pos);

TLinkListNode* LinkList_Get(LinkList *list, int pos);

TLinkListNode* LinkList_Delete(LinkList *list, int pos);