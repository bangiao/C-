#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//同样产生了多态
class Parent
{
public:
	virtual void print()
	{
		cout << "parent" << endl;
	}
protected:
private:
};

class Child : public Parent
{
public:
	void print()
	{
		cout << "Child" << endl;
	}
protected:
private:
};

class stu : public Child
{
public:
	void print()
	{
		cout << "stu" << endl;
	}
protected:
private:
};

void howto(Parent &p1)
{
	p1.print();
}

int main(int argv, char *args[])
{
	Parent *p1 = NULL;
	stu s;
	s.print();
	p1 = &s;
	p1->print();
	howto(s);
	printf("hello world...\n");
	system("pause");
	return 0;
}