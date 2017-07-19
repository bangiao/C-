#define  _CRT_SECURE_NO_WARNINGS
#include "seqList.h"
#include <iostream>
using namespace std;
template <class T>
seqList<T>::seqList(int Capacity)
{
	if (0 == Capacity)
	{
		throw - 1;
	}
	this->m_Capacity = Capacity;
	this->m_len = 0;
	this->m_node = new T[Capacity];
	memset(this->m_node, 0, sizeof(T) * Capacity);
}

template <class T>
seqList<T>::~seqList()
{
	if (NULL != this->m_Capacity)
	{
		delete []this->m_node;
		this->m_node = NULL;
	}
	this->m_len = 0;
	this->m_Capacity = 0;
}
//读取
template <class T>
int seqList<T>::get(T &t, int pos)
{
	if (pos < 0)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	t = this->m_node[pos];
	return 0;
}
//插入
template <class T>
int seqList<T>::insert(T &t, int pos)
{
	int i = 0;
	if (pos < 0)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	if (pos >= this->m_Capacity)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	if (this->m_Capacity <= this->m_len)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	if (this->m_len < pos)
	{
		pos = this->m_len;
	}
	for (i = this->m_len; i > pos; i--)
	{
		this->m_node[i] = this->m_node[i - 1];
	}
	this->m_node[pos] = t;
	this->m_len++;
	return 0;
}
//删除
template <class T>
int seqList<T>::del(T &t, int pos)
{
	int i = 0;
	if (pos < 0)
	{
		printf("func err line:%d, file:%s\n", __LINE__, __FILE__);
		return -1;
	}
	if (this->m_len < pos)
	{
		pos = this->m_len;
	}
	t = this->m_node[pos];
	for (i = pos + 1; i < this->m_len; i++)
	{
		this->m_node[i - 1] = this->m_node[i];
	}
	this->m_len--;
	return 0;
}
//长度
template <class T>
int seqList<T>::len()
{
	return this->m_len;
}
//清空
template <class T>
void seqList<T>::clear(T &t)
{
	this->m_len = 0;
}
//数量
template <class T>
int seqList<T>::capacity()
{
	return this->m_Capacity;
}