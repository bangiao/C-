#include <iostream>
using namespace std;

/*
函数的重载
1, 函数的名字相同
2, 函数的返回值不是重载的条件\
3, 函数参数的顺序
4, 函数参数的类型
5, 函数参数的数量
6, 必须发生在同一个作用域当中  (例如一个类, 或者观看 { 这个就是一个作用域  }  )
*/

/*
函数的重写
1, 函数的的名字必须相同
2, 函数的返回值必须相同
3, 函数的参数必须相同
4, 必须发生在子类与父类之间
5, 必须有virtual关键字
*/

class Parent
{
public:
	Parent()
	{
		cout << "Parent():printf()...do" << endl;
	}
	void fun()
	{
		cout << "Parent:void fun()" << endl;
	}
	virtual void fun(int i)
	{
		cout << "Parent():void fun(int i)" << endl;
	}

	virtual void fun(int i, int j)
	{
		cout << "Parent():void fun(int i, int j) " << endl; 
	}
};

class Child : public Parent
{
public:
	void fun(int i, int j)
	{
		cout << "Child():void fun(int i, int j) " << endl;
	}

	void fun(int i, int j, int k)
	{
		cout << "Child():void fun(int i, int j, int k)" << endl;
	}
};

void run32(Parent &p)
{
	p.fun(1, 2);
}

int main()
{
	Parent a;

	a.fun();
	a.fun(1);
	a.fun(1, 2);

	Child c;
	//c.fun();		//注意  这里是函数的重载
	//c.fun(1);		//这个和上面的一样
	c.Parent::fun();
	c.Parent::fun(1);

	//c.fun(1, 2);	//这个是函数的重写 产生多态
	
// 	int a1 = 0;
// 	int *p1 = &a1;
// 	int *&p = p1;
// 
// 	printf("a1:%d\n", a1);
// 	printf("*p1:%d\n", *p1);
// 	printf("*p:%d\n", *p);
	system("pause");
	return 0;
}