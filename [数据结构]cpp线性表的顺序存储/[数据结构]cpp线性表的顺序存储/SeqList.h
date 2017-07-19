#pragma once

template <class T>
class SeqList
{
public:
	SeqList(int Capacity);
	~SeqList();

	int insert(T &Node, int pos);

	int getLen();

	int getCapacity();

	int get(int pos, T &s);

	int del(int pos, T &s);

	int clear();

private:
	int length;
	int capacity;
	T *TArray;
};

