#include <iostream>
using namespace std;

class A
{
public:
	int a;
	int b;
	A(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void print()
	{
		cout << "a:" << a << "   b:" << b << endl;
	}
private:
};

class B : public A
{
public:
protected:
private:
};


//������һ������ĸ��� -- > ���Ƽ�����ԭ��
int main()
{
	A a;
	a.print();
	B b;
	b.print();
	A *pA = NULL;
	pA = &b;
	pA->print();
	system("pause");
	return 0;
}
