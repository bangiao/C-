#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//这个就是 依赖倒置原则
//发动机
class AbsEngine
{
public:
	//给汽车调用
	virtual void installEngine() = 0;
};

class Engine4000cc : public AbsEngine
{
public:
	virtual void installEngine()
	{
		cout << "install Engine4000cc success" << endl;
	}
};

class Engine4500cc : public AbsEngine
{
public:
	virtual void installEngine()
	{
		cout << "install Engine4500cc success" << endl;
	}
};


//根据原则:
//父类的属性有父类的构造函数初始化
//子类的属性有子类的构造函数初始化

//抽象类:
//是将有共同属性和方法的抽象成一个类, 但是无法描述具体的对象
class AbsCar
{
public:
	//所以这里存在构造函数
	AbsCar(AbsEngine *engine)
	{
		m_engine = engine;
	}
	virtual void CarinstallEngine()
	{
		m_engine->installEngine();
	}

protected:
	//属性
	AbsEngine *m_engine;
};

class BM5 : public AbsCar
{
public:
	BM5(AbsEngine *m_engine) : AbsCar(m_engine){}
};

class BM6 : public AbsCar
{
public:
	BM6(AbsEngine *m_engine) : AbsCar(m_engine){}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsCar *CarBase = NULL;
	AbsEngine *EnBase = NULL;

	EnBase = new Engine4000cc;
	CarBase = new BM5(EnBase);
	CarBase->CarinstallEngine();

	delete CarBase;
	CarBase = NULL;
	delete EnBase;
	EnBase = NULL;

// 	EnBase = new Engine4500cc;
// 	CarBase = new BM5(EnBase);
// 	CarBase->CarinstallEngine();
// 	
// 	
// 	delete CarBase;
// 	CarBase = NULL;
// 	delete EnBase;
// 	EnBase = NULL;

	system("pause");
	return ret;
}