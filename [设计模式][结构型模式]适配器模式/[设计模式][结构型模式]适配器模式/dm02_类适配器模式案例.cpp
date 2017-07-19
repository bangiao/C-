#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//Target
//目的: Target 这个接口想调用 Adaptee 函数 SpecificRequest 
//但是 Target 是纯虚函数所以没有实例对象(这个 Target 不是抽象类但是这里的函数
//Request已经被实现所以无法调用  Adaptee::SpecificRequest() 所以必须借助
//它实例的子类对象进行调用目的)
//所以实例化一个对象然后对象的虚函数调用 Adaptee 的 函数 SpecificRequest
//达到调用 Adaptee::SpecificRequest() 目的
class Target
{
public:
	virtual void Request() = 0;
};

//Adaptee    目标
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Adaptee::SpecificRequest()" << endl;
	}
};

//Adapter	适配器
class Adapter : public Target, public Adaptee
{
public:
	virtual void Request()
	{
		Adaptee::SpecificRequest();
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Target *targetObj = new Adapter();
	targetObj->Request();

	delete targetObj;

	
	system("pause");
	return ret;
}