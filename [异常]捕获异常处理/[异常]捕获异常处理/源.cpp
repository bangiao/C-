#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void print(char *str)
{
	if (0 == strcmp("11", str))
	{
		throw 1;
	}
	cout << str << endl;
}

int main(void)
{
	char *str = "11";
	try
	{
		print(str);
	}
	catch (int &e)
	{
		cout << "zhazha" << endl;
	}
	cout << str << endl;
	system("pause");
	return 0;
}