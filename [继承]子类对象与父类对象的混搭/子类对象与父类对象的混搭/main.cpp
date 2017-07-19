#include <iostream>
using namespace std;

class Parent
{
public:

	Parent(int i = 0, int j = 0)
	{
		this->i = i;
		this->j = j;
		cout << "Parent()" << endl;
	}
	virtual void print()
	{
		cout << "Parent :: print()" << endl;
	}
protected:
	int i;
	int j;
private:
};

class Child : public Parent
{
public:
	Child(int i = 0, int j = 0, int k = 0)
	{
		this->i = i;
		this->j = j;
		this->k = k;
		printf("Child()\n");
	}

	void print()
	{
		printf("Child::print()\n");
	}
protected:
	int k;
private:
};

void howtofun(Parent *pBase)
{
	pBase->print();
}

// void print(int x, int y)
// {
// 	cout << x << y << endl;
// }

int main()
{
	int i = 0;
	Parent *p = NULL;
	Child *c = NULL;
	Child a1(1, 2);
	Child a2(3, 4);
	Child a3(5, 6);
	Child ca[3] = { Child(1, 2), Child(3, 4), Child(5, 6) };

	int x = 70;
	int y = 10;

//	print(x < 70 ? x++ : x--, y < 10 ? y++ : y--);

	p = ca;		//复制兼容性原则
	c = ca;

	p->print();
	c->print();

	p++;		//指针存在步长问题 这里的p 和c步长不相同
	c++;

	printf("sizeof(p):%d\n", sizeof(*p));
	printf("sizeof(c):%d\n", sizeof(*c));


// 	c->print();
// 	p->print();

	for (i = 0; i < 3; i++)
	{
		howtofun(&ca[i]);
	}

	system("pause");
	return 0;
}