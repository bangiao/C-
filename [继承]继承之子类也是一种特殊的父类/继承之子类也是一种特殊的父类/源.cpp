#include <iostream>
using namespace std;

class Parent
{
public:
	int i;
protected:
};

class Child : public Parent
{
public:
	int j;
protected:
};

void print(Parent &p1)		//参数为父类
{
	cout << p1.i << endl;
}

int main()
{
	Child c1;

	c1.i = 10;

	print(c1);	//传入子类, 但是参数是父类

	system("pause");
	return 0;
}