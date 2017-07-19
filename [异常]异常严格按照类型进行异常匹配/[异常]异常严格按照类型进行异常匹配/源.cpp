#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void Div(int &a, int &b)
{
	if (0 == b)
	{
		throw b;			//这是严格的按照类型的异常  如果没有则错误报错
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