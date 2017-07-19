#include <iostream>
using namespace std;
//1. 先构造的后析构
//2. 继承中构造函数会首先构造基类(父类)然后构造子类(派生类)  没有父亲哪有儿子
//子类对象构造时, 需要调用父类的构造函数进行构造
//子类对象析构时, 需要调用父类对象的父类的析构函数进行销毁
class Parent
{
public:
	Parent(const char *s)
	{
		cout << "Parent ()" << endl;
	}
	Parent()
	{
		cout << "Parent ()" << endl;
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
	Child() : Parent("aaaaaaaaaa")
	{
		cout << "Child()" << endl;
	}
	~Child()
	{
		cout << "~Child()" << endl;
	}
protected:
private:
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