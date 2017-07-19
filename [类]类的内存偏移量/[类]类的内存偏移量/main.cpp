#include <iostream>
using namespace std;

struct MyStruct
{
	int age{1};// 4
	int a1{ 2 };
	int a2{ 3 };
	int a3{ 4 };
	void show()
	{

	}
	int kk{ 5 };
};

int main(void)
{
	cout << sizeof(MyStruct) << endl;

	cout << (int)(&(((MyStruct *)(NULL))->kk)) << endl;
	MyStruct m;
	cout << &m << endl;
	cout << &(m.kk) << endl;
	system("pause");
	return 0;
}