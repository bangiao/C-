#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SeqStack.h"

typedef struct _tag_SeqStack 
{
	unsigned int *Date;
	int Length;
	int capacity;
}TSeqStack;

vSeqStack *SeqStack_Create(int capacity)
{
	TSeqStack *Stack = (TSeqStack *)malloc(sizeof(TSeqStack) + sizeof(unsigned int) * capacity);
	if (NULL == Stack)
	{
		return NULL;
	}
	Stack->Date = (unsigned int *)(Stack + 1);
	Stack->Length = 0;
	Stack->capacity = 0;
	return (vSeqStack *)Stack;
}
void SeqStack_Destory(vSeqStack *Stack)
{
	TSeqStack *tStack = (TSeqStack *)Stack;
	if (NULL == Stack)
	{
		return;
	}
	free(tStack);
	return ;
}
void SeqStack_Clear(vSeqStack *Stack)
{
	TSeqStack *tStack = (TSeqStack *)Stack;
	if (NULL == tStack)
	{
		return;
	}
	tStack->Length = 0;
}
int SeqStack_Push(vSeqStack *Stack, void *item)
{
	TSeqStack *tStack = (TSeqStack *)Stack;
	if (NULL == tStack)
	{
		return -1;
	}
	tStack->Date = (unsigned int)item;
	return 0;
}
void *SeqStack_Pop(vSeqStack *Stack)
{
	return NULL;
}
void *SeqStack_Top(vSeqStack *Stack)
{
	return NULL;
}
int SeqStack_Size(vSeqStack *Stack)
{
	return 0;
}
int SeqStack_Capacity(vSeqStack *Stack)
{
	return 0;
}