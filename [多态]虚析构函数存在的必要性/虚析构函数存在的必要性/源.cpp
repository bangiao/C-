#include <iostream>
using namespace std;

class person
{
public:
	person()
	{
		cout << "父类构造函数person()" << endl;
	}

	virtual ~person()		//虚析构
	{
		cout << "父类虚析构函数" << endl;
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
		cout << "子类构造函数Child()" << endl;
	}

	~Child()
	{
		cout << "子类虚析构函数" << endl;
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