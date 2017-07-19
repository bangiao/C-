#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void print(int a, int b)
{
	cout << "a:" << a << " b:" << b << endl;
}

int main(int argv, char *args[])
{
	int a = 10;
	int b = 20;

	Swap(a, b);
	print(a, b);
	system("pause");
	return 0;
}