#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Abs_A
{
public:
	virtual void print(char *str) = 0;
	void _print(char *str)
	{
		cout << str << endl;
	}
protected:
private:
};

class B : public Abs_A
{
public:
	virtual void print(char *str)
	{
		cout << str << endl;
	}
private:
	char str[1024]{"helloworld"};
};

int main(void)
{
	B b;
	b._print("_print");
	b.print("kankan");
	system("pause");
	return 0;
}