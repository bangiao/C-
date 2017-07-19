#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

/*
����1:
	����ڵ���������, �ý����ջ
	���û��, ���ʸý��
����2:
	����ڵ�û��������, �ظ�����1
	������û��������(���������), ����ջ��Ԫ��ָʾ����, ����ջ��Ԫ��, ������������, �ظ�����1
	���ջ��Ϊ��, ��ʾ��������

*/

typedef struct BiTNode
{
	int nData;
	struct BiTNode *lchild, *rchild;
}BiTNode;

//�������
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

//һֱ���� �ߵ�������������
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

		//��� t �������� �ظ�����1
		if (NULL != t->rchild)
		{
			t = goLeft(t->rchild, s);
		}
		else if (!s.empty())	//���û�������������ջ��Ԫ�� ����
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