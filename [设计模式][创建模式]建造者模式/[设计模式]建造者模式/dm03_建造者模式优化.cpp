#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//这个房子的属性要有 墙 门 窗
//要有建房子的方法 被设置出 墙 门 窗等
//要能够 看到墙 门 窗


//对象的表示
////////////////////////////////////////////////
/*
class AbsHouse
{
public:
AbsHouse(){}
virtual ~AbsHouse(){}
virtual void setWall(string wall) = 0;
virtual void setWindow(string window) = 0;
virtual void setDoor(string door) = 0;
// -  - - --
virtual string getWall() = 0;
virtual string getWindow() = 0;
virtual string getDoor() = 0;
protected:
string m_door;
string m_wall;
string m_window;
};
*/
class House
{
public:
	void setWall(string wall)
	{
		m_wall = wall;
	}
	void setWindow(string window)
	{
		m_window = window;
	}
	void setDoor(string door)
	{
		m_door = door;
	}
	// - - - - - 
public:
	string getWall()
	{
		cout << m_wall << endl;
		return m_wall;
	}
	string getWindow()
	{
		cout << m_window << endl;
		return m_window;
	}
	string getDoor()
	{
		cout << m_door << endl;
		return m_door;
	}

protected:
private:
	string m_door;
	string m_wall;
	string m_window;
};
////////////////////////////////////////////////

//建筑师的职责是:
//建墙 门 窗
//建哪种房子 别墅 平房 公寓

//对象的构建
////////////////////////////////////////////////
class AbsBuilder
{
public:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;
	virtual House *getHouse() = 0;
	virtual ~AbsBuilder(){}
};

//公寓建造者
class FlatBuilder : public AbsBuilder
{
public:
	FlatBuilder()
	{
		this->m_house = new House;
	}
	~FlatBuilder()
	{
		if (NULL != m_house)
		{
			delete m_house;
		}
		m_house = NULL;		//废话 无法将 main 函数中的 house 指向 NULL
	}
	virtual void buildWall()
	{
		m_house->setWall("FlatBuilder wall");
	}

	virtual void buildDoor()
	{
		m_house->setDoor("FlatBuilder door");
	}

	virtual void buildWindow()
	{
		m_house->setWindow("FlatBuilder window");
	}
	virtual House * getHouse()
	{
		return m_house;
	}

private:
	House *m_house;
};

//别墅建造者
class VillaBuilder : public AbsBuilder
{
public:
	VillaBuilder()
	{
		this->m_house = new House;
	}
	~VillaBuilder()
	{
		if (NULL != m_house)
		{
			delete m_house;
		}
		m_house = NULL;			//废话 无法将 main 函数中的 house 指向 NULL
	}
	virtual void buildWall()
	{
		m_house->setWall("VillaBuilder wall");
	}

	virtual void buildDoor()
	{
		m_house->setDoor("VillaBuilder door");
	}

	virtual void buildWindow()
	{
		m_house->setWindow("VillaBuilder window");
	}
	virtual House * getHouse()
	{
		return m_house;
	}
private:
	House *m_house;
};
////////////////////////////////////////////////

//设计师有一个建筑团队
////////////////////////////////////////////////
//设计建筑队如何建房子
//设计好的房子拿去给house
class AbsDirector
{
public:
	AbsDirector(AbsBuilder *build = NULL)
	{
		m_build = build;
	}
	virtual void ConStruct() = 0;
	virtual House *getHouse() = 0;

protected:
	AbsBuilder *m_build;
};

class Director : public AbsDirector
{
public:
	Director(AbsBuilder *build) : AbsDirector(build)
	{
		;
	}
	virtual void ConStruct()
	{
		cout << "Director work" << endl;
		m_build->buildWall();
		m_build->buildDoor();
		m_build->buildWindow();
	}
	virtual House *getHouse()
	{
		return this->m_build->getHouse();
	}
};

class advDirector : public AbsDirector
{
public:
	advDirector(AbsBuilder *build) : AbsDirector(build)
	{
		;
	}
	~advDirector(){}
	virtual void ConStruct()
	{
		cout << "advDirector work" << endl;
		m_build->buildWall();
		m_build->buildWindow();
		m_build->buildDoor();
	}
	virtual House *getHouse()
	{
		return this->m_build->getHouse();
	}
};
////////////////////////////////////////////////

int mainOP()
{
	int ret = 0;
	AbsBuilder *buBase = NULL;
	AbsDirector *dirBase = NULL;
	House *house = NULL;

	buBase = new VillaBuilder;

	dirBase = new advDirector(buBase);

	dirBase->ConStruct();
	house = dirBase->getHouse();

	house->getDoor();
	house->getWall();
	house->getWindow();

//	我应用层有没看到 new house 所以为什么要我去 delete
// 	delete house;
// 	house = NULL;
	delete dirBase;
	dirBase = NULL; 
	delete buBase;
	buBase = NULL;
	house = NULL;


	buBase = new FlatBuilder;
	dirBase = new Director(buBase);

	dirBase->ConStruct();

	house = dirBase->getHouse();

	house->getDoor();
	house->getWall();
	house->getWindow();

	delete dirBase;
	dirBase = NULL;
	delete buBase;
	buBase = NULL;
	house = NULL;

	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	mainOP();

	system("pause");
	return ret;
}