#pragma once
//这就是一个节点
template <class T>
class _tag_linklist
{
public:
	_tag_linklist<T> *pNext;
	T data;
};

template <class T>
class linklist
{
public:
	linklist();
	~linklist();
	//长度
	int len();
	//读取
	int get(T &t, int pos);
	//插入
	int insert(T &t, int pos);
	//删除
	int del(T &t, int pos);
	//清空
	int clear();
private:
	_tag_linklist<T> *head;
	int m_len;
};

