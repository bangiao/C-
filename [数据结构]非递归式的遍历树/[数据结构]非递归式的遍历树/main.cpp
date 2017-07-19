#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

/*
步骤1:
	如果节点有左子树, 该结点入栈
	如果没有, 访问该结点
步骤2:
	如果节点没有右子树, 重复步骤1
	如果结点没有右子树(结点访问完毕), 根据栈顶元素指示回退, 访问栈顶元素, 并访问右子树, 重复步骤1
	如果栈顶为空, 表示遍历结束

*/

typedef struct BiTNode
{
	int nData;
	struct BiTNode *lchild, *rchild;
}BiTNode;

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

//一直左走 走到中序遍历的起点
BiTNode *goLeft(BiTNode *T, stack<BiTNode *> &s)
{
	if (NULL == T)
	{
		return NULL;
	}
	while (NULL != T->lchild)
	{
		s.push(T);
		T = T->lchild;
	}
	return T;
}

void ModOrder(BiTNode *root)
{
	BiTNode *t = NULL;
	if (NULL == root)
	{
		return;
	}
	stack<BiTNode *> s;

	t = goLeft(root, s);

	while (t)
	{
		printf("%d\t", t->nData);

		//如果 t 有右子树 重复步骤1
		if (NULL != t->rchild)
		{
			t = goLeft(t->rchild, s);
		}
		else if (!s.empty())	//如果没有右子树则根据栈顶元素 回退
		{
			t = s.top();
			s.pop();
		}
		else
		{
			t = NULL;
		}

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

	modOrder(&t1);
	puts("");

	ModOrder(&t1);
	puts("");
	system("pause");
	return ret;
}