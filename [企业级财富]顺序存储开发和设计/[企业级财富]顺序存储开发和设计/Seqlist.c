#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"
#include <string.h>

//�²�Ӧ����Ҫ�������ݽṹ�����ϲ�Ӧ�õ�����
typedef struct _tag_SeqList
{
	//���������������
	unsigned int *Node;		//������Ҫע�� �����ں��Ĵ����д�ŵ��ǵ�ַ ���Կ����� unsigned int ����
	//���峤��
	int Length;
	//��������
	int capacity;
}TSeqList;

SeqList *SeqList_Create(int capacity)
{
	TSeqList *list = NULL;		//����֮���Զ���Ϊ�ṹ������Ϊ����ֵΪvoid��Ӱ�����ݵķ�װ����ֱ����
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

	//�ж��Ƿ��Ѿ�man
// 	if (t_list->Length >= t_list->capacity)
// 	{
// 		return -3;
// 	}

	//�ݴ�
	if (pos > t_list->Length)
	{
		pos = t_list->Length;
	}
	
	for (int i = t_list->Length; i > pos; i--)		//���Ĵ���	ǰ�˲��뷨
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
	//����Ҫɾ���Ľ��
	ret = (void*)t_list->Node[pos];
	//����������ƶ�
	for (i = pos + 1; i < t_list->Length; i++)
	{
		t_list->Node[i - 1] = t_list->Node[i];
	}
	t_list->Length--;
	return ret;
}
