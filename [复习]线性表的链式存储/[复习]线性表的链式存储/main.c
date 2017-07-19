#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

typedef struct Teacher 
{
	TLinkListNode node;
	int age;
}Teacher;

int main(int argc, char *argv[])
{
	int ret = 0;
	LinkList *list = NULL;
	list = LinkList_Create();
	if (NULL == list)
	{
		printf("func main() LinkList_Create() if (NULL == list) err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	Teacher t1, t2, t3, t4, t5;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;

	ret = LinkList_Insert(list, (TLinkListNode *)&t1, 0);
	if (0 != ret)
	{
		printf("func main() LinkList_Insert() if (0 != ret) err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = LinkList_Insert(list, (TLinkListNode *)&t2, 0);
	if (0 != ret)
	{
		printf("func main() LinkList_Insert() if (0 != ret) err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = LinkList_Insert(list, (TLinkListNode *)&t3, 0);
	if (0 != ret)
	{
		printf("func main() LinkList_Insert() if (0 != ret) err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = LinkList_Insert(list, (TLinkListNode *)&t4, 0);
	if (0 != ret)
	{
		printf("func main() LinkList_Insert() if (0 != ret) err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	ret = LinkList_Insert(list, (TLinkListNode *)&t5, 0);
	if (0 != ret)
	{
		printf("func main() LinkList_Insert() if (0 != ret) err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	
	printf("len:%d\n", LinkList_Length(list));

	Teacher * tmp = (Teacher *)LinkList_Get(list, 0);
	if (NULL == tmp)
	{
		printf("func LinkList_Get() if (NULL == tmp) err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	printf("tmp:%d\n", tmp->age);

	while (LinkList_Length(list) > 0)
	{
		tmp = (Teacher *)LinkList_Delete(list, 0);
		if (NULL == tmp)
		{
			printf("func LinkList_Delete() if (NULL == tmp) err line:%d, file:%s\n", __LINE__, __FILE__);
			goto End;
		}
		printf("Data:%d\t", tmp->age);
	}
	puts("");
End:
	LinkList_Destroy(list);
	system("pause");
	return ret;
}