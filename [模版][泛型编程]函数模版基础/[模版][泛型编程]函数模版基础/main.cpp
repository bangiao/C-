#include <iostream>
using namespace std;

class person
{
public:
	int a, b;
	person(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
protected:
private:
};

void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void swap(float &a, float &b)
{
	float tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//template 是告诉c++编译器, 现在开始泛型编程
//typename 是告诉c++编译器,  T 是数据类型(而且是任意复杂数据类型) 请不要乱报错
template <typename T>
void swap2(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename P>
void swap3(P &a, P &b)
{
	P c;
	c.a = a.a;
	a.a = b.a;
	b.a = c.a;
	c.b = a.b;
	a.b = b.b;
	b.b = c.b;
}
int main()
{
	//泛型编程的调用方式有两种
	int a = 1;
	int b = 2;
	swap(a, b);
	//1. 自动类型调用
	swap2(a, b);

	float a1 = 1, b1 = 2;
	swap(a1, b1);
	swap2(a1, b1);

	double a2 = 1, b2 = 2;
	//2. 具体类型调用
	swap2<double>(a2, b2);
	person p1(1, 2), p2(3, 4);

	swap3(p1, p2);
	system("pause");
	return 0;
}