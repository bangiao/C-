#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinTree 
{
	int data;
	struct BinTree *lchild, *rchild;
}BinTree;

BinTree *Create()
{
	char data;
	BinTree *T = NULL;
	data = getchar();
	if ('#' == data)
	{
		return NULL;
	}
	else
	{
		T = (BinTree *)malloc(sizeof(BinTree));			//创建一个新的节点
		memset(T, 0, sizeof(BinTree));
		T->data = data;
		T->lchild = Create();
		T->rchild = Create();
	}
	return T;
}

void Destroy(BinTree * node)
{
	if (NULL == node)
	{
		return;
	}
	Destroy(node->lchild);
	Destroy(node->rchild);
	free(node);
}

void printTree(BinTree *node)
{
	if (NULL == node)
	{
		return;
	}
	else
	{
		printTree(node->lchild);
		printTree(node->rchild);
		printf("%c\t", node->data);
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	BinTree *tree = NULL;
	
	tree = Create();
	if (NULL == tree)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	printTree(tree);
	Destroy(tree);
	system("pause");
	return ret;
}