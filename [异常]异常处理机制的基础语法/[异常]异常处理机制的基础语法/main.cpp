#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int div1(int a, int b)
{
	int k;
	if (1 == b)
	{
		throw b;
	}
	k = a / b;
	return k;
}

int main(int argv, char *args[])
{
	int k = 0;
	int i = 10, j = 0;
//	div(i, 1);		//һ���쳣���׳�����Ҫ��catchȥ��ȥ��
	try
	{
		div1(i, j);
	}
	catch (int e)
	{
		cout << e << "����Ϊ0 " << endl;
	}
	catch (...)
	{
		cout << "err" << endl;
	}
	system("pause");
	return 0;
}