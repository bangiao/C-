#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <map>
/*
��������ı��Ҳ���� int a[N] ����� N ������ ����������Ϊ��1 - 1000�е�Ԫ��
����һ����СΪ 1000 ��Ԫ��  Ϊ���ܹ���� 1000��Ԫ��
*/
int main(int argc, char *argv[])
{
	int ret = 0;
	int a[] = { 1, 2, 4, 3, 5, 6, 7, 8, 4, 2, 5, 7, 3, 8, 4, 8, 4, 2, 2, 8, 9, 1, 3, 5, 7, 7, 5, 7, 7, 7, 7 };
	int Array_Len = sizeof(a) / sizeof(int);


	map<int, int> m;

	for (int i = 0; i < Array_Len; i++)
	{
		pair<map<int, int>::iterator, bool> Pairib = m.insert(make_pair(a[i], 1));
		if (true != Pairib.second)
		{
			m[a[i]]++;
		}
	}
	
	int nMax = 0;
	int Num = 0;
	for (int i = 0; i < Array_Len; i++)
	{
		if (nMax < m[a[i]])
		{
			nMax = m[a[i]];
			Num = a[i];
		}
	}
	cout << nMax << Num << endl;


	system("pause");
	return ret;
}