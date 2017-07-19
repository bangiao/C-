#define  _CRT_SECURE_NO_WARNINGS
#include "linkstack.h"
#include <iostream>
using namespace std;

template <class T>
linkstack<T>::linkstack()
{
	this->list = new linklist<T>;
	//memset(this->list, 0, sizeof(linklist<T>));	//this->list �ײ��д��� head ��new �����ֵΪ 0 ���������
	//Ҳ����˵ head = NULL �������ǰ׷���???
	//�������������ǳ���������� ��Ϊ head ��ָ��
}

template <class T>
linkstack<T>::~linkstack()
{
	if (NULL != this->list)
	{
		delete this->list;
	}
	this->list = NULL;
}

template <class T>
void linkstack<T>::clear()
{
	this->list->clear();
}

template <class T>
int linkstack<T>::size()
{
	return this->list->len();
}

template <class T>
int linkstack<T>::push(T &t)
{
	return this->list->insert(t, 0);
}

template <class T>
int linkstack<T>::pop(T &t)
{
	return this->list->del(0, t);
}

template <class T>
int linkstack<T>::top(T &t)
{
	return this->list->get(t, 0);
}