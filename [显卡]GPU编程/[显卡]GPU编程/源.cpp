#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <amp.h>
using namespace std;
using namespace concurrency;

int main(void)
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	array_view<int> arr(10, a); // GPU 数据结构

	parallel_for_each(arr.extent, [&](index <1> id) restrict (amp){
		arr[id] += 1;
	});

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}