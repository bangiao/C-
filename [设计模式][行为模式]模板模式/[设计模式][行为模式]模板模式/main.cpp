#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//说白了就是抽象类中不仅方法接口 还放了 方法, 程序的逻辑
//实则不是 c++ 中的那种 template 模板
//而是将方法集合在一起的函数被叫为模板
class AbsMakeCar
{
protected:
	virtual void MakeHead() = 0;
	virtual void MakeBoby() = 0;
	virtual void MakeTail() = 0;
public :
	//模板函数(方法) (有点像建造者模式中的设计师)
	void MakeClass()
	{
		MakeHead();
		MakeBoby();
		MakeTail();
	}
protected:
private:
};

class MakeJeep : public AbsMakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "MakeJeep::MakeHead()" << endl;
	}
	virtual void MakeBoby()
	{
		cout << "MakeJeep::MakeBoby()" << endl;
	}
	virtual void MakeTail()
	{
		cout << "MakeJeep::MakeTail()" << endl;
	}
protected:
private:
};

class MakeBus : public AbsMakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "MakeBus::MakeHead()" << endl;
	}
	virtual void MakeBoby()
	{
		cout << "MakeBus::MakeBoby()" << endl;
	}
	virtual void MakeTail()
	{
		cout << "MakeBus::MakeTail()" << endl;
	}
protected:
private:
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsMakeCar *base = NULL;
	base = new MakeJeep;
	base->MakeClass();

	delete base;
	
	system("pause");
	return ret;
}