#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class test
{
public:
	test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	test()
	{
		this->a = 0;
		this->b = 0;
	}
	test(int a)
	{
		this->a = a;
		this->b = 0;
	}
	void print()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
protected:
private:
	int a, b;
};

int main(int argv, char *args[])
{
	test t1;
	test t2(1, 2);
	test t3 = (1, 2);
	test t4 = 1;
	test t5 = test(1, 2);	//匿名对象 === = = = = = 匿名对象的声明周期
	printf("hello world...\n");
	system("pause");
	return 0;
}