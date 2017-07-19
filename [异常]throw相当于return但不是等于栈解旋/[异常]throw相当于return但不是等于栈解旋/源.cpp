//栈解旋是一种语法现象
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
protected:
private:
	int a;
	int b;
};

//这个函数的throw会调用析构函数
void devide()
{
	Test t1(1, 2), t2(3, 4);
	throw 1;					//throw相当于return 但不是 return  return 是不能夸函数返回的但是 throw可以
}


int main(int argv, char *args[])
{
	int ret = 0;
	
	try
	{
		devide();
	}
	catch (int e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "未知错误" << endl;
	}
	system("pause");
	return ret;
}