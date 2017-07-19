#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
using namespace std;
//电脑组装
//对象的表示
////////////////////////////////////////////////////////////
class Computer
{
public:
	//看零件
	string getCpu()
	{
		return m_cpu;
	}
	string getDisk()
	{
		return m_disk;
	}
	string getMemory()
	{
		return m_memory;
	}
	//被设置零件
	void setCpu(string cpu)
	{
		m_cpu = cpu;
	}
	void setDisk(string disk)
	{
		m_disk = disk;
	}
	void setMemory(string memory)
	{
		m_memory = memory;
	}
private:
	string m_cpu;
	string m_disk;
	string m_memory;
};
////////////////////////////////////////////////////////////



//对象构建
////////////////////////////////////////////////////////////
//由谁来组装
class AbsBuilder
{
public:
	virtual void buildCpu() = 0;
	virtual void buildDisk() = 0;
	virtual void buildMemory() = 0;
	virtual Computer *getComputer() = 0;

};

class HWBuilder : public AbsBuilder
{
public:
	HWBuilder()
	{
		m_computer = new Computer;
	}
	virtual void buildCpu()
	{
		m_computer->setCpu("HWBuilder Intercpu");
	}
	virtual void buildDisk()
	{
		m_computer->setDisk("HWBuilder SDDisk");
	}
	virtual void buildMemory()
	{
		m_computer->setMemory("HWBuilder SDMeory");
	}
	virtual Computer *getComputer()
	{
		return m_computer;
	}

private:
	Computer *m_computer;
};

class LXBuilder : public AbsBuilder
{
public:
	LXBuilder(Computer *computer)
	{
		m_computer = computer;
	}
	virtual void buildCpu()
	{
		m_computer->setCpu("LXBuilder AMDcpu");
	}
	virtual void buildDisk()
	{
		m_computer->setDisk("LXBuilder JSDDisk");
	}
	virtual void buildMemory()
	{
		m_computer->setMemory("LXBuilder HKSTMeory");
	}
	virtual Computer *getComputer()
	{
		return m_computer;
	}

private:
	Computer *m_computer;
};
////////////////////////////////////////////////////////////

//主人来计划整个组装过程
class Director
{
public:
	Director(AbsBuilder *BuBase)
	{
		m_BuBase = BuBase;
	}
	void ConStruct()
	{
		m_BuBase->buildCpu();
		m_BuBase->buildDisk();
		m_BuBase->buildMemory();
	}
private:
	AbsBuilder *m_BuBase;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Director *director = NULL;
	AbsBuilder *BuBase = NULL;
	Computer *computer = NULL;

	BuBase = new HWBuilder;
	director = new Director(BuBase);
	director->ConStruct();
	computer = BuBase->getComputer();

	cout << computer->getCpu() << endl;
	cout << computer->getDisk() << endl;
	cout << computer->getMemory() << endl;
	delete computer;
	delete director;
	delete BuBase;
	computer = NULL;
	director = NULL;
	BuBase = NULL;
	
	system("pause");
	return ret;
}