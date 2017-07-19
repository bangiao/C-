#include <iostream>
using namespace std;
//1. ����үү
//2. �󵽸���
//3. o1
//4. o2
//5. �Լ�
//�ܽ�:
/*
û��үү���׺��������ж���
*/
class CCObject
{
public:
	CCObject(const char *s)
	{
		cout << "CCObject ()  s:" << s << endl;
	}
	~CCObject()
	{
		cout << "~CCObject()" << endl;
	}
};

class Parent : public CCObject
{
public:
	Parent(const char *s) : CCObject("aaaaa")
	{
		cout << "Parent()" << "   s" << s << endl;
	}
	~Parent()
	{
		cout << "~Parent()" << endl;
	}
protected:
private:
};

class Child : Parent
{
public:
	Child() : o1("bba"), o2("CCCCCC"), Parent("Parent from Child()")
	{
		cout << "Child()" << endl;
	}
	~Child()
	{
		cout << "~Child()" << endl;
	}
protected:
	CCObject o1;
	CCObject o2;
};

void run32()
{
	Child c1;
}

int main()
{
	run32(); 
	system("pause");
	return 0;
}