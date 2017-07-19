#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"
#include <string.h>

//上层应用的数据结构
typedef struct _Teacher
{
	char name[64];
	int age;
}Teacher;

int main()
{
	int capacity = 10;
	Teacher t1, t2, t3;
	int ret = 0, i = 0;
	SeqList *list = NULL;

	list = SeqList_Create(capacity);
	if (NULL == list)
	{
		ret = -1;
	}
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	ret = SeqList_Insert(list, (SeqListDate *)&t1, 0);
	ret = SeqList_Insert(list, (SeqListDate *)&t2, 0);
	ret = SeqList_Insert(list, (SeqListDate *)&t3, 0);

	for (i = 0; i < SeqList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)SeqList_Get(list, i);
		printf("%d\n", tmp->age);
	}

	SeqList_Destory(list);

	system("pause");
	return 0;
}