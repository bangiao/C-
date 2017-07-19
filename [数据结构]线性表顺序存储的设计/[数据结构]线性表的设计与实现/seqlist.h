#pragma once

typedef void SeqList;
typedef void SeqListNode;

//创建链表
SeqList *List_Create(int Capacity);

//销毁链表
int List_Destory(SeqList **list);

//清除链表
int List_Clear(SeqList *list);

//链表的长度
int List_Length(SeqList *list);

//链表的总数量
int List_Capacity(SeqList *list);

//链表的插入
int List_Insert(SeqList *list, SeqListNode *DataNode, int pos);

//链表的读取
SeqListNode *List_Get(SeqList *list, int pos);

//链表的删除
SeqListNode* List_Delete(SeqList *list, int pos);
