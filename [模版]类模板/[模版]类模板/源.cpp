#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class T>
class AA
{
public:
	AA(T a = 0)
	{
		this->a = a;
	}
	void print()
	{
		cout << this->a << endl;
	}
protected:
	T a;
};

int main(int argv, char *args[])
{
	AA<int> a(11);		//AA�����Ǹ�����
	a.print();
	printf("hello world...\n");
	system("pause");
	return 0;
}