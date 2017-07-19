#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//简单工厂模式不是标准的设计模式
//因为不符合高内聚的也就是 开闭原则
//加入新的模块比如 Pear 是要修改某个函数的内部 这是不符合设计模式的原则的




//接口
/////////////////////////////////////////////////////////
//这里已经成为一个架构 不用再次修改

//符合单一职责原则(一个类一个功能)
//符合接口隔离原则(一个接口只提供一种功能)
class AbsFurit
{
public:
	virtual void getFurit() = 0;
};
//这里已经成为一个架构 不用再次修改
class AbsFactroy
{
public:
		//依赖原则
	virtual AbsFurit *setFurit() = 0;
};

//这里已经成为一个架构 不用再次修改
void HowDo(AbsFactroy *&FacBase, AbsFurit *&FurBase)
{
	FurBase = FacBase->setFurit();
	FurBase->getFurit();
}
//这里已经成为一个架构 不用再次修改
void DelClass(AbsFurit *&FurBase, AbsFactroy *&FacBase)
{
	if (NULL != FurBase)
	{
		delete FurBase;
		FurBase = NULL;
	}
	if (NULL != FacBase)
	{
		delete FacBase;
		FacBase = NULL;
	}
}

/////////////////////////////////////////////////////////

//符合面向接口编程(依赖倒置原则)

//符合单一职责原则(一个类一个功能)

//水果子类
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

//工厂子类
//香蕉工厂
class BananaFactroy : public AbsFactroy
{
public:
	virtual Banana *setFurit()
	{
		return new Banana;
	}
};

//苹果工厂
class AppleFactroy : public AbsFactroy
{
public:
	virtual Apple *setFurit()
	{
		return new Apple;
	}
};

//符合面向事件编程(开闭原则)
//这里原本没有 梨子 的这里新加的梨子类
class Pear : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "I'm Pear" << endl;
	}
};
//这里原本没有 梨子 的这里新加的梨子工厂类
class PearFactroy : public AbsFactroy
{
public:
	virtual Pear *setFurit()
	{
		return new Pear;
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	//迪米特法则(多态法则)
	
	//里氏替换原则(基类可以被子类代替)(不理解)
	AbsFactroy *fac = NULL;
	AbsFurit *FuritBase = NULL;

	fac = new BananaFactroy;
	HowDo(fac, FuritBase);
	DelClass(FuritBase, fac);

	fac = new AppleFactroy;
	HowDo(fac, FuritBase);
	DelClass(FuritBase, fac);

	fac = new PearFactroy;
	HowDo(fac, FuritBase);
	DelClass(FuritBase, fac);

	system("pause");
	return ret;
}