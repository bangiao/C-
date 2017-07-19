#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

/*
class Mediator
{
public:
void setWoman(AbsPerson *woman)
{
_woman = woman;
}
void setMan(AbsPerson *man)
{
_man = man;
}
void  getParent()
{
if (_woman->getSex() == _man->getSex())
{
cout << ""
}
}
protected:
private:
AbsPerson *_woman;
AbsPerson *_man;
};
*/

class AbsPerson
{
public:
	AbsPerson(string name, int sex, int condi)
	{
		this->name = name;
		this->sex = sex;
		this->condi = condi;
	}
	string getName()
	{
		return this->name;
	}
	int getSex()
	{
		return this->sex;
	}
	int getCondi()
	{
		return this->condi;
	}

	virtual bool getParent(AbsPerson *base) = 0;

protected:
	string name;
	int sex;
	int condi;
};


class Woman : public AbsPerson
{
public:
	Woman(string name, int sex, int condi) : AbsPerson(name, sex, condi)
	{

	}
	virtual bool getParent(AbsPerson *base)
	{
		if (this->sex == base->getSex())
		{
			cout << "不匹配" << endl;
			return false;
		}
		if (this->condi == base->getCondi())
		{
			cout << this->getName() << base->getName() << "匹配" << endl;
			return true;
		}
		else
		{
			cout << this->getName() << base->getName() << "不匹配" << endl;
			return false;
		}
	}
};

class Man : public AbsPerson
{
public:
	Man(string name, int sex, int condi) : AbsPerson(name, sex, condi)
	{

	}
	virtual bool getParent(AbsPerson *base)
	{
		if (this->sex == base->getSex())
		{
			cout << "不匹配" << endl;
			return false;
		}
		if (this->condi == base->getCondi())
		{
			cout << this->getName() << base->getName() << "匹配" << endl;
			return true;
		}
		else
		{
			cout << this->getName() << base->getName() << "不匹配" << endl;
			return false;
		}
	}
};


int main01()
{
	int ret = 0;
	AbsPerson *womanbase = NULL;
	AbsPerson *manbase1 = NULL;
	AbsPerson *manbase2 = NULL;

	womanbase = new Woman("小芳", 2, 5);
	manbase1 = new Man("张三", 1, 4);
	manbase2 = new Man("李四", 1, 5);

	womanbase->getParent(manbase1);
	womanbase->getParent(manbase2);
	
	return ret;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main01();
	system("pause");
	return ret;
}