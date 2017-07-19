#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circlelist.h"

typedef struct _Teacher
{
	CircleListNode header;
	int age;
}Teacher;

int main()
{
	CircleList*list = LinkList_Create();
	int ret = 0, i = 0;
	Teacher t1, t2, t3, t4, t5, t6, t7, t8;

	t1.age = 1;
	t2.age = 2;
	t3.age = 3;
	t4.age = 4;
	t5.age = 5;
	t6.age = 6;
	t7.age = 7;
	t8.age = 8;

	ret = CircleList_Length(list);
	ret = CircleList_Insert(list, (CircleListNode*)&t1, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&t2, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&t3, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&t4, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&t5, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&t6, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&t7, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&t8, CircleList_Length(list));

	for (i = 0; i < CircleList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)CircleList_Get(list, i);
		printf("%d\n", tmp->age);
	}

// 	Teacher *tmp = (Teacher *)CircleList_Delete(list, 1);
// 
// 	for (i = 0; i < CircleList_Length(list); i++)
// 	{
// 		Teacher *tmp = (Teacher *)CircleList_Get(list, i);
// 		printf("%d\n", tmp->age);
// 	}

	printf("\n");

	CircleList_Reset(list);

	while (CircleList_Length(list) > 0)
	{
		Teacher * pv = NULL;
		for (i = 1; i < 3; i++)
		{
			CircleList_Next(list);
		}
		pv = (Teacher *)CircleList_Current(list);
		printf("%d\n", pv->age);
		CircleList_DeleteNode(list, (CircleListNode *)pv);
	}

	//	void CircleList_Clear(CircleList* list);
	CircleList_Destroy(list);
	system("pause");
	return 0;
}

/*
CircleList* LinkList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

//add  游标 的定义函数

CircleListNode *CircleList_DeleteNode(CircleList *list, CircleListNode *node);

CircleListNode *CircleList_Reset(CircleList *list);

CircleListNode *CircleList_Current(CircleList *list);

CircleListNode *CircleList_Next(CircleList *list);
*/