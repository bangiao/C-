#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��������ʽ��
struct BiTNode 
{
	int data;
	struct BiTNode *lchild, *rchild;
};

//��������ʾ��
struct TriNode 
{
	int data;
	struct TriNode *lchild, *rchild;
	struct TriNode *parent;
};

//˫�ױ�ʾ��

//����������
#define MAX_TREE_SIZE 100
struct  BPTNode
{
	int data;
	int ParentPostion;	//˫�׵������±�
	char LRTag;		//���Һ��ӱ�־ 1 ���� 2�Һ���
};

struct BPTree 
{
	BPTNode nodes[MAX_TREE_SIZE];	//�ڵ�
	int num_node;		//�ڵ���Ŀ
	int root;		//���ڵ��λ�� ���׽ڵ�������±�
};

int main(int argc, char *argv[])
{
	int ret = 0;
	
	
	system("pause");
	return ret;
}