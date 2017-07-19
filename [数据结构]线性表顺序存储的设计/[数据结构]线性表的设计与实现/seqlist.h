#pragma once

typedef void SeqList;
typedef void SeqListNode;

//��������
SeqList *List_Create(int Capacity);

//��������
int List_Destory(SeqList **list);

//�������
int List_Clear(SeqList *list);

//����ĳ���
int List_Length(SeqList *list);

//�����������
int List_Capacity(SeqList *list);

//����Ĳ���
int List_Insert(SeqList *list, SeqListNode *DataNode, int pos);

//����Ķ�ȡ
SeqListNode *List_Get(SeqList *list, int pos);

//�����ɾ��
SeqListNode* List_Delete(SeqList *list, int pos);
