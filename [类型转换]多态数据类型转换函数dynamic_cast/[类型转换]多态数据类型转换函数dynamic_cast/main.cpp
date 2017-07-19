#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//dynamic_cast<typename>(����) ���ڶ�̬����������ת��
//���ԭ�����������ͺ�ת��������������ͬ�򷵻ط�NULL�����෴����NULL;
class Person
{
public:
	virtual void cry() = 0;
};

class Child : public Person
{
public:
	void cry()
	{
		cout << "ѧ��" << endl;
	}
	void Study()
	{
		cout << "ѧϰ" << endl;
	}
};

class Teacher : public Person
{
public:
	void cry()
	{
		cout << "��ʦ" << endl;
	}
	void Teacher_Child()
	{
		cout << "Teacher_Child()" << endl;
	}
};

void print(Person *Base)
{
	Base->cry();

	Child *c1 = dynamic_cast<Child *>(Base);
	if (NULL != c1)
	{
		c1->Study();
	}

	Teacher *t1 = dynamic_cast<Teacher *>(Base);
	if (NULL != t1)
	{
		t1->Teacher_Child();
	}
	return;
}

int main(int argv, char *args[])
{
	Child c1;
	Teacher t1;

	print(&c1);
	print(&t1);
	system("pause");
	return 0;
}