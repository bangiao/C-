#include <iostream>
using namespace std;

class KK
{
public:
	KK(int a)
	{
		this->a = a;
	}
private:
	int a{0};
	int b = 10;
	int c = 20;
	double d = 30;
};

template <class T>
void func1(T *p)
{
	cout << sizeof(T) << endl;
	cout << sizeof(p) << endl;
}

template <class T>
void func2(T &p)
{
	cout << sizeof(T) << endl;
	cout << sizeof(p) << endl;
}

int main(void)
{
	KK k(10);

	func1<KK>(&k);
	func2<KK>(k);

	system("pause");
	return 0;
}