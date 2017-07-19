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
			cout << "�Ա𲻷���" << endl;
		}
		else if (base1->getCondi() == base2->getCondi())
		{
			cout << base1->getName() << " ƥ�� " << base2->getName() << endl;
		}
		else
		{
			cout << base1->getName() << " ��ƥ�� " << base2->getName() << endl;
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

	m1 = new Man("����", 1, 4, mediator);
	m2 = new Man("����", 1, 5, mediator);
	w1 = new Woman("С��", 2, 5, mediator);

	//������������� getParent() ������ ? ����
	mediator->setDoubleHuman(m1, m2);
	mediator->getParent();
	//������з������ú�?
	m1->getParent(w1);
	m2->getParent(w1);

	delete w1;
	delete m2;
	delete m1;
	delete mediator;
	
	system("pause");
	return ret;
}