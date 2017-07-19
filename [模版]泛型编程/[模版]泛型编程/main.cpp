#include <iostream>
using namespace std;

template <class T>
void sockArray(T *a, int Len)
{
	int i, j;
	T tmp = 0;
	int num = 0;
	for (i = 0; i < Len; i++)
	{
		for (j = 0; j < Len; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

template <class T>
void printArray(T *a, int Len)
{
	int i;

	for (i = 0; i < Len; i++)
	{
		printf("%d\n", a[i]);
	}
}

int main()
{
	int a[] = { 43, 56, 421, 946, 63, 78, 87 };
	int num = sizeof(a) / sizeof(*a);

	sockArray<int>(a, num);

	printArray<int>(a, num);
	system("pause");
	return 0;
}