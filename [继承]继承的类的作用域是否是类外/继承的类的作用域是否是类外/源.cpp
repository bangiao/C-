#include <iostream>
using namespace std;

class person
{
public:
	int c;
	void print()	
	{
		cout << c << endl;
		cout << b << endl;
	}
protected:
	int b;
private:
	int a;
};

class Child : private person
{
public:
	Child(int c, int b);
protected:
private:
};

Child::Child(int c, int b)
{
	this->c = c;
	this->b = b;
	print();
}

int main()
{
	Child c1(1, 2);
	system("pause");
	return 0;
}