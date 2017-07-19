#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyVector.h"
using namespace std;


template <typename T>
MyVector<T>::MyVector(int Size = 0)
{
	this->m_Size = Size;
	this->m_Space = new T[Size];
	memset(this->m_Space, 0, sizeof(T) * Size);
}

template <typename T>
MyVector<T>::MyVector(const MyVector &obj)
{
	this->m_Size = obj.m_Size;
	this->m_Space = new T[this->m_Size];
	memcpy(this->m_Space, obj.m_Space, sizeof(T) * obj.m_Size);
}

template <typename T>
MyVector<T>::~MyVector()
{
	this->m_Size = 0;
	if (0 != this->m_Space)
	{
		delete[]this->m_Space;
		this->m_Space = NULL;
		this->m_Size = 0;
	}
}

template <typename T>
int MyVector<T>::getLen()
{
	return this->m_Size;
}

template <typename T>
T& MyVector<T>::operator[](int Index)
{
	return (this->m_Space[Index]);
}

template <typename T>
MyVector<T> &MyVector<T>::operator = (const MyVector &obj)
{
	if (NULL == this->m_Space)
	{
		delete[]this->m_Space;
		this->m_Space = NULL;
		this->m_Size = 0;
	}
	this->m_Size = obj.m_Size;
	memcpy(this->m_Space, obj.m_Space, sizeof(T) * obj.m_Size);
	return *this;
}
