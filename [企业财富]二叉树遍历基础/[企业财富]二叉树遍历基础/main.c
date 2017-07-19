#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�������õݹ�����õķ���
//�������ı�������������
//�������
//�������
//�������
typedef struct _BitNode 
{
	int data;						//���ݽṹ
	struct _BitNode *lChild;		//����
	struct _BitNode *rChild;		//�Һ���
}BitNode, *BitTree;

//������
typedef struct _TriNode 
{
	int data;						//���ݽṹ
	struct _TriNode *lChild;		//����
	struct _TriNode *rChild;		//�Һ���
	struct _TriNode *Parent;		//����
}TriNode, *TriTree;

//˫������
#define MAX_TREE_SIZE 100
typedef struct  _BPTNode
{
	int data;
	int *parent;		//ָ��˫�׵�ָ��
	char LRTag;			//���Һ��ӱ�־
}BPTNode;

typedef struct _BPTree 
{
	BPTNode nodes[MAX_TREE_SIZE];//��Ϊ�ڵ�֮���Ƿ�ɢ����Ҫ�ѽڵ�洢��������
	int num_node;//�ڵ����Ŀ
	int root;//���ڵ��λ��//ע�����洢���Ǹ��׽ڵ���������±�
}BPTree;

//�������
void PreOrder(BitNode *T)
{
	if (T != NULL)
	{
		printf("%d\n", T->data);	//�ȴ�ӡ��ͷ���
		PreOrder(T->lChild);		//Ȼ���ӡ��ڵ�
		PreOrder(T->rChild);		//�ٴ�ӡ�ҽڵ�
	}
}
//�������
void MidOrder(BitNode *T)
{
	if (T != NULL)
	{
		MidOrder(T->lChild);		//Ȼ���ӡ��ڵ�
		printf("%d\n", T->data);	//�ȴ�ӡ��ͷ���
		MidOrder(T->rChild);		//�ٴ�ӡ�ҽڵ�
	}
}
//�������
void AfrOrder(BitNode *T)
{
	if (T != NULL)
	{
		AfrOrder(T->lChild);		//Ȼ���ӡ��ڵ�
		AfrOrder(T->rChild);		//�ٴ�ӡ�ҽڵ�
		printf("%d\n", T->data);	//�ȴ�ӡ��ͷ���
	}
}
/*
		1
    2     3
  4		5
*/

/*
��������
1��Ҷ�ӽڵ�����
2copy������
3���������
*/

int g_num = 0;

int Point_Num(BitNode *T)
{
	if (NULL != T)
	{
		if (NULL == T->lChild && NULL == T->rChild)
		{
			g_num++;

		}
		Point_Num(T->lChild);
		Point_Num(T->rChild);
	}
	return 0;
}
/*
1
2     3
4		5
*/
int Point_Num2(BitNode *T, int *num)
{
	if (NULL != T)
	{
		Point_Num2(T->lChild, num);
		Point_Num2(T->rChild, num);
		if (NULL == T->lChild && NULL == T->rChild)
		{
			(*num)++;
		}
	}
	return 0;
}

//���������
/*
�����Һ��ӵ����������ϸ�(1)�����������
*/
int TreeDepth(BitNode *T)
{
	int DepthVal = 0, DepthL = 0, DepthR = 0;

	if (NULL == T)
	{
		DepthVal = 0;
		return DepthVal;
	}
	DepthL = TreeDepth(T->lChild);
	DepthR = TreeDepth(T->rChild);
	DepthVal = 1 + (DepthL > DepthR ? DepthL : DepthR);
	return DepthVal;
}

int main()
{
	BitNode a, b, c, d, e;
	int num = 0;
	memset(&a, 0, sizeof(BitNode));
	memset(&b, 0, sizeof(BitNode));
	memset(&c, 0, sizeof(BitNode));
	memset(&d, 0, sizeof(BitNode));
	memset(&e, 0, sizeof(BitNode));
	a.data = 1;
	b.data = 2;
	c.data = 3;
	d.data = 4;
	e.data = 5;

	//�������Ĺ�ϵ
	a.lChild = &b;
	a.rChild = &c;
	b.lChild = &d;
	c.lChild = &e;


	//�������  ����ͷ��� Ȼ������ߵĽڵ�(����) Ȼ������ұߵĽڵ�(�Һ���)
	printf("�������\n");
	PreOrder(&a);
	printf("�������\n");
	MidOrder(&a);
	printf("�������\n");
	AfrOrder(&a);
	printf("��Ҷ�ӽڵ�����\n");
	Point_Num(&a);
	printf("�ڵ������:%d\n", g_num);

	Point_Num2(&a, &num);
	printf("�ڵ������:%d\n", num);

	printf("�������:%d\n", TreeDepth(&a));
	system("pause");
	return 0;
}