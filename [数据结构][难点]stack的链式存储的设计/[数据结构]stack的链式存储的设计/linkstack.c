#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
#include "linklist.h"

//难点
typedef struct _tag_LinkStack 
{
	TLinkListNode node;		//linux 链表
	void *item;				//数据
}TLinkStack;

LinkStack *LinkStack_Create()		//void *
{
	return Linklist_Create();		//返回  void *  创建了头结点
}

void LinkStack_Destroy(LinkStack *stack)
{
	LinkStack_Clear(stack);//将栈里的东西全部清空
	LinkList_Destroy(stack);//释放头结点
}

void LinkStack_Clear(LinkStack *stack)
{
	TLinkStack *tmp = NULL;
	if (NULL == stack)
	{
		printf("func LinkStack_Clear() err line:%d, file:%s\n", __LINE__, __FILE__);
		return;
	}
	while (LinkStack_Size(stack) > 0)
	{
		tmp = LinkStack_Pop(stack);
		if (NULL == tmp)
		{
			printf("func LinkStack_Clear() err line:%d, file:%s\n", __LINE__, __FILE__);
			return;
		}
	}
}
//栈		新的数据
int LinkStack_Push(LinkStack *stack, void *item)
{
	int ret = 0;
	TLinkStack *tmp = NULL;
	//新节点
	tmp = (TLinkStack *)malloc(sizeof(TLinkStack));
	if (NULL == tmp)
	{
		printf("func LinkStack_Push() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	//初始化新节点
	memset(tmp, 0, sizeof(TLinkStack));
	//新数据进入新节点
	tmp->item = item;
	//线性表是对 linux 节点 进行操作的 不会影响到数据
	//所以可以放心大胆的使用 线性表的代码
	ret = LinkList_Insert(stack, (TLinkListNode *)tmp, 0);
	if (0 != ret)
	{
		printf("func LinkStack_Push() err line:%d, file:%s\n", __LINE__, __FILE__);
		if (NULL != tmp)
		{
			free(tmp);//如果插入失败, 则销毁
		}
		return -2;
	}
	return 0;
}

LinkStackNode *LinkStack_Pop(LinkStack *stack)
{
	void *item = NULL;//这个是为了读取即将pop的节点的数据  用于返回
	TLinkStack *tmp = NULL;
	//得到当前节点(这个节点即将被删除释放, malloc)
	tmp = (TLinkStack *)LinkList_Delete(stack, 0);
	if (NULL == tmp)
	{
		printf("func LinkStack_Pop() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	//得到数据
	item = tmp->item;
	//删除当前节点
	if (NULL != tmp)
		free(tmp);
	//返回数据
	return item;
}

LinkStackNode *LinkStack_Top(LinkStack *stack)
{
	void *item = NULL;
	TLinkStack *tmp = NULL;
	tmp = (TLinkStack *)LinkList_Get(stack, 0);//得到当前节点
	if (NULL == tmp)
	{
		printf("func LinkStack_Top() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	item = tmp->item;//得到当前节点的数据
	return item;//返回当前节点
}

int LinkStack_Size(LinkStack *stack)
{
	return LinkList_Length(stack);//返回linux线性表的长度
}