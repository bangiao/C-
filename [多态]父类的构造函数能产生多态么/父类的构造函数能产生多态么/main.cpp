#include <iostream>
using namespace std;

//类中只要有virtual就会产生虚函数指针vptr指针并且产生两个vptr指针 一个在父类 一个在子类
//当对象没有产生时vptr指针未被初始化
//当父类对象构造函数执行时 两个vptr指针将会同时指向父类的产生的地址
//当子类对象构造函数执行时子类的vptr指针将被指向子类地址

class AA
{
public:
	AA(int a = 1)
	{
		//printf("sizeof(a1):%d\n", sizeof(*this));
		this->a = a;
	}
	virtual void print()
	{
		cout << "父类a:" << a << endl;
	}
protected:
	int a;
};

class BB : public AA
{
public:
	BB(int a = 2, int b = 3)
	{
		this->a = a;
		this->b = b;
		print();
	}
	void print()
	{
		cout << "子类a:" << a << endl;
		cout << "子类b:" << b << endl;
	}
protected:
	int b;
};
int main()
{
// 	printf("sizeof(AA):%d\n", sizeof(AA));
// 	printf("sizeof(BB):%d\n", sizeof(BB));

	//AA a1;
	BB b1;
	b1.print();
	system("pause");
	return 0;
}
