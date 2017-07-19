#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二叉链表式法
struct BiTNode 
{
	int data;
	struct BiTNode *lchild, *rchild;
};

//三叉链表示法
struct TriNode 
{
	int data;
	struct TriNode *lchild, *rchild;
	struct TriNode *parent;
};

//双亲表示法

//就是两个表
#define MAX_TREE_SIZE 100
struct  BPTNode
{
	int data;
	int ParentPostion;	//双亲的数组下标
	char LRTag;		//左右孩子标志 1 左孩子 2右孩子
};

struct BPTree 
{
	BPTNode nodes[MAX_TREE_SIZE];	//节点
	int num_node;		//节点数目
	int root;		//根节点的位置 父亲节点的数组下标
};

int main(int argc, char *argv[])
{
	int ret = 0;
	
	
	system("pause");
	return ret;
}