#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int *&&add(const int a, const int b)
{
	int sum = 0;
	cout << "&sum: " << &sum << endl;
	sum = a + b;
	return &sum;
}

int main(void)
{
	const int num = 10;
	char *p = "abcd";
	int kk = 10;
	int kk2 = 20; 

	cout << &num << endl;
	cout << &"abcd" << endl;
	cout << &kk << endl;
	cout << &kk2 << endl;

	const int *tmp = add(kk, kk2);
	cout << *tmp << endl;
	
	system("pause");
	return 0;
}