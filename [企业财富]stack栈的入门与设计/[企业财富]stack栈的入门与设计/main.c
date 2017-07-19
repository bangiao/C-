#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SeqStack.h"


int main()
{
	vSeqStack *pStack = NULL;
	int ret = 0;
	int i = 0;
	int tmp = 0;
	int a[10] = { 0 };

	pStack = SeqStack_Create(10);
	for (i = 0; i < 10; i++)
	{
		a[i] = i + 1;
		ret = SeqStack_Push(pStack, (void *)(a + i));
	}
	tmp = *((int *)(SeqStack_Top(pStack)));
	printf("tmp: %d\n", tmp);
	printf("len:%d\n", SeqStack_Size(pStack));
	printf("capacity: %d\n", SeqStack_Capacity(pStack));

	while (SeqStack_Size(pStack) > 0)
	{
		tmp = *((int *)(SeqStack_Pop(pStack)));
		printf("%d\n", tmp);
	}

	//SeqStack_Clear(pStack);
	SeqStack_Destory(pStack);
	system("pause");
	return 0;
}