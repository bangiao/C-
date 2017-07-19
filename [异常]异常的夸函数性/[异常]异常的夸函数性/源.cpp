#include <iostream>
using namespace std;

void Div(int &a, int &b)
{
	if (0 == b)
	{
		throw b;
	}
	a = a - b;
}

void work()
{
	int a = 20;
	int b = 0;

	Div(a, b);
}


int main(int argv, char *args[])
{
	try
	{
		work();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	system("pause");
	return 0;
}