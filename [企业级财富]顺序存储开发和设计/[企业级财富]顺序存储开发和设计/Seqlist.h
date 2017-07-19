#pragma once

typedef void SeqList;		//���Ա�
typedef void SeqListDate;	//�ϲ����ݴ����������

//�������Ա�Ĵ�С
SeqList *SeqList_Create(int capacity);
//����
void SeqList_Destory(SeqList *list);
//���������
void SeqList_Clear(SeqList *list);
//��ȡ���Ա���
int SeqList_Length(SeqList *list);
//��ȡ����
int SeqList_Capacity(SeqList *list);
//�������Ա�����
int SeqList_Insert(SeqList *list, SeqListDate *node, int pos);
//��ȡ��pos�����Ա��ֵ
SeqListDate *SeqList_Get(SeqList *list, int pos);
//ɾ����pos�����Ա�����
SeqListDate *SeqList_Delete(SeqList *list, int pos);