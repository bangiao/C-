#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//函数重载: 存在于同一个作用域中才能产生函数的重载
//函数的重写: 函数的重写存在于不同的类中  如果有virtual的话则产生多态没有的话则发生  函数的重定义 
class Parent
{
public:
	virtual void func()
	{

	}
	virtual void func(int i)
	{

	}
	virtual void func(int i, int j)
	{

	}
protected:
private:
};

class Child : public Parent
{
public:
	void func(int i, int j)
	{

	}
	void func(int i, int j, int k)
	{

	}//这两个是函数重载
protected:
private:
};

int main(int argv, char *args[])
{
	Child c1;
//	c1.func(1);	
	//c++编译器发现子类中有相关函数所以只会在子类中查找函数
	//这里这个func(int i) 是在父类中的函数但是子类中没有这个函数   没有重载函数接受 1 个参数
	//这个时候如果子类中没有相同名字的函数的时候子类是可以调用的但是此时子类中存在func同名函数
	//产生函数的重定义 所以此时c++提示
	c1.Parent::func(1);
	c1.func(1, 2);//这是虚函数重写产生多态
	printf("hello world...\n");
	system("pause");
	return 0;
}