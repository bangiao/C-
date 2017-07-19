#include <iostream>
using namespace std;

void div(int *a, int *b)
{
	if (0 == *b)
	{
		throw *b;
	}
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void test()
{
	int a = 10;
	int b = 0;
	try
	{
		div(&a, &b);
	}
	catch (...)
	{
		throw;	//这里将抛出 *b 变量
	}
}

int main(int argv, char *args[])
{
	try
	{
		test();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (...)
	{
		cout << "other err" << endl;
	}
	system("pause");
	return 0;
}