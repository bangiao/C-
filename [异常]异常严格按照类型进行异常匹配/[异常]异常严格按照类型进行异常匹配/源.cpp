#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void Div(int &a, int &b)
{
	if (0 == b)
	{
		throw b;			//�����ϸ�İ������͵��쳣  ���û������󱨴�
	}
	a = a - b;
}

int main(int argv, char *args[])
{
	int ret = 0;
	int a = 10;
	int b = 0;
	try
	{
		Div(a, b);
	}
	catch (char err)			//err
	{
		cout << err << endl;
	}
	catch (...)
	{
		cout << "err err " << endl;
	}
// 	catch (int arr)
// 	{
// 		cout << arr << endl;
// 	}
	
	system("pause");
	return ret;
}