#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode;

//创建线性表
SeqList *SeqList_Create(int Capacity);
//销毁线性表
void SeqList_Destroy(SeqList *list);
//恢复到线性表创建
void SeqList_Clear(SeqList *list);
//线性表的长度
int SeqList_Length(SeqList *list);
//线性表的容量
int SeqList_Capacity(SeqList *list);
//读取指定位置的内容
SeqListNode *SeqList_Get(SeqList *list, int pos);
//删除指定位置的数据 并返回这个数据
SeqListNode *SeqList_Delete(SeqList *list, int pos);
//插入数据节点
int SeqList_Insert(SeqList *list, SeqListNode *NodeData, int pos);

#endif