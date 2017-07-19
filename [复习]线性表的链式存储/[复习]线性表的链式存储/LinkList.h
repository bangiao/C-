#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;
typedef struct _tag_LinkListNode
{
	struct _tag_LinkListNode *next;
}TLinkListNode;

LinkList *LinkList_Create();

void LinkList_Destroy(LinkList *list);

void LinkList_Clear(LinkList *list);

int LinkList_Length(LinkList *list);

TLinkListNode *LinkList_Get(LinkList *list, int pos);

TLinkListNode *LinkList_Delete(LinkList *list, int pos);

int LinkList_Insert(LinkList *list, TLinkListNode *Node, int pos);

#endif