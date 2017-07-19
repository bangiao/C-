#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class T>
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
protected:
	T a;
};

template <class T>
//需要确定以什么形式派生继承父类的东西
class BB : public AA<T>
{
public:
	BB(T a, T b) : AA<T>(a)	//同样的要知道怎么析构
	{
		this->b = b;
	}

	void printB()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
protected:
	T b;
};

int main(int argv, char *args[])
{
	BB<int> b1(1, 2);
	b1.printB();
	printf("hello world...\n");
	system("pause");
	return 0;
}