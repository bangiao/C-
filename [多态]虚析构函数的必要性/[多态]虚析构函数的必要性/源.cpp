#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "parent" << endl;
	}
	virtual ~Parent()
	{
		cout << "~Parent" << endl;
	}
	virtual void print()
	{
		cout << "Parent print" << endl;
	}
protected:
private:
};

class Child : public Parent
{
public:
	Child()
	{
		cout << "Child" << endl;
	}
	~Child()
	{
		cout << "~Child" << endl;
	}
	void print()
	{
		cout << "Child print" << endl;
	}
protected:
private:
};

int mainOP()
{
	Child *c1 = new Child;
	Parent *p1;
	p1 = c1;
	p1->print();
	delete p1;		//�������û��ʹ�������������Ļ���ֻ���ø������������ ������������������������
	return 0;
}

int main(int argv, char *args[])
{
	mainOP(); 
	printf("hello world...\n");
	system("pause");
	return 0;
}