#pragma once

typedef void SeqStack;

SeqStack *SeqStack_Create(int Capacity);

void SeqSatck_Destroy(SeqStack *stack);

void SeqStack_Clear(SeqStack *stack);

int SeqStack_Push(SeqStack *stack, void *item);

void *SeqStack_Pop(SeqStack *stack);

void *SeqStack_Front(SeqStack *stack);

int SeqStack_Size(SeqStack *stack);

int SeqStack_Capacity(SeqStack *stack);
