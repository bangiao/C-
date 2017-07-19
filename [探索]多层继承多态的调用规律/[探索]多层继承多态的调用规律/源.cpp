#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
	�����������
			B
			B
			A

	��δ����ֱ����� ���ӳ���û��ʵ�ָ�����麯����ʱ��, ����ȴ�������麯��
	���ʱ���麯���ĵ��ý���ȥ���Լ���һ��ĳ�����ȥ��, ȥ����
*/

char buffer[512];

class A
{
public:
	A()
	{
		cout << "this is A" << endl;
	}
	virtual void print()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "this is B" << endl;
	}
	virtual void print() final
	{
		cout << "B" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "this is C" << endl;
	}
};

int main(void)
{
	A *a = new(buffer) B;
	a->print();		// B

	a = new(buffer) C;
	a->print();		// A 

	a = new(buffer) A;
	a->print();		// A 

	system("pause");
	return 0;
}