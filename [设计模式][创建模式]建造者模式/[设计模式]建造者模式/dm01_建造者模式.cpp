#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
using namespace std;

//������ӵ�����Ҫ�� ǽ �� ��
//Ҫ�н����ӵķ��� �����ó� ǽ �� ����
//Ҫ�ܹ� ����ǽ �� ��


//����ı�ʾ
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

//����ʦ��ְ����:
//��ǽ �� ��
//�����ַ��� ���� ƽ�� ��Ԣ

//����Ĺ���
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

//��Ԣ������
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
// 		m_house = NULL;		//�ϻ� �޷��� main �����е� house ָ�� NULL
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

//����������
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
// 		m_house = NULL;			//�ϻ� �޷��� main �����е� house ָ�� NULL
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

//���ʦ��һ�������Ŷ�
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