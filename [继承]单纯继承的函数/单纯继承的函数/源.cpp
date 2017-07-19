#include <iostream>
using namespace std;

void func()
{
	cout << " aaaa" << endl;
}

void func(int i)
{
	cout << i << endl;
}

void func(int i, double j)
{
	cout << i << j << endl;
}

void func(double i, int j)
{
	cout << i << j << endl;
}

int main()
{
	int i = 0;
	double j = 1;

	func(i, j);
	func(j, i);
	func(i);
	system("pause");
	return 0;
}



// #include <iostream>
// using namespace std;
// 
// class Parent
// {
// public:
// 	Parent()
// 	{
// 		cout << "Parent():printf()...do" << endl;
// 	}
// 	void fun()
// 	{
// 		cout << "Parent:void fun()" << endl;
// 	}
// 	void fun(int i)
// 	{
// 		cout << "Parent():void fun(int i)" << endl;
// 	}
// 
// 	void fun(int i, int j)
// 	{
// 		cout << "Parent():void fun(int i, int j) " << endl;
// 	}
// };
// 
// class Child : public Parent
// {
// public:
// 	void fun(int i, int j)
// 	{
// 		cout << "Child():void fun(int i, int j) " << endl;
// 	}
// };
// 
// int main()
// {
// //	Parent p1;
// 	Child c;
// //	c.fun();
// // 	c.fun(1, 2);
// // 	p1.fun(1, 2);
// 	system("pause");
// 	return 0;
// }