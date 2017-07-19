#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"
#include <string.h>

//下层应用需要定义数据结构接收上层应用的数据
typedef struct _tag_SeqList
{
	//定义数据用来存放
	unsigned int *Node;		//这里需要注意 这里在核心代码中存放的是地址 所以可以是 unsigned int 类型
	//定义长度
	int Length;
	//定义数量
	int capacity;
}TSeqList;

SeqList *SeqList_Create(int capacity)
{
	TSeqList *list = NULL;		//这里之所以定义为结构体是因为返回值为void不影响数据的封装可以直接用
	list = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(unsigned int) * capacity);
	if (NULL == list)
	{
		return NULL;
	}
	list->capacity = 0;
	list->Length = 0;
	list->Node = (unsigned int *)(list + 1);
	return list;
}

void SeqList_Destory(SeqList *list)
{
	if (NULL == list)
	{
		return;
	}
	free(list);
	return ;
}

void SeqList_Clear(SeqList *list)
{
	TSeqList *t_list = (TSeqList *)list;
	if (NULL == t_list)
	{
		return;
	}
	t_list->Length = 0;
	return ;
}

int SeqList_Length(SeqList *list)
{
	TSeqList *t_list = (TSeqList *)list;
	if (NULL == t_list)
	{
		return -1;
	}
	return t_list->Length;
}

int SeqList_Capacity(SeqList *list)
{
	TSeqList *t_list = (TSeqList *)list;
	if (NULL == t_list)
	{
		return -1;
	}
	return t_list->capacity;
}

int SeqList_Insert(SeqList *list, SeqListDate *node, int pos)
{
	TSeqList *t_list = (TSeqList *)list;
	if (list == NULL || node == NULL)
	{
		return -1;
	}

	if (pos < 0 || pos > t_list->capacity)
	{
		return -2;
	}

	//判断是否已经man
// 	if (t_list->Length >= t_list->capacity)
// 	{
// 		return -3;
// 	}

	//容错
	if (pos > t_list->Length)
	{
		pos = t_list->Length;
	}
	
	for (int i = t_list->Length; i > pos; i--)		//核心代码	前端插入法
	{
		t_list->Node[i] = t_list->Node[i - 1];
	}
	t_list->Node[pos] = (unsigned int)node;
	++t_list->Length;
	return 0;
}

SeqListDate *SeqList_Get(SeqList *list, int pos)
{
	TSeqList *t_list = (TSeqList *)list;
	if (NULL == t_list || pos < 0 || pos > t_list->Length)
	{
		return NULL;
	}
	return (SeqListDate*)t_list->Node[pos];
}

SeqListDate *SeqList_Delete(SeqList *list, int pos)
{
	int i = 0;
	TSeqList *t_list = (TSeqList *)list;
	void* ret = NULL;
	if (list == NULL || pos < 0 || pos > t_list->Length)
	{
		return NULL;
	}
	//缓存要删除的结点
	ret = (void*)t_list->Node[pos];
	//对链表进行移动
	for (i = pos + 1; i < t_list->Length; i++)
	{
		t_list->Node[i - 1] = t_list->Node[i];
	}
	t_list->Length--;
	return ret;
}
