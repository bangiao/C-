#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
using namespace std;

//这个房子的属性要有 墙 门 窗
//要有建房子的方法 被设置出 墙 门 窗等
//要能够 看到墙 门 窗


//对象的表示
////////////////////////////////////////////////
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
	// -  - - -- 
	string getWall()
	{
		return m_wall;
	}
	string getWindow()
	{
		return m_window;
	}
	string getDoor()
	{
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
// 	~FlatBuilder()
// 	{
// 		if (NULL != m_house)
// 		{
// 			delete m_house;
// 		}
// 		m_house = NULL;		//废话 无法将 main 函数中的 house 指向 NULL
// 	}
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
// 	~VillaBuilder()
// 	{
// 		if (NULL != m_house)
// 		{
// 			delete m_house;
// 		}
// 		m_house = NULL;			//废话 无法将 main 函数中的 house 指向 NULL
// 	}
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
class Director   
{
public:
	Director(AbsBuilder *build)
	{
		m_build = build;
	}
	void ConStruct()
	{
		m_build->buildWall();
		m_build->buildWindow();
		m_build->buildDoor();
	}
private:
	AbsBuilder *m_build;
};
////////////////////////////////////////////////

int main01()
{
	int ret = 0;
	House *house = NULL;
	Director *dir = NULL;
	AbsBuilder *BuildBase = NULL;

	BuildBase = new FlatBuilder;
	dir = new Director(BuildBase);
	dir->ConStruct();
	house = BuildBase->getHouse();
	cout << house->getDoor() << endl;
	cout << house->getWall() << endl;
	cout << house->getWindow() << endl;

	delete dir;
	dir = NULL;
	delete BuildBase;
	BuildBase = NULL;
	delete house;
	house = NULL;
	
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	main01();
	
	system("pause");
	return ret;
}