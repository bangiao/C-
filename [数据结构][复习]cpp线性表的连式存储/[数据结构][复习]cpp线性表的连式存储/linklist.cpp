#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "linklist.h"
using namespace std;

template <class T>
linklist<T>::linklist()
{
	this->head = new _tag_linklist<T>;
	memset(this->head, 0, sizeof(_tag_linklist<T>));
	this->m_len = 0;
}

template <class T>
linklist<T>::~linklist()
{
	T tmp;
	while (this->m_len > 0)
	{
		this->del(tmp, 0);
	}
	if (NULL != this->head)
	{
		delete this->head;
		this->head = NULL;
	}
}


//长度
template <class T>
int linklist<T>::len()
{
	return this->m_len;
}
//读取
template <class T>
int linklist<T>::get(T &t, int pos)
{
	int i = 0;
	if (pos < 0)
	{
		printf("func err line:^d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	if (pos > this->m_len)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	_tag_linklist<T> *pCur = NULL;
	pCur = this->head;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->pNext;
	}
	pCur = pCur->pNext;
	t = pCur->data;
	return 0;
}
//插入
template <class T>
int linklist<T>::insert(T &t, int pos)
{
	_tag_linklist<T> *pCur = NULL;
	if (pos < 0)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	int i = 0;
	pCur = this->head;
	for (i = 0; i < pos && NULL != pCur->pNext; i++)
	{
		pCur = pCur->pNext;
	}
	_tag_linklist<T> *node = new _tag_linklist<T>;
	node->data = t;
	node->pNext = NULL;

	node->pNext = pCur->pNext;
	pCur->pNext = node;
	this->m_len++;
	return 0;
}
//删除
template <class T>
int linklist<T>::del(T &t, int pos)
{
	int i = 0;
	if (pos < 0)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	_tag_linklist<T> *pCur = NULL;
	_tag_linklist<T> *Next = NULL;
	_tag_linklist<T> *tmp = NULL;
	pCur = this->head;
	for (i = 0; i < pos; i++)
	{
		pCur = pCur->pNext;
	}
	Next = pCur->pNext;
	tmp = Next;
	t = tmp->data;
	pCur->pNext = Next->pNext;
	if (NULL != tmp)
	{
		delete tmp;
		tmp = NULL;//
	}
	this->m_len--;
	return 0;
}
//清空
template <class T>
int linklist<T>::clear()
{
	this->m_len = 0;
	return 0;
}