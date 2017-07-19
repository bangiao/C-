#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// c++ �е�  static ������ĳ�Ա����ʱ, �����Ա�����ͳ�Ϊ��̬��Ա������, �����������Ĵ���
// ֱ�ӵ�����
class People
{
public :
	People()
	{
		cout << "People ���캯��" << endl;
	}
	~People()
	{
		cout << "People ��������" << endl;
	}
	virtual void say()
	{
		cout << "My name is People" << endl;
	}
};

class Child : public People
{
public:
	Child()
	{
		cout << "Child ���캯��" << endl;
	}
	~Child()
	{
		cout << "Child ��������" << endl;
	}
	virtual void say()
	{
		People::say();
		cout << "My name is Child" << endl;
	}
};

class Teacher : public People
{
public :
	Teacher()
	{
		cout << "Teacher ���캯��" << endl;
	}
	~Teacher()
	{
		cout << "Teacher ��������" << endl;
	}
	virtual void say()
	{
		cout << "My name is Teacher" << endl;
	}
};

int main(void)
{
	// Ҫ�޸ĵĵط�, ����һ��
	People *p = new Child();

	p->say();
	delete p;
	p = NULL;

	// Ҫ�޸ĵĵط�, ����һ��
	p = new Teacher();
	p->say();
	delete p;
	p = NULL;

	system("pause");
	return 0;
}