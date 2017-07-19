#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


//≈–∂œπÊ‘Ú
bool pr_pred(int a, int b)
{
	return (a < b);
}

void main()
{
	vector<int> v1(5);

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		v1[i] = rand() % 10;
	}

	for (i = 0; i < 5; i++)
	{
		cout << v1[i] << endl;
	}

	sort(v1.begin(), v1.end(), pr_pred);

	for (i = 0; i < 5; i++)
	{
		cout << v1[i] << endl;
	}
	system("pause");
}