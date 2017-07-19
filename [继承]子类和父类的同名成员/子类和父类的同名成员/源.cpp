#include <iostream>
using namespace std;


class base
{
protected:
	int a;
	int b;

public:
	base(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
};

class Child : public base
{
public:
	Child(int b = 0, int c  =0)
	{
		this->b = b;
		this->c = c;
	}
	void init()
	{
		this->a = 0;
		this->base::b = 1;		//处理方法在这里 格式 base::XX
		this->b = 2;
		this->c = 3;
	}
	void print()
	{
		printf("a = %d, base::b = %d, b = %d, c = %d\n", this->a, this->base::b, this->b, this->c);
	}
protected:
private:
	int b;
	int c;
};

int main()
{
	Child c1;

	c1.init();
	c1.print();

	system("pause");
	return 0;
}