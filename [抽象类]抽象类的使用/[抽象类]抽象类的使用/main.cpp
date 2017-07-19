#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//接口类   抽象类
class Figure
{
public:
	virtual double show_area() = 0;
};

class triangle : public Figure
{
public:
	triangle(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}

	double show_area()
	{
		this->area = this->x * this->y / 2;
		return this->area;
	}
protected:
private:
	double x;
	double y;
	double area;
};

class square : public Figure
{
public:
	square(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}
	double show_area()
	{
		this->area = this->x * this->y;
		return this->area;
	}
protected:
private:
	double x;
	double y;
	double area;
};

class circle : public Figure
{
public:
	circle(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double show_area()
	{
		this->area = this->x * this->x * 3.14;
		return this->area;
	}
protected:
private:
	double x;
	double y;
	double area;
};

void whobig(Figure &f1, Figure &f2)
{
	if (f1.show_area() < f2.show_area())
	{
		cout << "f1 big" << endl;
	}
	else if (f1.show_area() == f2.show_area())
	{
		cout << "f1 == f2" << endl;
	}
	else
	{
		cout << "f2 big" << endl;
	}
}

int mainOP()
{
	triangle t1(2, 3);
	square s1(3, 4);
	circle c1(5, 6);

	cout << t1.show_area() << endl;
	cout << s1.show_area() << endl;
	cout << c1.show_area() << endl;
	whobig(t1, s1);
	whobig(c1, t1);
	whobig(s1, c1);
	return 0;
}

int main(int argv, char *args[])
{
	mainOP();
	printf("hello world...\n");
	system("pause");
	return 0;
}