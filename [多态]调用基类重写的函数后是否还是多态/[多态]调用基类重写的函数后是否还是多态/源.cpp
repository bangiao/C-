#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// c++ 中的  static 修饰类的成员方法时, 这个成员方法就成为静态成员方法了, 可以脱离对象的存在
// 直接调用了
class People
{
public :
	People()
	{
		cout << "People 构造函数" << endl;
	}
	~People()
	{
		cout << "People 析构函数" << endl;
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
		cout << "Child 构造函数" << endl;
	}
	~Child()
	{
		cout << "Child 析构函数" << endl;
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
		cout << "Teacher 构造函数" << endl;
	}
	~Teacher()
	{
		cout << "Teacher 析构函数" << endl;
	}
	virtual void say()
	{
		cout << "My name is Teacher" << endl;
	}
};

int main(void)
{
	// 要修改的地方, 就这一处
	People *p = new Child();

	p->say();
	delete p;
	p = NULL;

	// 要修改的地方, 就这一处
	p = new Teacher();
	p->say();
	delete p;
	p = NULL;

	system("pause");
	return 0;
}