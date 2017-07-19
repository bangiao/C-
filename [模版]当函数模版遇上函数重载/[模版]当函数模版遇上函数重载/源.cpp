#include <iostream>
using namespace std;

int Max(int a, int b)
{
	return (a > b ? a : b);
}

int Max(int a, int  b, int c)
{
	return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

template <class T>
T Max(T a, T b)
{
	return (a > b ? a : b);
}

template <class T>
T Max(T a, T b, T c)
{
	return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

int print(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	cout << Max(1, 2) << endl;	//��ģ�溯������ͨ���������ʵ�ʱ��һ��ʹ�� ��ͨ����
	cout << Max<>(1, 2) << endl;	//��ʹ�ÿ�ģ���� ǿ�Ƶ���ģ�溯��
	cout << Max<float>(1, 2) << endl;//��ǿ��ת����ʱ�����a�ͱ���b�ᱻǿ��ת���ɸ�����
	cout << Max<float>('a', 'h') << endl;

	cout << Max(1, 'a') << endl;	//����ͨ�����������õ����Ͳ�������c++�������������������� char���int int���char
									//����ģ�溯��ȴ�޷�ʵ���������
	print(1, 'b');					//��ͨ�����������������

	cout << Max('a', 'b') << endl;			//����ͨ������������������Ҫ����������Ǹ�ת��ʱ���ȿ���ģ��

	cout << Max(1.0, 2.0) << endl;	//ֱ�ӵ���ģ�溯��
	system("pause");
	return 0;
}