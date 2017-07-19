#define  _CRT_SECURE_NO_WARNINGS
#include "linkstack.h"
#include <iostream>
using namespace std;

template <class T>
linkstack<T>::linkstack()
{
	this->list = new linklist<T>;
	//memset(this->list, 0, sizeof(linklist<T>));	//this->list 底层有存在 head 是new 如果赋值为 0 则出现问题
	//也就是说 head = NULL 这样不是白费了???
	//这就有类似于深浅拷贝的问题 因为 head 是指针
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