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

void print(Parent &p1)		//����Ϊ����
{
	cout << p1.i << endl;
}

int main()
{
	Child c1;

	c1.i = 10;

	print(c1);	//��������, ���ǲ����Ǹ���

	system("pause");
	return 0;
}