#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyClass.h"
using namespace std;

int main(int argv, char *args[])
{
	_Tag_Array a(10); //����10��Ԫ�ص�����

	for (int i = 0; i < a.getLength(); i++)
	{
		a.setData(i, i + 1);
	}

	for (int i = 0; i < a.getLength(); i++)
	{
		cout << a.getData(i) << endl;
	}
	printf("hello world...\n");
	system("pause");
	return 0;
}