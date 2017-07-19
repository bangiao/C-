#include <iostream>
using namespace std;

class AbsC
{
public:
	AbsC(int a = 0)
	{
		this->a = a;
	}
	virtual int getA()
	{
		return this->a;
	}
private:
	int a;
};

class C : public AbsC
{
public:
	C(int b, int c)
	{
		this->b = b;
		this->c = c;
	}
	virtual int getA()
	{
		return this->b;
	}
protected:
private:
	int b, c;
};

int main(void)
{
	C c(10, 20);

	system("pause");
	return 0;
}