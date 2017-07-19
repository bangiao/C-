#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class parent
{
public:
	void printP()
	{
		cout << "parent" << endl;
	}
protected:
private:
};
class Child : public parent
{
public:
	void printC()
	{
		cout << "Child" << endl;
	}
protected:
private:
};

void howfunc(parent &base)
{
	base.printP();
}

void howfunc2(parent base)
{
	base.printP();
}

int main(int argv, char *args[])
{
	parent p1;
	Child c1;

	parent *p2 = &c1;
	p2->printP();

	howfunc(c1);
	howfunc2(c1);
	printf("hello world...\n");
	system("pause");
	return 0;
}