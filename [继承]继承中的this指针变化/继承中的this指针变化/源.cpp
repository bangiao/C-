#include <iostream>
using namespace std;

class Parent
{
public:
	int a;
	void print()
	{
		cout << "Parent()" << endl;
		cout << this << endl;
	}
};

class Child : public Parent
{
public:
	int b;
	void print()
	{
		cout << "Child()" << endl;
		cout << this << endl;
	}
};


int main()
{
	Child c;

	c.Child::print();
	c.Parent::print();

	system("pause"); 

	return 0;
}