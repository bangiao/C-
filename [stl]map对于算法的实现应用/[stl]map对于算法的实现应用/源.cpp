#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <map>

int main(int argc, char *argv[])
{
	int ret = 0;
	int a[] = { 1, 1, 2, 3, 4, 5, 6, 5, 5, 7, 8 };
	int i = 0;
	int Array_Len = sizeof(a) / sizeof(int);


	//map��int int �ֱ�Ϊ key��value ͬʱ��Ϊ int
	// ��һ��int ���ڴ�� a[i] �ڶ��� ���� ������ͬ
	//���� ����map��������ͬkey�����ķ���
	//Ҳ���� insert �ķŻ�ֵ
	//�鿴Դ���֪ �� _Pairib  pair <iterator, bool>
	/*
	_Pairib insert(const value_type& _Val)
	{	// try to insert node with value _Val, favoring right side
	return (_Insert_nohint(false,
	_Val, _Nil_obj));
	}
	*/
	/*
	˼·:
		��Ϊ key = value ====>
		a[i] = a[i]���ֵĴ���
		����map���������ظ�ֵ  �� insert �ķ���ֵ
	*/
	map<int, int>m;

	for (i = 0; i < Array_Len; i++)
	{
		pair<map<int, int>::iterator, bool> pairib = m.insert(map<int, int>::value_type(a[i], 1));
		//��������� 1   ��һ�ε�ֵ ������һ  �������ɹ�һ�����key
		if (false == pairib.second)
		{
			m[a[i]]++;
		}
	}
	int nMax = 0;
	int ArrayValue = 0;
	int n = 0;
	for (i = 0; i < Array_Len; i++)
	{
		if (nMax < m[a[i]])
		{
			nMax = m[a[i]];
			ArrayValue = a[i];
			n = i;
		}
	}
	cout << "�±�:" << n << "����Ԫ��:" << ArrayValue << "���ٸ�:" << nMax << endl;

	system("pause");
	return ret;
}