#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTNode
{
	int nData;
	struct BiTNode *lchild, *rchild;
}BiTNode;

//ÖÐÐò±éÀú
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

int Depth(BiTNode *Tree)
{
	int depthleft = 0;
	int depthright = 0;
	int deptval = 0;
	if (NULL == Tree)
	{
		deptval = 0;
		return deptval;
	}

	depthleft = Depth(Tree->lchild);

	depthright = Depth(Tree->rchild);

	deptval = 1 + (depthleft > depthright ? depthleft : depthright);
	return deptval;
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

	int num = Depth(&t1);
	printf("num:%d\n", num);

	modOrder(&t1);
	puts("");
	system("pause");
	return ret;
}