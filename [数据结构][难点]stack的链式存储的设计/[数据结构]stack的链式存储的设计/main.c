#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"
#include "linklist.h"

int main(int argc, char *argv[])
{
	int ret = 0;
	int i = 0;
	LinkStack *Stack = NULL;

	int a[10] = { 0 };


	Stack = LinkStack_Create();
	if (NULL == Stack)
	{
		goto End;
	}

	for (i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		ret = LinkStack_Push(Stack, a + i);
		if (0 != ret)
		{
			goto End;
		}
	}
	printf("Top:%d\n", *((int *)LinkStack_Top(Stack)));
	printf("Size:%d\n", LinkStack_Size(Stack));

	while (LinkStack_Size(Stack) > 0)
	{
		int num = *((int  *)LinkStack_Pop(Stack));
		printf("num:%d\t", num);
	}
	puts("");
End:
	LinkStack_Destroy(Stack);
	system("pause");
	return ret;
}