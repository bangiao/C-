#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����ģ������ϸ�����ͻ��� �������κε���ʽת��
template <class T, class C>
void MySwap(T &a, C &b)
{
	T tmp = 0;
	tmp = (T)a;
	a = b;
	b = (C)tmp;
}

void MySwap(int &a, char &b)
{
	int tmp = 0;
	tmp = (char)a;
	a = b;
	b = (char)tmp;
}

int main(int argv, char *args[])
{
	int a = 10;
	char b = 'z';
	MySwap(a, b);				//������û�в��������б��ʱ��Ĭ�ϵ������صĺ���
	MySwap(b, a);
	MySwap<int, char>(a, b);	//�������������Ͳ����б��ʱ�����ʱ�����ģ�溯��
	printf("hello world...\n");
	system("pause");
	return 0;
}