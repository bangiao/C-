#include <iostream>
using namespace std;
//定义和声明
class A
{
public:
	A()
	{
		//cout << &b << endl;
	}
// 	void mm()
// 	{
// 		cout << &b << "::" << b << endl;
// 	}
	int a;
	static int b;
protected:
private:
};

class B : public A
{
public:
	B()
	{
		//cout << &b << endl;
	}
// 	void mm()
// 	{
// 		cout << &b << "::" << b << endl;
// 	}
	int c;
	static int b;
protected:
private:
};

// int A::b = 0;
// int B::b = 1;

int main()
{
	B a1;
	a1.mm();

	system("pause");
	return 0;
}
