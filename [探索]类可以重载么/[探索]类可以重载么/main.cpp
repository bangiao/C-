#include <iostream>
using namespace std;

//不可以  但是 模板类是怎么实现的???
// class Person
// {
// public:
// 	Person()
// 	{
// 
// 	}
// protected:
// 	int a;
// };
// 
// class Person
// {
// public:
// 	Person()
// 	{
// 
// 	}
// protected:
// 	double a;
// };

template <class T>
class Person
{
public:
	Person(T a)
	{
		this->a = a;
	}
protected:
	T a;
};

int main(int argv, char *args[])
{
	Person<int> a1(1);
	Person<double> a2(1.0001);
	//其原理是什么???
	system("pause");
	return 0;
}