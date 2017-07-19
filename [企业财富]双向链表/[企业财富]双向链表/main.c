#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublelist.h"

typedef struct _Teacher 
{
	DoubleListnode node;
	int age;
}Teacher;

int main()
{
	int ret = 0, i = 0;
	vDoubleList* list = DoubleList_Create();
	Teacher t1, t2, t3, t4, t5;
	Teacher *tmp = NULL;
	t1.age = 1, t2.age = 2, t3.age = 3, t4.age = 4, t5.age = 5;
	ret = DoubleList_Insert(list, (DoubleListnode*)&t1, DoubleList_Length(list));
	ret = DoubleList_Insert(list, (DoubleListnode*)&t2, DoubleList_Length(list));
	ret = DoubleList_Insert(list, (DoubleListnode*)&t3, DoubleList_Length(list));
	ret = DoubleList_Insert(list, (DoubleListnode*)&t4, DoubleList_Length(list));
	ret = DoubleList_Insert(list, (DoubleListnode*)&t5, DoubleList_Length(list));

	for (i = 0; i < DoubleList_Length(list); i++)
	{
		tmp = (Teacher *)DoubleList_Get(list, i);
		printf("DoubleList_Get tmp->age = %d\n", tmp->age);
	}
	puts("");

	DoubleList_Delete(list, DoubleList_Length(list) - 1);
	DoubleList_Delete(list, 0);
	for (i = 0; i < DoubleList_Length(list); i++)
	{
		tmp = (Teacher *)DoubleList_Get(list, i);
		printf("DoubleList_Delete ºó tmp->age = %d\n", tmp->age);
	}
	puts("");

	DoubleList_Reset(list);
	DoubleList_Next(list);
	tmp = (Teacher *)DoubleList_Current(list);
	printf("DoubleList_Current tmp->age = %d\n", tmp->age);
	DoubleList_DeleteNode(list, (DoubleListnode *)tmp);
	tmp = (Teacher *)DoubleList_Current(list);
	printf("DoubleList_DeleteNode tmp->age = %d\n", tmp->age);
	printf("DoubleList_Length = %d\n", DoubleList_Length(list));
	DoubleList_Destroy(list);
	system("pause");
	return 0;
}
