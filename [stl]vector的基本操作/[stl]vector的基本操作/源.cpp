#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>

//vector �����Ԫ�غ�ɾ��Ԫ��  ��ȡͷ��Ԫ�غ�β��Ԫ��
int main11()
{
	vector<int > a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	a.push_back(9);
	
	//��ȡ����
	cout << a.size() << endl;

	//��ȡͷ��Ԫ��
	cout << "��ȡͷ��Ԫ��\n" << a.front() << endl;

	//�޸�Ԫ�ص�ֵ
	a.front() = 11;

	cout << "��ȡβ��Ԫ��" << endl;
	while (a.size() != 0)
	{
		//��ȡβ��Ԫ��
		cout << a.back() << endl;
		a.pop_back();
	}
	return 0;
}

void printA(vector<int> &v1)
{
	for (vector<int>::iterator it = v1.begin(); v1.end() != it; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main13()
{
	vector<int> a(10);
	int i = 0;

	for (i = 0; i < a.size(); i++)
	{
		a[i] = i + 1;
	}

// 	cout << "ɾ��ǰ:" << endl;
// 	printA(a);
// 
// 	a.erase(a.begin(), a.end());
// 
// 	cout << "ɾ����" << endl;
// 	printA(a);
// 	for (i = 0; i < a.size(); i++)
// 	{
// 		a[i] = i + 1;
// 	}
//	a.erase(a.begin());
// 	for (i = 0; i < a.size(); i++)
// 	{
// 		a[i] = i + 1;
// 	}
	
	
//	ɾ��ָ��Ԫ�ص�ֵ
	for (vector<int>::iterator it = a.begin(); a.end() != it;)
	{
		if (2 == *it)
		{
			it = a.erase(it);		//��� erase �����Ὣ it��ǰ��ֵɾ�� ��������ƶ�һ��λ��
		}
		else
		{
			it++;
		}
	}

	printA(a);

	return 0;
}

//ͷ�������β������
void main14()
{
	vector<int> v1(10);
	int i = 0;
	for (i = 0; i < v1.size(); i++)
	{
		v1[i] = i + 1;
	}

	v1.insert(v1.begin(), 10);

	v1.insert(v1.end(), 22);

	printA(v1);
}

int main(int argv, char *args[])
{
	int ret = 0;
	//main11();
	//main13();
	main14();
	system("pause");
	return ret;
}