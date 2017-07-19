#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
#include "linklist.h"

//�ѵ�
typedef struct _tag_LinkStack 
{
	TLinkListNode node;		//linux ����
	void *item;				//����
}TLinkStack;

LinkStack *LinkStack_Create()		//void *
{
	return Linklist_Create();		//����  void *  ������ͷ���
}

void LinkStack_Destroy(LinkStack *stack)
{
	LinkStack_Clear(stack);//��ջ��Ķ���ȫ�����
	LinkList_Destroy(stack);//�ͷ�ͷ���
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
//ջ		�µ�����
int LinkStack_Push(LinkStack *stack, void *item)
{
	int ret = 0;
	TLinkStack *tmp = NULL;
	//�½ڵ�
	tmp = (TLinkStack *)malloc(sizeof(TLinkStack));
	if (NULL == tmp)
	{
		printf("func LinkStack_Push() err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	//��ʼ���½ڵ�
	memset(tmp, 0, sizeof(TLinkStack));
	//�����ݽ����½ڵ�
	tmp->item = item;
	//���Ա��Ƕ� linux �ڵ� ���в����� ����Ӱ�쵽����
	//���Կ��Է��Ĵ󵨵�ʹ�� ���Ա�Ĵ���
	ret = LinkList_Insert(stack, (TLinkListNode *)tmp, 0);
	if (0 != ret)
	{
		printf("func LinkStack_Push() err line:%d, file:%s\n", __LINE__, __FILE__);
		if (NULL != tmp)
		{
			free(tmp);//�������ʧ��, ������
		}
		return -2;
	}
	return 0;
}

LinkStackNode *LinkStack_Pop(LinkStack *stack)
{
	void *item = NULL;//�����Ϊ�˶�ȡ����pop�Ľڵ������  ���ڷ���
	TLinkStack *tmp = NULL;
	//�õ���ǰ�ڵ�(����ڵ㼴����ɾ���ͷ�, malloc)
	tmp = (TLinkStack *)LinkList_Delete(stack, 0);
	if (NULL == tmp)
	{
		printf("func LinkStack_Pop() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	//�õ�����
	item = tmp->item;
	//ɾ����ǰ�ڵ�
	if (NULL != tmp)
		free(tmp);
	//��������
	return item;
}

LinkStackNode *LinkStack_Top(LinkStack *stack)
{
	void *item = NULL;
	TLinkStack *tmp = NULL;
	tmp = (TLinkStack *)LinkList_Get(stack, 0);//�õ���ǰ�ڵ�
	if (NULL == tmp)
	{
		printf("func LinkStack_Top() err line:%d, file:%s\n", __LINE__, __FILE__);
		return NULL;
	}
	item = tmp->item;//�õ���ǰ�ڵ������
	return item;//���ص�ǰ�ڵ�
}

int LinkStack_Size(LinkStack *stack)
{
	return LinkList_Length(stack);//����linux���Ա�ĳ���
}