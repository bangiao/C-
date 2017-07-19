#define  _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
#include <iostream>
using namespace std;

template <class T>
SeqList<T>::SeqList(int Capacity)
{
	this->TArray = new T[Capacity];
	this->capacity = Capacity;
	this->length = 0;
}

template <class T>
SeqList<T>::~SeqList()
{
	delete[]this->TArray;
	this->TArray = NULL;
	this->length = 0;
	this->capacity = 0;
}

template <class T>
int SeqList<T>::insert(T &Node, int pos)
{
	if (pos < 0)
	{
		return -1;
	}
	int i = 0;

	for (i = this->length; i > pos; i--)
	{
		this->TArray[i] = this->TArray[i - 1];
	}
	this->TArray[pos] = Node;
	this->length++;
	return 0;
}

template <class T>
int SeqList<T>::getLen()
{
	return this->length;
}

template <class T>
int SeqList<T>::getCapacity()
{
	return this->capacity;
}

template <class T>
int SeqList<T>::get(int pos, T &s)
{
	if (pos < 0)
	{
		return -1;
	}
	s = this->TArray[pos];
	return 0;
}

template <class T>
int SeqList<T>::del(int pos, T &s)
{
	int i = 0;
	if (pos < 0)
	{
		return -1;
	}
	s = this->TArray[pos];
	for (i = pos + 1; i < this->length; i++)
	{
		this->TArray[i - 1] = this->TArray[i];
	}
	this->length--;
	return 0;
}
template <class T>
int SeqList<T>::clear()
{
	this->length = 0;
	return 0;
}