#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//简单工厂模式不是标准的设计模式
//因为不符合高内聚的也就是 开闭原则   面向事件(细节)编程
//比如我现在要加入新的水果 Pear 梨子 这样子的话 要修改类 Factroy 这样是不符合开闭原则的
//因为修改类的话这个类有可能出现新的业务或逻辑问题, 这样是不好的
//加入新的模块比如 Pear 是要修改某个函数的内部 这是不符合设计模式的原则的
class AbsFurit
{
public:
	virtual void getFurit() = 0;
};

class Banana : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "I'm Banana" << endl;
	}
};

class Apple : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "I'm Apple" << endl;
	}
};

//这里不符合开闭原则(面向事件编程)
class Factroy
{
public:
	AbsFurit *setFurit(char *name)
	{
		//事件
		if ("apple" == name)
		{
			return new Apple;
		}
		//事件
		else if ("banana" == name)
		{
			return new Banana;
		}
		//事件   - - - - - 没分开 不符合 面向事件编程
		else
		{
			return NULL;
		}
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Factroy *fac = NULL;
	AbsFurit *FuritBase = NULL;
	
	fac = new Factroy;
	FuritBase = fac->setFurit("banana");
	FuritBase->getFurit();

	delete FuritBase;

	FuritBase = fac->setFurit("apple");
	FuritBase->getFurit();

	delete FuritBase;

	delete fac;

	system("pause");
	return ret;
}