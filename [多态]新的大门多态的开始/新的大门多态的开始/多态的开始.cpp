#include <iostream>
using namespace std;

//多态产生的场景
//1. 继承
//2. 产生了赋值兼容性原则(父类指针指向子类对象 或者 父类引用指向子类对象)
//3. 虚函数重写

//要产生多态的话将要将virtual写到父类中 或者就是参数的类型的类中

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "父类a:" << this->a << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b = 0)
	{
		this->b = b;
	}
	void print()
	{
		cout << "子类b:" << this->b << endl;
	}
protected:
private:
	int b;
};

void howtoprint(Parent *base)
{
	base->print();
}

void howtoprint2(Parent &base)
{
	base.print();
}

int main()
{
	Parent p1;
	p1.print();

	Child c1;
	c1.print();

	Parent *pP = NULL;
	pP = &p1;
	pP->print();

// 	Child *pC = NULL;
// 	pC = &c1;
// 	pC->print();

	//子类是父类 - - - - 子类 = 父类 ? 父类 = 子类 ?
	//pC = &p1;		//p1是父类  子类妄图重生是不可能的
	pP = &c1;		// 父类 = 子类 意为子类 = (是) 父类	意为 子类长大成为父类
	pP->print();

	//引用(别名)
	Parent &p2 = c1;
	p2.print();		//打印出来的是父类的函数print()
	//其实我们真心希望当由子类复制给父类的时候打印出来的是子类的函数
	//由父类赋值的时候打印出来的是父类的函数
	//这时候虚函数出现了 相应的多态也出现了

	howtoprint(&p1);		//因为这里的函数参数的类型是父类所以它会跳到父类 如果virtual写在子类则不会产生多态
	howtoprint(&c1);		//要产生多态的话将要将virtual写到父类中 或者就是参数的类型的类中

	//c++默认是静态编译语言根据类型去响应类的函数
	//静态编译的定义是根据指针的类型去决定类中执行相应的程序
	//而在c++中加入virtual的话那么c++编译器会做手脚 = = = = => 动态链编译
	//c++编译器会来个迟绑定 = = = 同样的一句话能出现多种功能, 多种形态  - - - 这就是动态链编译
	howtoprint2(p1);
	howtoprint2(c1);

	//c1.Parent::print();	//子类访问父类重写的函数 域作用符

	system("pause");
	return 0;
}