#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  BiTNode
{
	int data;
	struct  BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//����һ����
BiTNode *Create_Tree()
{
	BiTNode *tmp = NULL;
	char ch;
	//���� 1##֮��ľ��ŷ�
	//�õ���һ���ַ����������뻺��ռ���
	scanf("%c", &ch);
	//�ж��ǲ��� # �� �������ʾΪ�� NULL
	if (ch == '#')
	{
		return NULL;
	}
	//�����ʾ������
	else
	{
		//����һ���ڵ� ���ڴ�� ch �е�����
		tmp = (BiTNode *)malloc(sizeof(BiTNode));
		if (NULL == tmp)
		{
			return NULL;
		}
		//�������Ӻ��ӵĽڵ�����ΪNULL
		memset(tmp, 0, sizeof(BiTNode));
		//����� ch ���ݷ��� �ڵ�������
		tmp->data = ch - '0';
		//�����ȴ�����ڵ� ���� # ֱ�ӷŻؽ�����ȡ����
		tmp->lchild = Create_Tree();
		//���������Һ��ӽڵ� ���� # ����
		tmp->rchild = Create_Tree();
	}
	//����һ������ڵ㴴��
	return tmp;
}

//��������ʱ�������򴴽�  ��������ʱ���ú���

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