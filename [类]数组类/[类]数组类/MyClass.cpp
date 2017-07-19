#include "MyClass.h"
#include <iostream>
using namespace std;

_Tag_Array::_Tag_Array(int Length)
{
	if (Length < 0)
	{
		Length = 0;
	}
	this->m_Data = new int[Length];
	this->m_Length = Length;
}
_Tag_Array::_Tag_Array(const _Tag_Array &obj)
{
	this->m_Length = obj.m_Length;
	if (NULL != this->m_Data)
	{
		delete[]this->m_Data;
	}
	this->m_Data = new int[obj.m_Length];
	memcpy(this->m_Data, obj.m_Data, sizeof(int ) * obj.m_Length);
}
_Tag_Array::~_Tag_Array()
{
	if (NULL != this->m_Data)
	{
		delete[]this->m_Data;
	}
}
void _Tag_Array::setData(int Index, int Value)
{
	this->m_Data[Index] = Value;
}
int _Tag_Array::getData(int Index)
{
	return this->m_Data[Index];
}
int _Tag_Array::getLength()
{
	return this->m_Length;
}
