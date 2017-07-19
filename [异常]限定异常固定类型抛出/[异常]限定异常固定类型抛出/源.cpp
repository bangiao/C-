#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test(int a = 0)
	{
		cout << "构造函数" << endl;
		this->a = a;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
private:
	int a;
};

void Div()
{
	Test t1(1), t2(2);
	cout << "要发生异常" << endl;
	throw 1;
}

//不抛出异常
void Div1()	throw()
{
	Test t1(1), t2(2);
	cout << "要发生异常" << endl;
	throw 1;
}

//只能放回所列出来的类型
void Div2()	throw(char, char *, int, int *)
{
	Test t1(1), t2(2);
	cout << "要发生异常" << endl;
	throw 1;
}
//不写, 抛出任何类型的异常
void Div3()
{
	Test t1(1), t2(2);
	cout << "要发生异常" << endl;
	throw 1;
}

int main(int argv, char *args[])
{
	int ret = 0;
	
	
	system("pause");
	return ret;
}