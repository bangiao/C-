#include <iostream>
using namespace std;

int Max(int a, int b)
{
	return (a > b ? a : b);
}

int Max(int a, int  b, int c)
{
	return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

template <class T>
T Max(T a, T b)
{
	return (a > b ? a : b);
}

template <class T>
T Max(T a, T b, T c)
{
	return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

int print(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	cout << Max(1, 2) << endl;	//当模版函数和普通函数都合适的时候一般使用 普通函数
	cout << Max<>(1, 2) << endl;	//当使用空模版是 强制调用模版函数
	cout << Max<float>(1, 2) << endl;//当强制转换的时候变量a和变量b会被强制转换成该类型
	cout << Max<float>('a', 'h') << endl;

	cout << Max(1, 'a') << endl;	//当普通函数参数调用的类型不符合是c++编译器会适量做出调整 char变成int int变成char
									//但是模版函数却无法实现这个功能
	print(1, 'b');					//普通函数都存在这个能力

	cout << Max('a', 'b') << endl;			//当普通函数的两个参数都需要进行上面的那个转换时优先考虑模版

	cout << Max(1.0, 2.0) << endl;	//直接调用模版函数
	system("pause");
	return 0;
}