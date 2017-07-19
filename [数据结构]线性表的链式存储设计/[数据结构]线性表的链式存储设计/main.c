#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

typedef struct Teacher 
{
	TLinkListNode node;
	int age;
}Teacher;

int main(int argc, char *argv[])
{
	int ret = 0;
	LinkList *tlinklist = Linklist_Create();
	if (NULL == tlinklist)
	{
		return ret;
	}
	Teacher t1, t2, t3, t4, t5;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	t4.age = 44;
	t5.age = 55;

	LinkList_Insert(tlinklist, (TLinkListNode *)&t1, 0);
	LinkList_Insert(tlinklist, (TLinkListNode *)&t2, 0);
	LinkList_Insert(tlinklist, (TLinkListNode *)&t3, 0);
	LinkList_Insert(tlinklist, (TLinkListNode *)&t4, 0);
	LinkList_Insert(tlinklist, (TLinkListNode *)&t5, 0);

	for (int i = 0; i < LinkList_Length(tlinklist); i++)
	{
		Teacher *tmp = (Teacher *) LinkList_Get(tlinklist, i);
		if (NULL == tmp)
		{
			ret = -1;
			printf("func main() err line:%d, file:%s\n", __LINE__, __FILE__);
			goto End;
		}
		printf("tmp.age:%d\t", tmp->age);
	}

	LinkList_Delete(tlinklist, 3);
	for (int i = 0; i < LinkList_Length(tlinklist); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(tlinklist, i);
		if (NULL == tmp)
		{
			ret = -1;
			printf("func main() err line:%d, file:%s\n", __LINE__, __FILE__);
			goto End;
		}
		printf("tmp.age:%d\t", tmp->age);
	}
End:
	LinkList_Destroy(tlinklist);
	system("pause");
	return ret;
}