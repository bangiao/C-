#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//多继承中的static元素的功能还是一样的
//它将是父类和子类对象的共有的资金
class A
{
public:
	A(int b = 10)
	{
		this->a++;
		this->b = b;
	}
protected:
	//定义
	static int a;
	int b;
};

//声明
int A::a = 0;

class B : public A
{
public:
	B() : A()
	{
		this->a++;
		cout << "this is Child" << endl;
	}
	void print()
	{
		cout << "a: " << this->a << endl;
		cout << "b: " << this->b << endl;
	}
protected:
};

int main(int argv, char *args[])
{
	B b1;
	A a1;
	B b2;
	b2.print();
	printf("hello world...\n");
	system("pause");
	return 0;
}