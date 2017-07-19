#pragma once
//�����һ���ڵ�
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
	//����
	int len();
	//��ȡ
	int get(T &t, int pos);
	//����
	int insert(T &t, int pos);
	//ɾ��
	int del(T &t, int pos);
	//���
	int clear();
private:
	_tag_linklist<T> *head;
	int m_len;
};

