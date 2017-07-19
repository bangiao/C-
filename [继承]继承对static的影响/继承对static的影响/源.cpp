#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0, int b = 0, int c = 0)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	static int add()
	{
		a = a + 10;
		return 0;
	}
	void print()
	{
		cout << "a" << a << "  b" << b << "   c" << c << endl;
	}
	static int c;
private:
	static int a;	//这是声明
	int b;
};

int Parent::a = 0;		//这是定义
int Parent::c = 0;

class Child : /*private*/ public Parent
{
public:
protected:
private:
};

int main()
{
	Child c1;

	c1.add();		//static 函数仍然受到 private
	c1.c = 1;
	c1.print();
	system("pause");
	return 0;
}