#include <iostream>
using namespace std;

//定义一个抽象类:存在纯虚函数的类叫抽象类
//用于继承的类  不可以定义对象 当作普通的参数
//可以用于实现多态 比如 定义一个抽象类的指针或者引用 进行赋值兼容性原则
class figure
{
public:
	virtual void show_area() = 0;
protected:
	double x;
	double y;
private:
};

class triangle : public figure
{
public:
	triangle(double x = 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout << "三角形的面积:" << x*y*0.5 << endl;
	}
};

class square : public figure
{
public:
	square(double x = 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout << "四边形的面积:" << x*y << endl;
	}
};

class circle : public figure
{
public:
	circle(double x = 1)
	{
		this->x = x;
	}
	void show_area()
	{
		cout << "圆的面积:" << 3.14*x*x << endl;
	}
};

class test : public figure
{
public:
	test(double x = 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	//这里注释掉后的话 那么 相当于 继承了 virtual void show_area() = 0;
	//这个类同样无法定义对象  应为他也是抽象类
// 	void show_area()
// 	{
// 		cout << "四边形的面积:" << x*y << endl;
// 	}
};


void run_show(figure &pBase)
{
	pBase.show_area();
}

int main()
{
	triangle t1;
	square s1;
	circle c1;
	//test t2;

	run_show(t1);
	run_show(s1);
	run_show(c1);
	
	system("pause");
	return 0;
}