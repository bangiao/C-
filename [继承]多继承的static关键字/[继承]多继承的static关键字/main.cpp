#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//��̳��е�staticԪ�صĹ��ܻ���һ����
//�����Ǹ�����������Ĺ��е��ʽ�
class A
{
public:
	A(int b = 10)
	{
		this->a++;
		this->b = b;
	}
protected:
	//����
	static int a;
	int b;
};

//����
int A::a = 0;

class B : public A
{
public:
	B() : A()
	{
		this->a++;
		cout << "this is Child" << endl;
	}
	void print()
	{
		cout << "a: " << this->a << endl;
		cout << "b: " << this->b << endl;
	}
protected:
};

int main(int argv, char *args[])
{
	B b1;
	A a1;
	B b2;
	b2.print();
	printf("hello world...\n");
	system("pause");
	return 0;
}