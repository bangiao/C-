#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//函数模版存在严格的类型机制 不存在任何的隐式转换
template <class T, class C>
void MySwap(T &a, C &b)
{
	T tmp = 0;
	tmp = (T)a;
	a = b;
	b = (C)tmp;
}

void MySwap(int &a, char &b)
{
	int tmp = 0;
	tmp = (char)a;
	a = b;
	b = (char)tmp;
}

int main(int argv, char *args[])
{
	int a = 10;
	char b = 'z';
	MySwap(a, b);				//当函数没有参数类型列表的时候默认调用重载的函数
	MySwap(b, a);
	MySwap<int, char>(a, b);	//当函数存在类型参数列表的时候这个时候调用模版函数
	printf("hello world...\n");
	system("pause");
	return 0;
}