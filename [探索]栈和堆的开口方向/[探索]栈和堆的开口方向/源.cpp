#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdlib.h>

int main(int argv, char *args[])
{
	//栈中 
	//先创建的变量地址大			大 ~ 小
	//初步判断栈的地址开头想上
 	int ret = 0;
// 	int ret2 = 0;
// 	int *p1 = &ret;
// 	int *p2 = &ret2;
// 
// 	cout << p1 << endl;
// 	cout << p2 << endl;
// 	cout << &p1 << endl;
// 	cout << &p2 << endl;
	//堆中
	//先定义的越小 开口向下		小 ~ 大
	int *p1 = new int;
	int *p2 = new int;
	int *p3 = new int;
	int *p4 = new int;

	*p1 = ret;
	*p2 = ret;
	*p3 = ret;
	*p4 = ret;

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << p4 << endl;

	delete p1;
	delete p2;
	delete p3;
	delete p4;

	int *p5 = NULL;
	p5 = &ret;
	printf("%p, %d\n", p5, *p5);
	system("pause");
	return ret;
}