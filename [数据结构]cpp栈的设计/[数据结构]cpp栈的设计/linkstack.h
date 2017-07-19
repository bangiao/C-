#pragma once
#include "linklist.h"
template <class T>
class linkstack
{
public:
	linkstack();
	~linkstack();

	void clear();

	int size();

	int push(T &t);

	int pop(T &t);

	int top(T &t);
private:
	linklist<T> *list;
};

