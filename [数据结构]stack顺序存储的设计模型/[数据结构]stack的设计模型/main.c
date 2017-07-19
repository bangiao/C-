#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[])
{
	int ret = 0;
	int i = 0;
	int a[10];
	
	SeqStack *stack = NULL;
	stack = SeqStack_Create(10);
	if (NULL == stack)
	{
		printf("func SeqStack_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}
	for (i = 0; i < 1; i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack, a + i);
	}
	printf("Capacity: %d\n", SeqStack_Capacity(stack));
	printf("Size:%d\n", SeqStack_Size(stack));
	printf("Front:%d\n", *((int *)(SeqStack_Front(stack))));

	while (SeqStack_Size(stack) > 0)
	{
		int num = *((int *)SeqStack_Pop(stack));
		printf("num:%d\t", num);
	}
	puts("");
End:
	SeqSatck_Destroy(stack);
	system("pause");
	return ret;
}