#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//只抛出 int char long 类型的异常
void myClass1(int b) throw (int , char , long)
{
	throw 1;
}

//抛出任意类型的异常变量
void myClass2(int a)
{

}

//不抛出任何类型的异常变量
void myClass3(int a) throw () 
{

}

int main(int argv, char *args[])
{
	int ret = 0;
	
	
	system("pause");
	return ret;
}