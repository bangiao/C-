#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Mediator;

class AbsPerson
{
public:
	AbsPerson(string name, int sex, int glamour)
	{
		this->_name = name;
		this->_sex = sex;
		this->_glamour = glamour;
	}
public:
	virtual void getParent(AbsPerson *base) = 0;
public:
	string getName()
	{
		return _name;
	}
	int getSex()
	{
		return _sex;
	}
	int getCondi()
	{
		return _glamour;
	}
protected:
	string _name;
	int _sex;
	int _glamour;
	Mediator *_mediator;
};

class Mediator
{
public:
	void setDoubleHuman(AbsPerson *base1, AbsPerson *base2)
	{
		this->base1 = base1;
		this->base2 = base2;
	}
	void getParent()
	{
		if (base1->getSex() == base2->getSex())
		{
			cout << "性别不符合" << endl;
		}
		else if (base1->getCondi() == base2->getCondi())
		{
			cout << base1->getName() << " 匹配 " << base2->getName() << endl;
		}
		else
		{
			cout << base1->getName() << " 不匹配 " << base2->getName() << endl;
			return;
		}
		return;
	}
protected:
	AbsPerson *base1;
	AbsPerson *base2;
};

class Woman : public AbsPerson
{
public:
	Woman(string name, int sex, int glamour, Mediator *mediator) : AbsPerson(name, sex, glamour)
	{
		this->_mediator = mediator;
	}
	virtual void getParent(AbsPerson *base)
	{
		_mediator->setDoubleHuman(this, base);
		_mediator->getParent();
	}
};

class Man : public AbsPerson
{
public:
	Man(string name, int sex, int glamour, Mediator *mediator) : AbsPerson(name, sex, glamour)
	{
		this->_mediator = mediator;
	}
	virtual void getParent(AbsPerson *base)
	{
		_mediator->setDoubleHuman(this, base);
		_mediator->getParent();
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Mediator *mediator = NULL;
	AbsPerson *m1 = NULL, *m2 = NULL, *w1 = NULL;

	mediator = new Mediator;

	m1 = new Man("张三", 1, 4, mediator);
	m2 = new Man("李四", 1, 5, mediator);
	w1 = new Woman("小芳", 2, 5, mediator);

	//用这个方法调用 getParent() 方法好 ? 还是
	mediator->setDoubleHuman(m1, m2);
	mediator->getParent();
	//用这个中方法调用好?
	m1->getParent(w1);
	m2->getParent(w1);

	delete w1;
	delete m2;
	delete m1;
	delete mediator;
	
	system("pause");
	return ret;
}