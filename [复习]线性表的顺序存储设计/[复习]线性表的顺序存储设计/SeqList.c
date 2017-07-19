#include "SeqList.h"
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ײ�� ���ڴ洢�ϲ�Ӧ�÷������Ľڵ�
//�ײ��Ų����ϲ�Ӧ�÷���������ʲô���͵�����
//��ֻ������ô�洢�ڵ�

typedef struct _tag_SeqList 
{
	int Capacity;
	int Length;
	unsigned int *Node;		//malloc (Capacity) Capacity������ ���������ǵ�ַ
	//(int *)00401000 == > (int)00401000  ���ǵײ����ĵ�
}TSeqList;

//�������Ա�
SeqList *SeqList_Create(int Capacity)
{
	TSeqList *tlist = NULL;
	tlist = (TSeqList *)malloc(sizeof(TSeqList));
	if (NULL == tlist)
	{
		printf("func SeqList_Create() err if (NULL == tlist) line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	memset(tlist, 0, sizeof(TSeqList));
	tlist->Capacity = Capacity;
	tlist->Node = (unsigned int *)malloc(sizeof(unsigned int) * Capacity);
	if (NULL == tlist->Node)
	{
		printf("func SeqList_Create() err if (NULL == tlist->Node) line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	return tlist;
}
//�������Ա�
void SeqList_Destroy(SeqList *list)
{
	TSeqList *tlist = list;
	if (NULL == list)
	{
		printf("func SeqList_Destroy() err if (NULL == list) line:%d, file:%s\n", __LINE__, __FILE__);
		return;
	}
	tlist->Capacity = 0;
	tlist->Length = 0;
	if (NULL != tlist->Node)
	{
		free(tlist->Node);
	}
	free(tlist);
}
//�ָ������Ա���
void SeqList_Clear(SeqList *list)
{
	if (NULL == list)
	{
		printf("func SeqList_Clear() err if (NULL == list) line:%d, file:%s\n", __LINE__, __FILE__);
		return;
	}
	TSeqList *tlist = list;
	tlist->Length = 0;
}
//���Ա�ĳ���
int SeqList_Length(SeqList *list)
{
	TSeqList *tlist = (TSeqList *)list;
	if (NULL == tlist)
	{
		printf("func SeqList_Length() err if (NULL == tlist) line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	return tlist->Length;
}
//���Ա������
int SeqList_Capacity(SeqList *list)
{
	TSeqList *tlist = (TSeqList *)list;
	if (NULL == tlist)
	{
		printf("func SeqList_Capacity() err if (NULL == tlist) line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	return tlist->Capacity;
}
//��ȡָ��λ�õ�����
SeqListNode *SeqList_Get(SeqList *list, int pos)
{
	TSeqList *tlist = NULL;
	if (NULL == list || pos < 0)
	{
		printf("func SeqList_Get() err if (NULL == list || pos < 0) line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	tlist = list;
	if (pos >= tlist->Length)
	{
		printf("func SeqList_Get() err if (pos >= tlist->Length) line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	return (SeqListNode *)tlist->Node[pos];
}
//ɾ��ָ��λ�õ����� �������������
SeqListNode *SeqList_Delete(SeqList *list, int pos)
{
	TSeqList *tlist = NULL;
	SeqListNode *ret = NULL;
	int i = 0;

	if (NULL == list || pos < 0)
	{
		printf("func SeqList_Get() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	tlist = list;
	ret = (SeqListNode *)tlist->Node[pos];
	for (i = pos + 1; i < tlist->Length; i++)
	{
		tlist->Node[i - 1] = tlist->Node[i];
	}
	tlist->Length--;
	return ret;
}
//�������ݽڵ�
int SeqList_Insert(SeqList *list, SeqListNode *NodeData, int pos)
{
	TSeqList *tlist = NULL;
	int i = 0;
	if (NULL == list || NULL == NodeData || pos < 0)
	{
		printf("func SeqList_Insert() err if (NULL == list || NULL == NodeData || pos < 0) line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	tlist = list;
	if (tlist->Length >= tlist->Capacity)
	{
		printf("func SeqList_Insert() err if (tlist->Length >= tlist->Capacity) line:%d, file:%s\n", __LINE__, __FILE__);
		return -2;
	}
	if (pos > tlist->Length)
	{
		pos = tlist->Length;
	}
	for (i = tlist->Length; i > pos; i--)
	{
		tlist->Node[i] = tlist->Node[i - 1];
	}
	tlist->Node[pos] = (unsigned int)NodeData;
	tlist->Length++;
	return 0;
}