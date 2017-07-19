#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "父类的构造函数" << endl;
	}
	void printP()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
	~Parent()
	{
		this->a = 0;
		this->b = 0;
	}
protected:
private:
	int a;
	int b;
};

class Child : public Parent
{
public:
	Child(int a, int b, int c) : Parent(a, b)
	{
		this->c = c;
	}
	~Child()
	{
		this->c = c;
	}
	void printC()
	{
		this->printP();
		cout << this->c << endl;
	}
protected:
private:
	int c;
};

int main(int argv, char *args[])
{
	Child c1(1, 2, 3);
	c1.printC();
	printf("hello world...\n");
	system("pause");
	return 0;
}
