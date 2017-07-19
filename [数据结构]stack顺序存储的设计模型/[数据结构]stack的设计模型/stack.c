#define  _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

SeqStack *SeqStack_Create(int Capacity)
{

	return List_Create(Capacity);
}

void SeqSatck_Destroy(SeqStack *stack)
{
	List_Destory(&stack);
	return ;
}

void SeqStack_Clear(SeqStack *stack)
{
	List_Clear(stack);
	return ;
}

int SeqStack_Push(SeqStack *stack, void *item)
{
	return List_Insert(stack, item, List_Length(stack));
}

void *SeqStack_Pop(SeqStack *stack)
{
	return List_Delete(stack, List_Length(stack) - 1);
}

void *SeqStack_Front(SeqStack *stack)
{
	return List_Get(stack, List_Length(stack) - 1);
}

int SeqStack_Size(SeqStack *stack)
{
	return List_Length(stack);
}

int SeqStack_Capacity(SeqStack *stack)
{
	return List_Capacity(stack);
}
