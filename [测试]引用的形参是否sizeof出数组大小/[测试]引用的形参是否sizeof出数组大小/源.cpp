#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int func1(int &buf)
{
	int len = 0;
	len = sizeof(buf) / sizeof(int);
	cout << len << endl;
	return len;
}

template <class T>
int func(T &buf)
{
	int len = 0;
	len = sizeof(buf) / sizeof(T);
	cout << len << endl;
	return len;
}

template <class T>
void test(T &a)
{
	int len = 0;
	cout << "sizeof(T):" << sizeof(T) << endl;
	len = sizeof(a) / sizeof(a[0]);
	cout << "sizeof(a):" << sizeof(a) << endl;
	cout << "len:" << len << endl;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int buf[10];

//	func1(buf);
//	func(buf);
	test(buf);
	system("pause");
	return ret;
}