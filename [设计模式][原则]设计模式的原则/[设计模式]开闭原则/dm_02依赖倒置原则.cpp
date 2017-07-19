#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//依赖倒置原则:
//就是面向接口编程(抽象类编程)

//甲乙 或者 甲
//这个是一个接口, 是由甲乙两公司共同定义的一个协议(业有可能是单个公司定义的一个接口)
//接口协议层
////////////////////////////////////////////////////////
class AbsCpu
{
public:
	virtual void work() = 0;
};

class AbsHardDisk
{
public:
	virtual void work() = 0;
};

class AbsMemory
{
public:
	virtual void work() = 0;
};


//乙
//这下面的子类是由乙公司写的子类
//根据接口来写的
//都是根据抽象类进行编码的
class InterCpu : public AbsCpu
{
public:
	virtual void work()
	{
		cout << "InterCpu work" << endl;
	}
};

class XSHardDisk : public AbsHardDisk
{
public:
	virtual void work()
	{
		cout << "XSHardDisk work" << endl;
	}
};

class JSDMemory : public AbsMemory
{
public:
	virtual void work()
	{
		cout << "JSDMemory work" << endl;
	}
};

//甲
///////////////////////////////////////////////////////
//这个 Computer 是甲公司写的框架
//根据接口的定义来进行编写
//假设子类不存在 都是根据抽象类进行编码的
class Computer
{
public:
	Computer(AbsCpu *Cpu, AbsHardDisk *HardDisk, AbsMemory *Memory)
	{
		m_Cpu = Cpu;
		m_HardDisk = HardDisk;
		m_Memory = Memory;
	}
	void work()
	{
		m_Cpu->work();
		m_HardDisk->work();
		m_Memory->work();
	}
private:
	AbsCpu *m_Cpu;
	AbsHardDisk *m_HardDisk;
	AbsMemory *m_Memory;
};

//甲
//甲公司的业务层
//也是根据接口编写的代码
//子类已经存在, 根据抽象类进行编码的
int main(int argc, char *argv[])
{
	int ret = 0;
	AbsCpu *Cpu = NULL;
	AbsHardDisk *HardDisk = NULL;
	AbsMemory *Memory = NULL;

	//这里也可以把它写成一个函数或者类, 把它编程经常修改的类或者函数
/////////////////////////////////////////////////////
	Cpu = new InterCpu;
	HardDisk = new XSHardDisk;
	Memory = new JSDMemory;
/////////////////////////////////////////////////////

	Computer *computer = new Computer(Cpu, HardDisk, Memory);

	computer->work();
	//专门写一个销毁的函数, 也可以将其加入一个类中
/////////////////////////////////////////////////////
	delete computer;
	delete Memory;
	delete HardDisk;
	delete Cpu;
/////////////////////////////////////////////////////
	
	system("pause");
	return ret;
}