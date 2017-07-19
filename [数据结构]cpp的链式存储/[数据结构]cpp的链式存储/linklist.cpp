#define  _CRT_SECURE_NO_WARNINGS
#include "linklist.h"
#include <iostream>
using namespace std;

template <class T>
linklist<T>::linklist()
{
	this->head = NULL;

	this->head = new Node<T>;

	memset(this->head, 0, sizeof(Node<T>));
	this->length = 0;//
}

template <class T>
linklist<T>::~linklist()
{
	T tmp;
	while (this->len())
	{
		this->del(0, tmp);
	}
	if (NULL != this->head)
	{
		delete this->head;
	}
	this->head = NULL;
	this->length = 0;
}

template <class T>
int linklist<T>::insert(T &node, int pos)
{
	Node<T> *pCur = NULL;
	pCur = this->head;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	Node<T> *newNode = new Node<T>;
	newNode->node = node;
	newNode->next = pCur->next;
	pCur->next = newNode;
	this->length++;
	return 0;
}

template <class T>
int linklist<T>::get(T &node, int pos)
{
	Node<T> *pCur = NULL;
	pCur = this->head;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	node = pCur->next->node;
	return 0;
}

template <class T>
int linklist<T>::del(int pos, T &node)
{
	Node<T> *pCur = NULL;
	Node<T> *ret = NULL;
	pCur = this->head;
	int i = 0;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	ret = pCur->next;
	node = ret->node;

	pCur->next = ret->next;
	this->length--;
	if (NULL != ret)
	{
		delete ret;
		ret = NULL; //
	}
	return 0;
}

template <class T>
int linklist<T>::len()
{
	return this->length;
}

template <class T>
int linklist<T>::clear()
{
	this->length = 0;
	return 0;
}