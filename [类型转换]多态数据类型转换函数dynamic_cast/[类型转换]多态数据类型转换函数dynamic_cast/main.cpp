#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//dynamic_cast<typename>(变量) 用于多态的数据类型转换
//如果原本的子类类型和转换的子类类型相同则返回非NULL否则相反返回NULL;
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
		cout << "学生" << endl;
	}
	void Study()
	{
		cout << "学习" << endl;
	}
};

class Teacher : public Person
{
public:
	void cry()
	{
		cout << "老师" << endl;
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