#include <iostream>
using namespace std;
#include "list"

class Vendor
{
public:
	void sailbanana()
	{
		cout << "卖香蕉" << endl;
	}
	void sailapple()
	{
		cout << "卖苹果" << endl;
	}
};

class Command
{
public:
	virtual void sail() = 0;
};

class BananaCommand : public Command
{
public:
	BananaCommand(Vendor *v)
	{
		m_v = v;
	}
	Vendor *getV(Vendor *v)
	{
		return m_v;
	}

	void setV(Vendor *v)
	{
		m_v = v;
	}
	virtual void sail()
	{
		m_v->sailbanana();
	}
protected:
private:
	Vendor *m_v;
};

class AppleCommand : public Command
{
public:
	AppleCommand(Vendor *v)
	{
		m_v = v;
	}
	Vendor *getV(Vendor *v)
	{
		return m_v;
	}

	void setV(Vendor *v)
	{
		m_v = v;
	}
	virtual void sail()
	{
		m_v->sailapple();
	}
protected:
private:
	Vendor *m_v;
};

class Waiter
{
public:
	Command *getCommand()
	{
		return m_command;
	}
	void setCommand(Command *c)
	{
		m_command = c;
	}
	void sail()
	{
		m_command->sail();
	}
protected:
private:
	Command *m_command;
};

class AdvWaiter
{
public:
	AdvWaiter()
	{
		m_list = new list<Command *>;
		m_list->resize(0);
	}
	~AdvWaiter()
	{
		delete m_list;
	}
	void setCommands(Command *c)
	{
		m_list->push_back(c);
	}
	list<Command *> * getCommands()
	{
		return m_list;
	}
	void sail()
	{
		for (list<Command *>::iterator it = m_list->begin(); it != m_list->end(); it++)
		{
			(*it)->sail();
		}
	}
protected:
private:
	list<Command *> *m_list;
};

//小商贩 直接 卖 水果
void main25_01()
{
	Vendor *v = new Vendor;
	v->sailapple();
	v->sailbanana();

	delete v;
	return;
}

//小商贩 通过命令 卖 水果
void main25_02()
{
	Vendor *v = new Vendor;
	AppleCommand *ac = new AppleCommand(v);
	ac->sail();

	BananaCommand *bc = new BananaCommand(v);
	bc->sail();

	delete bc;
	delete ac;
	delete v;
}

//小商贩 通过waiter 卖 水果
void main25_03()
{
	Vendor *v = new Vendor;
	AppleCommand *ac = new AppleCommand(v);
	BananaCommand *bc = new BananaCommand(v);

	Waiter *w = new Waiter;
	w->setCommand(ac);
	w->sail();

	w->setCommand(bc);
	w->sail();

	delete w;
	delete bc;
	delete ac;
	delete v;
}

//小商贩 通过advwaiter 批量下单 卖水果
void main25_04()
{
	Vendor *v = new Vendor;
	AppleCommand *ac = new AppleCommand(v);
	BananaCommand *bc = new BananaCommand(v);

	AdvWaiter *w = new AdvWaiter;
	w->setCommands(ac);
	w->setCommands(bc);
	w->sail();

	delete w;
	delete bc;
	delete ac;
	delete v;
}

void main()
{
	//main25_01();
	//main25_02();
	//main25_03();
	main25_04();
	system("pause");
}