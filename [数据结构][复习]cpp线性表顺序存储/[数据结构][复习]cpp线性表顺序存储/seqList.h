#pragma once
template <class T>
class seqList
{
public:
	//顺序存储的创建
	seqList(int Capacity);
	//读取
	int get(T &t, int pos);
	//插入
	int insert(T &t, int pos);
	//删除
	int del(T &t, int pos);
	//销毁
	~seqList();
	//长度
	int len();
	//清空
	void clear(T &t);
	//数量
	int capacity();
private:
	int m_Capacity;
	int m_len;
	T *m_node;
};

