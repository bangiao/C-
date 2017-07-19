#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"
//‘º…™∑ÚŒ Ã‚
typedef struct Value 
{
	CircleListNode *node;
	int v;
}Value;

int main(int argc, char *argv[])
{
	int ret = 0;
	CircleList* list = NULL;
	int i = 0;
	list = CircleList_Create();
	if (NULL == list)
	{
		printf("func CircleList_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	Value v1; Value v2; Value v3; Value v4;
	Value v5; Value v6; Value v7; Value v8;

	v1.v = 1; v2.v = 2; v3.v = 3; v4.v = 4; 
	v5.v = 5; v6.v = 6; v7.v = 7; v8.v = 8;

	ret = CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = CircleList_Insert(list, (CircleListNode*)&v5, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = CircleList_Insert(list, (CircleListNode*)&v6, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = CircleList_Insert(list, (CircleListNode*)&v7, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = CircleList_Insert(list, (CircleListNode*)&v8, CircleList_Length(list));
	if (0 != ret)
	{
		printf("func CircleList_Insert() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}

	for (i = 0; i < CircleList_Length(list); i++)
	{
		Value *tmp = (Value *)CircleList_Get(list, i);
		if (NULL == tmp)
		{
			printf("func CircleList_Get() err line:%d, file:%s\n", __LINE__, __FILE__);
			goto End;
		}
		printf("tmp:%d\t", tmp->v);
	}
	puts("");
	Value *ptmp = NULL;
	CircleList_Reset(list);
	while (CircleList_Length(list) > 0)
	{
		for (i = 1; i < 3; i++)
		{
			CircleList_Next(list);
		}
		ptmp = (Value *)CircleList_Current(list);
		if (NULL == ptmp)
		{
			printf("func CircleList_Current() err line:%d, file:%s\n", __LINE__, __FILE__);
			goto End;
		}
		printf("ptmp:%d\n", ptmp->v);
		CircleList_DeleteNode(list, (CircleListNode *)ptmp);
	}

End:
	List_Destroy(list);
	system("pause");
	return ret;
}