#include <iostream>
using namespace std;

class person
{
public:
	person()
	{
		cout << "���๹�캯��person()" << endl;
	}

	virtual ~person()		//������
	{
		cout << "��������������" << endl;
	}
	virtual void print() = 0;
protected:
private:
};

class Child : public person
{
public:
	Child(int a = 0)
	{
		this->a = a;
		cout << "���๹�캯��Child()" << endl;
	}

	~Child()
	{
		cout << "��������������" << endl;
	}
	void print()
	{
		cout << this->a << endl;
	}
protected:
private:
	int a;
};

void howtoprint(person *pBase)
{
	pBase->print();
	delete pBase;
}

int main()
{
	Child *c1 = new Child(1);
	howtoprint(c1);
	system("pause");
	return 0;
}