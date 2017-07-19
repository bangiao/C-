#pragma once

typedef void LinkStack;
typedef void LinkStackNode;

LinkStack *LinkStack_Create();

void LinkStack_Destroy(LinkStack *stack);

void LinkStack_Clear(LinkStack *stack);

int LinkStack_Push(LinkStack *stack, void *item);

LinkStackNode *LinkStack_Pop(LinkStack *stack);

LinkStackNode *LinkStack_Top(LinkStack *stack);

int LinkStack_Size(LinkStack *stack);