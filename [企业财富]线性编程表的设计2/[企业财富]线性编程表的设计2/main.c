#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seqlist.h"

typedef struct _Teacher 
{
	LinkListNode *node;
	char name[32];
	int age;
}Teacher;

int main()
{
	LinkList *list = NULL;
	Teacher t1, t2, t3;
	int ret = 0, i = 0;

	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	list = LinkList_Create();			//��������ͷ

	ret = LinkList_Length(list);

	ret = LinkList_Insert(list, (LinkListNode *)&t1, 0);	//���ｫ����ĵ�ַ(��ͬ������ĵ�ַ)ǿתΪ����ĵ�ַ
	ret = LinkList_Insert(list, (LinkListNode *)&t2, 0);
	ret = LinkList_Insert(list, (LinkListNode *)&t3, 0);

	for (i = 0; i < LinkList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);		//���ﷵ������ĵ�ַȻ��ǿ��ת��Ϊ�ṹ��
		printf("%d\n", tmp->age);
	}

	LinkList_Destroy(list);

// 	LinkList_Clear(list);
// 	LinkListNode* LinkList_Delete(LinkList* list, int pos);
	system("pause");
	return 0;
}