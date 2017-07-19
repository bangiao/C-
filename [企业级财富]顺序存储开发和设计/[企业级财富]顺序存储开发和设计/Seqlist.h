#pragma once

typedef void SeqList;		//线性表
typedef void SeqListDate;	//上层数据存放数据类型

//定义线性表的大小
SeqList *SeqList_Create(int capacity);
//销毁
void SeqList_Destory(SeqList *list);
//清楚链表长度
void SeqList_Clear(SeqList *list);
//获取线性表长度
int SeqList_Length(SeqList *list);
//获取数量
int SeqList_Capacity(SeqList *list);
//插入线性表数据
int SeqList_Insert(SeqList *list, SeqListDate *node, int pos);
//获取第pos个线性表的值
SeqListDate *SeqList_Get(SeqList *list, int pos);
//删除第pos个线性表数据
SeqListDate *SeqList_Delete(SeqList *list, int pos);