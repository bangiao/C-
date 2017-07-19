#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
	输出是这样的
			B
			B
			A

	这段代码充分表明了 当子程序没有实现父类的虚函数的时候, 对象却调用了虚函数
	这个时候虚函数的调用将会去比自己大一层的长辈上去找, 去调用
*/

char buffer[512];

class A
{
public:
	A()
	{
		cout << "this is A" << endl;
	}
	virtual void print()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "this is B" << endl;
	}
	virtual void print() final
	{
		cout << "B" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "this is C" << endl;
	}
};

int main(void)
{
	A *a = new(buffer) B;
	a->print();		// B

	a = new(buffer) C;
	a->print();		// A 

	a = new(buffer) A;
	a->print();		// A 

	system("pause");
	return 0;
}