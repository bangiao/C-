#include <iostream>
using namespace std;

class person
{
public:
	person(char *name = "Tom")
	{
		int len = strlen(name) + 1;
		this->name = new char[32];
		memcpy(this->name, name, len);
	}
	void print()
	{
		cout << this->name << endl;
	}
	~person()
	{
		if (NULL != this->name)
		{
			delete[]this->name;
		}
	}
private:
	char *name;
};

person func()
{
	person A("zzzz");
	return A;
}

int mainOP1()
{
	person p1("zhazha");
	person p2("kangkang");

	p1 = p2;

	p1.print();
	p2.print();

	return 0;
}

int mainOP2()
{
	person A = func();
	A.print();
	return 0;
}

int main()
{
//	mainOP1();
	mainOP2();
	system("pause");
	return 0;
}