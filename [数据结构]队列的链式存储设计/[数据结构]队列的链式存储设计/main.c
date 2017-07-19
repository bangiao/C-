#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"
#include "linklist.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int ret = 0;
	int a[5] = { 0 };
	
	LinkQueue *queue = NULL;
	queue = LinkQueue_Create();
	if (NULL == queue)
	{
		printf("func LinkQueue_Create() err line:%d, file:%s\n", __LINE__, __FILE__);
		goto End;
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkQueue_Push(queue, (void *)(a + i));
	}

	printf("len:%d\n", LinkQueue_Length(queue));

	int *num = (int *)LinkQueue_Front(queue);
	printf("num_front:%d\n", *num);

	for (i = 0; i < 5; i++)
	{
		int flag = *((int *)LinkQueue_Pop(queue));
		printf("flag:%d\t", flag);
	}
	puts("");
End:
	LinkQueue_Destroy(queue);
	system("pause");
	return ret;
}