#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
	TLinkListNode node;//linux 链表
	int Length;//线性表的长度
}TLinkList;

LinkList *Linklist_Create()
{
	TLinkList *pHead = NULL;
	pHead = (TLinkList *)malloc(sizeof(TLinkList));
	if (NULL == pHead)
	{
		printf("func Linklist_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	memset(pHead, 0, sizeof(TLinkList));
	pHead->Length = 0;	//有了 memset 这下面两句就成了 废话
	pHead->node.pNext = NULL;
	return pHead;
}

int PrintV(LinkList *list)
{
	TLinkList *tlist = list;
	printf("%d\n", tlist->Length);
	printf("%p\n", tlist->node.pNext);
	return 0;
}

//销毁头结点
void LinkList_Destroy(LinkList *list)
{
	if (NULL == list)
	{
		printf("func LinkList_Destroy() err line:%d, file:%s\n", __LINE__, __FILE__);
		return;
	}
	free(list);
	list = NULL;
	return ;
}
//让链表恢复到初始化状态
void LinkList_Clear(LinkList *list)
{
	if (NULL == list)
	{
		printf("func LinkList_Clear() err line:%d, file:%s\n", __LINE__, __FILE__);
		return;
	}
	TLinkList *tlist = list;
	tlist->Length = 0;
	tlist->node.pNext = NULL;
	return ;
}

int LinkList_Length(LinkList *list)
{
	if (NULL == list)
	{
		printf("func LinkList_Length() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	TLinkList *tlist = list;//转到线性表中的linux链表

	return tlist->Length;//线性表的数据中有数据
}

int LinkList_Insert(LinkList *list, TLinkListNode *node, int pos)
{
	TLinkListNode *pCur = NULL;
	TLinkListNode *pNext = NULL;
	if (NULL == list || NULL == node || pos < 0)
	{
		printf("func LinkList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	pCur = (TLinkListNode *)list;
	int i = 0;
	for (i = 0; i < pos && pCur->pNext != NULL; i++)
	{
		pCur = pCur->pNext;//循环得到新节点
	}
	node->pNext = pCur->pNext;//新节点的下一个节点指向第三个节点的位置
	pCur->pNext = node;//当前节点的下一个位置 指向 node 新节点
	((TLinkList *)list)->Length++;//线性表中的长度加 1 
	return 0;
}

TLinkListNode* LinkList_Get(LinkList *list, int pos)
{
	TLinkListNode *pCur = NULL;
	if (NULL == list || pos < 0)
	{
		printf("func LinkList_Get() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	pCur = (TLinkListNode *)list;
	int i = 0;
	for (i = 0; i < pos && pCur->pNext != NULL; i++)
	{
		pCur = pCur->pNext;	//得到当前节点的前一个节点
	}
	return pCur->pNext;		//得到当前节点
}

//两个指针删除当前节点, 有图
TLinkListNode* LinkList_Delete(LinkList *list, int pos)
{
	TLinkListNode *pCur = NULL;
	TLinkListNode *pNext = NULL;
	if (NULL == list || pos < 0)
	{
		printf("func LinkList_Delete() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	pCur = (TLinkListNode *)list;
	int i = 0;
	for (i = 0; i < pos && pCur->pNext != NULL; i++)
	{
		pCur = pCur->pNext;//这个获取的是当前节点的上一个节点(因为头结点不计入链表的缘故)
	}
	//这里得到当前节点
	pNext = pCur->pNext;
	//前一个节点的next = 当前节点的next  这里当前节点和当前的前一个节点指向同一个(当前节点的next)节点
	pCur->pNext = pNext->pNext;
	//节点的总长度减一
	((TLinkList *)list)->Length--;
	//返回当前节点
	return pNext;
}