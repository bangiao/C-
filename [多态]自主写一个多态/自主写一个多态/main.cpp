#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int Money = 0)
	{
		this->Money = Money;
	}
	virtual int GetMoney()
	{
		return Money;
	}
protected:
	int Money;
};

class Child1 : public Parent
{
public:
	Child1(int Money = 0)
	{
		this->Money = Money;
	}
	int GetMoney()
	{
		return this->Money;
	}
};

class Child2 : public Parent
{
public:
	Child2(int Money = 0)
	{
		this->Money = Money;
	}
	int GetMoney()
	{
		return this->Money;
	}
};

void print_money(Parent &p1, Parent &p2)
{
	if (p1.GetMoney() > p2.GetMoney())
	{
		cout << "p1 max" << endl;
	}
	else if (p1.GetMoney() == p2.GetMoney())
	{
		cout << "==" << endl;
	}
	else
	{
		cout << "p2 max" << endl;
	}
}

int main()
{
	Parent p1(0);
	Child1 c1(2);
	Child2 c2(1);

	print_money(p1, c1);
	print_money(c1, c2);
	print_money(c1, p1);

	system("pause");
	return 0;
}