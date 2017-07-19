#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string"
using namespace std;
//原型模式
//就是让一个复杂的类具有复制的能力
class AbsPerson
{
public:
	virtual AbsPerson *clone() = 0;
	virtual void print() = 0;
};

class cPlusPlusprogrammer : public AbsPerson
{
public:
	cPlusPlusprogrammer()
	{
		this->m_age = 0;
		this->m_name = "";
	}
	cPlusPlusprogrammer(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
	virtual AbsPerson *clone()
	{
		cPlusPlusprogrammer *tmp = new cPlusPlusprogrammer;
		*tmp = *this;
		return tmp;
	}
	virtual void print()
	{
		cout << "name: " << m_name << "  age: " << m_age << endl;
	}
private:
	string m_name;
	int m_age;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsPerson *PerBase = NULL;
	AbsPerson *PerBase2 = NULL;

	PerBase = new cPlusPlusprogrammer("lin", 21);
	PerBase->print();
	PerBase2 = PerBase->clone();
	PerBase2->print();

	delete PerBase2;
	delete PerBase;
	system("pause");
	return ret;
}