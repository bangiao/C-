#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// ǿ��ת���ķ�ʽ, ֻ�����ڸ�����֮��ת��

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
	string name{"��Ʒ"};
};

int main(void)
{
// 	A a("��", 100);
// 	C c("ƻ��", 3);
// 	
// 	A *p = new A("zhazha", 100);
// 	// ��ͬ�����޷�ǿת
// 	// p = static_cast<A *>(&c);
// 
// 	B b = B("����", 23333);
// 
// 	// �������ת���ɸ���
// 	A *p1 = static_cast<A *>(&b);
// 
// 	cout << p1->name.c_str() << " " << p1->age << endl;
// 
// 	// �������ת��������???
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