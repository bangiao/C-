#pragma once

//�ڵײ���е�ģ������Ӧ�� ����ڵ� ����ڵ� 
//���Ի����罫����ڵ�������� 
//д�ڵ��������ݽṹ��
//Ȼ����ģ����ȥ������


//�ڵ�
template <class T>
struct Node 
{
	Node<T> *next;
	T node;
};

//ģ����
template <class T>
class linklist
{
public:
	linklist();

	~linklist();

	int insert(T &node, int pos);

	int get(T &node, int pos);

	int del(int pos, T &node);

	int len();

	int clear();

private:
	Node<T> *head;
	int length;
};

