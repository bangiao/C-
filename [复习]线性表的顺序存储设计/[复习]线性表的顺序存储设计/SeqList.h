#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

//�������Ա�
SeqList *SeqList_Create(int Capacity);
//�������Ա�
void SeqList_Destroy(SeqList *list);
//�ָ������Ա���
void SeqList_Clear(SeqList *list);
//���Ա�ĳ���
int SeqList_Length(SeqList *list);
//���Ա������
int SeqList_Capacity(SeqList *list);
//��ȡָ��λ�õ�����
SeqListNode *SeqList_Get(SeqList *list, int pos);
//ɾ��ָ��λ�õ����� �������������
SeqListNode *SeqList_Delete(SeqList *list, int pos);
//�������ݽڵ�
int SeqList_Insert(SeqList *list, SeqListNode *NodeData, int pos);

#endif