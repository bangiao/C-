#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//二叉树用递归是最好的方法
//二叉树的遍历方法有三种
//先序遍历
//中序遍历
//后序遍历
typedef struct _BitNode 
{
	int data;						//数据结构
	struct _BitNode *lChild;		//左孩子
	struct _BitNode *rChild;		//右孩子
}BitNode, *BitTree;

//三叉树
typedef struct _TriNode 
{
	int data;						//数据结构
	struct _TriNode *lChild;		//左孩子
	struct _TriNode *rChild;		//右孩子
	struct _TriNode *Parent;		//父亲
}TriNode, *TriTree;

//双亲链表
#define MAX_TREE_SIZE 100
typedef struct  _BPTNode
{
	int data;
	int *parent;		//指向双亲的指针
	char LRTag;			//左右孩子标志
}BPTNode;

typedef struct _BPTree 
{
	BPTNode nodes[MAX_TREE_SIZE];//因为节点之间是分散的需要把节点存储到数组中
	int num_node;//节点的数目
	int root;//根节点的位置//注意此域存储的是父亲节点在数组的下标
}BPTree;

//先序遍历
void PreOrder(BitNode *T)
{
	if (T != NULL)
	{
		printf("%d\n", T->data);	//先打印出头结点
		PreOrder(T->lChild);		//然后打印左节点
		PreOrder(T->rChild);		//再打印右节点
	}
}
//中序遍历
void MidOrder(BitNode *T)
{
	if (T != NULL)
	{
		MidOrder(T->lChild);		//然后打印左节点
		printf("%d\n", T->data);	//先打印出头结点
		MidOrder(T->rChild);		//再打印右节点
	}
}
//后序遍历
void AfrOrder(BitNode *T)
{
	if (T != NULL)
	{
		AfrOrder(T->lChild);		//然后打印左节点
		AfrOrder(T->rChild);		//再打印右节点
		printf("%d\n", T->data);	//先打印出头结点
	}
}
/*
		1
    2     3
  4		5
*/

/*
三个问题
1求叶子节点数量
2copy二叉树
3求树的深度
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

//求树的深度
/*
将左右孩子的深度求出加上根(1)就是树的深度
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

	//构建树的关系
	a.lChild = &b;
	a.rChild = &c;
	b.lChild = &d;
	c.lChild = &e;


	//先序遍历  先是头结点 然后是左边的节点(左孩子) 然后才是右边的节点(右孩子)
	printf("先序遍历\n");
	PreOrder(&a);
	printf("中序遍历\n");
	MidOrder(&a);
	printf("后序遍历\n");
	AfrOrder(&a);
	printf("求叶子节点数量\n");
	Point_Num(&a);
	printf("节点的数量:%d\n", g_num);

	Point_Num2(&a, &num);
	printf("节点的数量:%d\n", num);

	printf("树的深度:%d\n", TreeDepth(&a));
	system("pause");
	return 0;
}