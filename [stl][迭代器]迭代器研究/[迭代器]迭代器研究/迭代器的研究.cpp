#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>

//����������һ��ָ��  �÷���ָ������
//��Ҫ֪����������Ҫ֪���⼸��:
//һ:
//1	�������� begin() ָ����������ͷ��Ԫ��
//2	�������� end() ָ������������һ����Ԫ��֮��(��ʱ����ָ�������Ԫ��)

// begin()
//  1   3   5
//  ��
// end()
//  1   3   5
//            ��

//2  ������������

// 1)ֻ��
// 2)ֻд
// 3)����
// 4)˫��
// 5)����

//�����������Ԫ��
int main11()
{
	vector<int> v1(10);
	int i = 0; 
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++, i++)
	{
		*it = i + 1;
	}

	for (vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	return 0;
}


//�����������Ԫ��
int main12()
{
	vector<int> v1(10);
	int i = 0;
	
	for (vector<int>::iterator it = v1.begin(); v1.end() != it; it++)
	{
		*it = i++;
	}

	for (vector<int>::reverse_iterator it1 = v1.rbegin(); it1 != v1.rend(); it1++)
	{
		cout << *it1 << " ";
	}

	cout << endl;
	return 0;
}

int main(int argv, char *args[])
{
	int ret = 0;
	
//	main11();
	main12();
	system("pause");
	return ret;
}