#include <iostream>
using namespace std;

struct A 
{
	char &b = a;
	char a{0};
};

int func(int &a)
{
	return a + 1;
}

int func2(int *a)
{
	return *a + 1;
}

int func3(int a)
{
	return a + 1;
}

int main(void)
{
 	int v = 10;
// 	func(v);
// 	func2(&v);
// 	func3(v);
// 	cout << sizeof(A) << endl;

	int &a = v;
	int &b = v;

	cout << "a: " << &a << endl
		<< "b: " << &b << endl;

	int *p1 = &v;
	int *p2 = &v;

	cout << "p1: " << p1 << endl
		<< "p2: " << p2 << endl;

	cout << "&p1: " << &p1 << endl
		<< "&p2: " << &p2 << endl;


	system("pause");
	return 0;
}
