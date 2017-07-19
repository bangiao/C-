#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// 强制转换的方式, 只允许在父子类之间转化

class A
{
public:
	A(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int age{ 10 };
	string name{ "zhazha" };
};

class B : public A
{
public:
	B(string name, int age) : A(name, age)
	{
		
	}
protected:
private:
};

class C
{
public:
	C(string name, int id)
	{
		this->name = name;
		this->id = id;
	}
protected:
private:
	int id{0};
	string name{"商品"};
};

int main(void)
{
// 	A a("人", 100);
// 	C c("苹果", 3);
// 	
// 	A *p = new A("zhazha", 100);
// 	// 不同类型无法强转
// 	// p = static_cast<A *>(&c);
// 
// 	B b = B("男人", 23333);
// 
// 	// 子类可以转化成父类
// 	A *p1 = static_cast<A *>(&b);
// 
// 	cout << p1->name.c_str() << " " << p1->age << endl;
// 
// 	// 父类可以转化成子类???
// 	B * p2 = static_cast<B *>(&a);
// 
// 	cout << p2->name.c_str() << " " << p2->age << endl;


	int a = 10;
	double d = 3.30;

	int c = static_cast<int>(d);
	d = static_cast<double>(a);


	cout << c << " " << d << endl;

	system("pause");
	return 0;
}