#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

//线性表的线性存储

typedef struct _tag_SeqList 
{
	int Length;
	int Capacity;
	unsigned int *pNode;
}TSeqList;

SeqList *List_Create(int Capacity)
{
	if (0 == Capacity)
	{
		printf("func List_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (NULL == tmp)
	{
		printf("func List_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->pNode = (unsigned int *)malloc(sizeof(unsigned int) * Capacity);
	if (NULL == tmp->pNode)
	{
		printf("func List_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	memset(tmp->pNode, 0, sizeof(unsigned int) * Capacity);
	tmp->Capacity = Capacity;
	tmp->Length = 0;
	return tmp;
}

int List_Destory(SeqList **list)
{
	if (NULL == list)
	{
		printf("func List_Destory() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	TSeqList *tmp = (TSeqList *)*list;
	if (NULL != tmp->pNode)
	{
		free(tmp->pNode);
		((TSeqList*)(*list))->pNode = NULL;
	}
	tmp->Length = 0;
	tmp->Capacity = 0;
	free(tmp);
	((TSeqList*)(*list)) = NULL;
	return 0;
}

int List_Clear(SeqList *list)
{
	if (NULL == list)
	{
		printf("func List_Clear() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	TSeqList *tmp = (TSeqList *)list;
	tmp->Length = 0;
	return 0;
}


int List_Length(SeqList *list)
{
	if (NULL == list)
	{
		printf("func List_Length() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	TSeqList *tmp = (TSeqList *)list;

	return tmp->Length;
}


int List_Capacity(SeqList *list)
{
	if (NULL == list)
	{
		printf("func List_Capacity() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	TSeqList *tmp = (TSeqList *)list;
	return tmp->Capacity;
}


int List_Insert(SeqList *list, SeqListNode *DataNode, int pos)
{
	int i = 0;
	if (NULL == list || NULL == DataNode || pos < 0)
	{
		printf("func List_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	TSeqList *tmp = (TSeqList *)list;
	if (tmp->Length >= tmp->Capacity)
	{
		printf("func List_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -2;
	}
	if (pos > tmp->Length)
	{
		pos = tmp->Length;
	}
	//将所有末尾的最大长度拿过来 一个一个的往后移一格知道 i = pos
	for (i = tmp->Length; i > pos; i--)
	{
		tmp->pNode[i] = tmp->pNode[i - 1];
	}
	tmp->pNode[pos] = (unsigned int)DataNode;
	tmp->Length++;
	return 0;
}


SeqListNode *List_Get(SeqList *list, int pos)
{
	if (NULL == list || pos < 0)
	{
		printf("func List_Get() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	TSeqList *tmp = (TSeqList *)list;

	return (SeqListNode *)tmp->pNode[pos];
}

//这里存在一个小问题  关于 ret 变量
SeqListNode * List_Delete(SeqList *list, int pos)
{
	int i = 0;
	SeqListNode *ret = 0;
	if (NULL == list || pos < 0)
	{
		printf("func List_Delete() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	TSeqList *tmp = (TSeqList *)list;
	ret = (SeqListNode *)tmp->pNode[pos];
	for (i = pos + 1; i < tmp->Length; i++)
	{
		tmp->pNode[i - 1] = tmp->pNode[i];
	}
	tmp->Length--;
	return ret;
}
