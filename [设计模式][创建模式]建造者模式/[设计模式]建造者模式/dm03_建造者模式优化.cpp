#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//������ӵ�����Ҫ�� ǽ �� ��
//Ҫ�н����ӵķ��� �����ó� ǽ �� ����
//Ҫ�ܹ� ����ǽ �� ��


//����ı�ʾ
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
	~FlatBuilder()
	{
		if (NULL != m_house)
		{
			delete m_house;
		}
		m_house = NULL;		//�ϻ� �޷��� main �����е� house ָ�� NULL
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

//����������
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
		m_house = NULL;			//�ϻ� �޷��� main �����е� house ָ�� NULL
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

//���ʦ��һ�������Ŷ�
////////////////////////////////////////////////
//��ƽ�������ν�����
//��ƺõķ�����ȥ��house
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

//	��Ӧ�ò���û���� new house ����ΪʲôҪ��ȥ delete
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