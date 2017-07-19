#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		this->a = 0;
	}
	int a;
};

class B1 : public A
{
public:
	B1()
	{
		this->b1 = 0;
	}
	int b1;
};

class B2 : public A
{
public:
	B2()
	{
		this->b2 = 0;
	}
	int b2;
};

class C : public B1, public B2
{
public:
	C()
	{
		this->c = 0;
	}
	int c;
};

int main(int argv, char *args[])
{
	C c1;
//	c1.a;	//解决这个问题的方法是 虚继承
	c1.b1;
	c1.b2;
	c1.c;
	printf("hello world...\n");
	system("pause");
	return 0;
}