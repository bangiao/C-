#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  BiTNode
{
	int data;
	struct  BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//创建一个树
BiTNode *Create_Tree()
{
	BiTNode *tmp = NULL;
	char ch;
	//输入 1##之类的井号法
	//得到第一个字符其余在输入缓冲空间中
	scanf("%c", &ch);
	//判断是不是 # 号 井号则表示为空 NULL
	if (ch == '#')
	{
		return NULL;
	}
	//否则表示有数据
	else
	{
		//创建一个节点 用于存放 ch 中的数据
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (NULL == tmp)
		{
			return NULL;
		}
		//将左右子孩子的节点设置为NULL
		memset(tmp, 0, sizeof(BiTNode));
		//将这个 ch 数据放入 节点数据域
		tmp->data = ch - '0';
		//继续先创建左节点 遇到 # 直接放回结束获取左孩子
		tmp->lchild = Create_Tree();
		//继续创建右孩子节点 遇到 # 结束
		tmp->rchild = Create_Tree();
	}
	//这是一个先序节点创建
	return tmp;
}

//创建树的时候用先序创建  销毁树的时候用后序

void FreeTree(BiTNode *root)
{
	if (NULL == root)
	{
		return;

	}
	if (NULL != root->lchild)
	{
		FreeTree(root->lchild);
	}
	if (NULL != root->rchild)
	{
		FreeTree(root->rchild);
	}
	if (NULL != root)
	{
		free(root);
		root = NULL;
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	BiTNode *tmp = NULL;

	tmp = Create_Tree();
	FreeTree(tmp);
	system("pause");
	return ret;
}