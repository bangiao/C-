#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AbsFurit
{
public:
	virtual void getFurit() = 0;
};

class AbsFactroy
{
public:
	virtual AbsFurit *setApple() = 0;
	virtual AbsFurit *setPear() = 0;
};

class NorthApple : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "NorthApple" << endl;
	}
};

class NorthPear : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "NorthPear" << endl;
	}
};

class SouthApple : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "SouthApple" << endl;
	}
};

class SouthPear : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "SouthPear" << endl;
	}
};

class SouthFactroy : public AbsFactroy
{
public:
	virtual SouthApple *setApple()
	{
		return new SouthApple;
	}
	virtual SouthPear *setPear()
	{
		return new SouthPear;
	}
};


class NorthFactroy : public AbsFactroy
{
public:
	virtual NorthApple *setApple()
	{
		return new NorthApple;
	}
	virtual NorthPear *setPear()
	{
		return new NorthPear;
	}
};

void HowDoApple(AbsFactroy *&FacBase, AbsFurit *&FurBase)
{
	FurBase = FacBase->setApple();
	FurBase->getFurit();
}


// typedef AbsFurit *(*FUNC)();
// void HowDoFunc(AbsFactroy *&FacBase, AbsFurit *&FurBase)
// {
// 	FurBase = FacBase->setApple();
// 	FurBase->getFurit();
// }


void DeleteClass(AbsFactroy *&FacBase, AbsFurit *&FurBase)
{
	if (NULL != FurBase)
	{
		delete FurBase;
		FurBase = NULL;
	}
	if (NULL != FurBase)
	{
		delete FacBase;
		FacBase = NULL;
	}
}

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsFactroy *FacBase = NULL;
	AbsFurit *FurBase = NULL;
	
	FacBase = new NorthFactroy;
	HowDoApple(FacBase, FurBase);
	DeleteClass(FacBase, FurBase);
	
	
	system("pause");
	return ret;
}