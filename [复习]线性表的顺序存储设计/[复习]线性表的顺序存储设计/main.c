#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

typedef struct Teacher 
{
	int age;
}Teacher;

int main(int argc, char *argv[])
{
	int ret = 0;
	SeqList *list = NULL;
	list = SeqList_Create(10);
	if (NULL == list)
	{
		printf("func SeqList_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	Teacher t1, t2, t3, t4, t5;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;

	ret = SeqList_Insert(list, (SeqListNode *)&t1, 0);
	if (0 != ret)
	{
		printf("func SeqList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = SeqList_Insert(list, (SeqListNode *)&t2, 0);
	if (0 != ret)
	{
		printf("func SeqList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = SeqList_Insert(list, (SeqListNode *)&t3, 0);
	if (0 != ret)
	{
		printf("func SeqList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = SeqList_Insert(list, (SeqListNode *)&t4, 0);
	if (0 != ret)
	{
		printf("func SeqList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = SeqList_Insert(list, (SeqListNode *)&t5, 0);
	if (0 != ret)
	{
		printf("func SeqList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}

	printf("length:%d\n", SeqList_Length(list));
	printf("Capacity:%d\n", SeqList_Capacity(list));

	Teacher *tmp = (Teacher *)SeqList_Get(list, 4);
	if (NULL == tmp)
	{
		printf("func SeqList_Get() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	printf("tmp:%d\n", tmp->age);
	while (SeqList_Length(list) > 0)
	{
		tmp = (Teacher *)SeqList_Delete(list, 0);
		if (NULL == tmp)
		{
			printf("func SeqList_Delete() err line:%d, file:%s\n", __LINE__, __FILE__);
			goto End;
		}
		printf("Delete:%d\t", tmp->age);
	}
	puts("");


//	SeqList_Clear(list);

	/*
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
	*/
End:
	SeqList_Destroy(list);
	system("pause");
	return ret;
}