#pragma once

//在底层库中的模板类中应该 分配节点 缓存节点 
//所以还不如将这个节点独立出来 
//写在单独的数据结构中
//然后让模板类去包容它


//节点
template <class T>
struct Node 
{
	Node<T> *next;
	T node;
};

//模板类
template <class T>
class linklist
{
public:
	linklist();

	~linklist();

	int insert(T &node, int pos);

	int get(T &node, int pos);

	int del(int pos, T &node);

	int len();

	int clear();

private:
	Node<T> *head;
	int length;
};

