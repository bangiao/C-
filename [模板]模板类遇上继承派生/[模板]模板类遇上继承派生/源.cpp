#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//通常有用到类名的地方一般都要加上<typename>(类型参数列表)
//Such as:
//有用到模板类的类名中 AA 的地方都有加上 <typename>(类型参数列表)
//这样用的原因是 模板类是个抽象类还没有实体

template <class T>
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "printA()" << endl;
		cout << this->a << endl;
	}
protected:
	T a;
};

//要派生出一个子类的话需要告诉编译器你派生的是什么数据类型的类
//更深的探究是 c++编译器要知道派生的父类具体的内存是多少
//因为只有固定的数据内存才能知道如何分配内存
class BB : public AA<int>		//告诉编译器已什么样的情势继承父类AA
{
public:
	BB(int a, int b) : AA<int>(a)
	{
		cout << "printB()" << endl;
		this->b = b;
	}
	void printB()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
protected:
	int b;
};

int main(int argv, char *args[])
{
	AA<int> a(11);
	a.printA();

	BB b(22, 33);
	b.printB();
	printf("hello world...\n");
	system("pause");
	return 0;
}