#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <list>

int main11()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}

	cout << "����������:" << endl;
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n��ͨ����" << endl;
	while (l.size())
	{
		cout << l.front() << " ";
		l.pop_front();
	}
	cout << endl;
	return 0;
}

void printD(list<int> &l)
{
	for (list<int>::iterator it = l.begin(); l.end() != it; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//list �Ĳ���
int main12()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}
//	0	1	2	3	4	5	6	7	8	9	10  λ��
//	1	2	3	4	5	6	7	8	9	10
//	��
	list<int>::iterator it = l.begin();
	it++;
//	0	1	2	3	4	5	6	7	8	9	10  λ��
//	1	2	3	4	5	6	7	8	9	10
//		��
	it++;
//	0	1	2	3	4	5	6	7	8	9	10  λ��
//	1	2	3	4	5	6	7	8	9	10
//			��
	it++;
//	0	1	2	3	4	5	6	7	8	9	10  λ��
//	1	2	3	4	5	6	7	8	9	10
//				��
	l.insert(it, 100);
//����Ǵ� 1 ��ʼ�Ļ� ���������ǲ����� 3 �ĺ����λ��  ���λ�õ����һ һλȻ���������  ��ͼ
//	1	2	3	100	4	5	6	7	8	9	10
//				��
//����Ǵ� 0 ��ʼ�Ļ�  ����������ǲ����� 3 ���λ��  ���ʱ�� 3 �����ݺ���һ�� �ó�λ�ø��µ�λ��
//	0	1	2	100	3	4	5	6	7	8	9
//				��	
//��ʵ���������� 0 ~ 2  0  1  2 �����ݳ�Ϊ���ĸ�λ��
	printD(l);
	return 0;
}

// it++ һ��ָ�� 1 ��Ϊ begin() ָ����� ��һ������Ԫ��
//it ++ ����ָ��ڶ�������Ԫ�� 
//it ++ ����������Ԫ��

//Ҳ����:

//it - - - - -> 0

//it++ - - - -> 1

//it++ - - - - >2

//it++ - - - -->3  ���Ե� it.insert(X)ʱ ���������λ�ò���

//�������˼���� �滻���λ�õ�Ԫ�ؽ�ԭ�����λ�õ�Ԫ�غ���

int main13()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}

	printD(l);
	list<int>::iterator it = l.begin();
	it++;
	it++;
	it++;
//	1	2	3	4	5	6	7	8	9	10
//				��
	l.erase(l.begin(), it);  // cout		4 ...... 10
	printD(l);
	return 0;
}

int main14()
{
	list<int> l;

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i + 1);
	}
	l.push_back(2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}

	l.erase(l.begin());

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}
	l.remove(2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
//	main11();
//	main12();
//	main13();
	main14();
	system("pause");
	return ret;
}