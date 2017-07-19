#pragma once
template <class T>
class seqList
{
public:
	//˳��洢�Ĵ���
	seqList(int Capacity);
	//��ȡ
	int get(T &t, int pos);
	//����
	int insert(T &t, int pos);
	//ɾ��
	int del(T &t, int pos);
	//����
	~seqList();
	//����
	int len();
	//���
	void clear(T &t);
	//����
	int capacity();
private:
	int m_Capacity;
	int m_len;
	T *m_node;
};

