#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTNode 
{
	int nData;
	struct BiTNode *lchild, *rchild;
}BiTNode;

//先序遍历
void preOrder(BiTNode *root)
{
	if (NULL == root)
	{
		return;
	}
	printf("%d\t", root->nData);
	preOrder(root->lchild);
	preOrder(root->rchild);
}
//中序遍历
void modOrder(BiTNode *root)
{
	if (NULL == root)
	{
		return;
	}
	modOrder(root->lchild);
	printf("%d\t", root->nData);
	modOrder(root->rchild);
}

void nextOrder(BiTNode *root)
{
	if (NULL == root)
	{
		return;
	}
	nextOrder(root->lchild);
	nextOrder(root->rchild);
	printf("%d\t", root->nData);
}

//用到全局变量很不爽
int sum;
void countLeaf(BiTNode *Tree)
{
	if (NULL == Tree)
	{
		return;
	}
	if (NULL == Tree->lchild && NULL == Tree->rchild)
	{
		sum++;
	}
	if (Tree->lchild)
	{
		countLeaf(Tree->lchild);
	}
	if (Tree->rchild)
	{
		countLeaf(Tree->rchild);
	}
}

void countLeaf1(BiTNode *Tree, int *sum)
{
	if (NULL == Tree)
	{
		return;
	}
	if (NULL == Tree->lchild && NULL == Tree->rchild)
	{
		(*sum)++;
	}
	if (Tree->lchild)
	{
		countLeaf1(Tree->lchild, sum);
	}
	if (Tree->rchild)
	{
		countLeaf1(Tree->rchild, sum);
	}
}

//递归可以这样理解

void countLeaf2(BiTNode *Tree, int *sum)
{
	if (NULL == Tree)
	{
		return;
	}
	if (NULL == Tree->lchild && NULL == Tree->rchild)
	{
		(*sum)++;
	}
	if (Tree->lchild)
	{
		countLeaf3(Tree->lchild, sum);
	}
	if (Tree->rchild)
	{
		countLeaf3(Tree->rchild, sum);
	}
}

void countLeaf3(BiTNode *Tree, int *sum)
{
	if (NULL == Tree)
	{
		return;
	}
	if (NULL == Tree->lchild && NULL == Tree->rchild)
	{
		(*sum)++;
	}
	if (Tree->lchild)
	{
		countLeaf2(Tree->lchild, sum);
	}
	if (Tree->rchild)
	{
		countLeaf2(Tree->rchild, sum);
	}
}

//这样同样可以 printf出sum
void countLeaf4(BiTNode *Tree, int *sum)
{
	if (NULL == Tree)
	{
		return;
	}
	if (Tree->lchild)
	{
		countLeaf4(Tree->lchild, sum);
	}
	if (Tree->rchild)
	{
		countLeaf4(Tree->rchild, sum);
	}
	if (NULL == Tree->lchild && NULL == Tree->rchild)
	{
		(*sum)++;
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	BiTNode t1, t2, t3, t4, t5;

	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));


	t1.nData = 1;
	t2.nData = 2;
	t3.nData = 3;
	t4.nData = 4;
	t5.nData = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	sum = 0;

	countLeaf(&t1);

	printf("sum:%d\n", sum);

	{
		int mysum = 0;
		countLeaf1(&t1, &mysum);
		printf("mysum:%d\n", mysum);
	}

	{
		int mysum4 = 0;
		countLeaf4(&t1, &mysum4);
		printf("mysum:%d\n", mysum4);
	}
	/*
	preOrder(&t1);
	puts("");

	modOrder(&t1);
	puts("");

	nextOrder(&t1);
	puts("");
	*/
	system("pause");
	return ret;
}