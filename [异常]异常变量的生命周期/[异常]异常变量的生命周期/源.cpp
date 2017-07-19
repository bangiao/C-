#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test()
	{
		cout << "构造函数" << endl;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
	Test(const Test &obj)
	{
		cout << "拷贝构造函数" << endl;
	}
};

void dowork(char *from, char *to)
{
	Test t1;							//第一次构造函数
	if ('a' == *from)
	{
		throw Test();					//第二次构造函数  是构造匿名对象  然后进行拷贝构造函数 
		//将匿名对象拷贝过去
	}
	if ('\b' == *from)
	{
		throw new Test();
	}
	while (*from != '\0')
	{
		*from++ = *to++;
	}
}

int main1()
{
	int ret = 0;
	
	char *from = "abcde";
	char to[6];
	try
	{
		dowork(from, to);
	}
	catch (Test e)
	{
		cout << "typename:Test e" << endl;
	}
// 	catch (Test &e)						//得知异常元素和异常元素的引用不可以同时存在
// 	{//不会产生拷贝构造函数
// 		cout << "typename:Test &e" << endl;
// 	}
	catch (Test *e)
	{
		cout << "typename:Test *e" << endl;
		delete e;
	}
	catch (...)
	{
		cout << "is unknow" << endl;
	}
	return ret;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main1();
	system("pause");
	return ret;
}