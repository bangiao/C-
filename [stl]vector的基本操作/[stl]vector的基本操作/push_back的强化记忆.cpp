#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>

//push_back�ǽ�Ԫ�ز��뵽vector��ĩβ 
//�������Ǹ�����Ļ� 
//����뵽���������ĩβ֮���Ԫ�غ������⿪��һ���ռ���д������

void printV(vector<int> &v1)
{
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << "  ";
	}
	cout << endl;
}

int main21(int argv, char *args[])
{
	int ret = 0;
	vector<int> v1(10);

	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i + 1;
	}

	printV(v1);
	v1.push_back(11);
	v1.push_back(12);
	cout << "push_back() ֮��" << endl;
	printV(v1);
	system("pause");
	return ret;
}

int main22()
{
	vector<int> v1(10);

	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i + 1;
	}

	for (vector<int > ::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	return 0;
}

int main23(int argv, char *args[])
{
	int ret = 0;
	//main21();
	main22();

	system("pause");
	return ret;
}