#pragma once
typedef void vSeqStack;
vSeqStack *SeqStack_Create(int capacity);
void SeqStack_Destory(vSeqStack *Stack);
void SeqStack_Clear(vSeqStack *Stack);
int SeqStack_Push(vSeqStack *Stack, void *item);
void *SeqStack_Pop(vSeqStack *Stack);
void *SeqStack_Top(vSeqStack *Stack);
int SeqStack_Size(vSeqStack *Stack);
int SeqStack_Capacity(vSeqStack *Stack);