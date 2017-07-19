#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyClass.h"
using namespace std;

int main(int argv, char *args[])
{
	_Tag_Array a(10); //定义10个元素的数组

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