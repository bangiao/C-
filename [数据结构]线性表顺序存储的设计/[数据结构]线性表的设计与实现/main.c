#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

typedef struct Teacher 
{
	int age;
	char name[32];
}Teacher;

int main(int argc, char *argv[])
{
	int ret = 0;
	SeqList *list = List_Create(5);
	if (NULL == list)
	{
		goto End;
	}

	Teacher t1, t2, t3, t4, t5;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;

	ret = List_Insert(list, (SeqListNode *)&t1, 0);//头插法			导致先进后出有点像栈模型
	if (0 != ret)
	{
		goto End;
	}
	ret = List_Insert(list, (SeqListNode *)&t2, 0);//头插法			导致先进后出有点像栈模型
	if (0 != ret)
	{
		goto End;
	}
	ret = List_Insert(list, (SeqListNode *)&t3, 0);//头插法			导致先进后出有点像栈模型
	if (0 != ret)
	{
		goto End;
	}
	ret = List_Insert(list, (SeqListNode *)&t4, 0);//头插法			导致先进后出有点像栈模型
	if (0 != ret)
	{
		goto End;
	}
	ret = List_Insert(list, (SeqListNode *)&t5, 0);//头插法			导致先进后出有点像栈模型
	if (0 != ret)
	{
		goto End;
	}

	for (int i = 0; i < List_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)List_Get(list, i);
		if (NULL == tmp)
		{
			goto End;
		}
		printf("tmp->age = %d\t", tmp->age);
	}

End:
	List_Destory(&list);
	system("pause");
	return ret;
}
