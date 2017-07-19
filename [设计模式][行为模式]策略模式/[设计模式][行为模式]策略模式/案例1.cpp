#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Strategy
{
public:
	virtual void SynEncCrypt() = 0;
};

class AES : public Strategy
{
public:
	virtual void SynEncCrypt()
	{
		cout << "AES加密" << endl;
	}
protected:
private:
};

class Des : public Strategy
{
public:
	virtual void SynEncCrypt()
	{
		cout << "Des加密" << endl;
	}
protected:
private:
};

//组合关系: 既是关联又是依赖则为组合或者聚集
class ConText
{
public:
	ConText(Strategy *base)
	{
		_base = base;
	}
	void Operator()
	{
		_base->SynEncCrypt();
	}
protected:
private:
	Strategy *_base;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	ConText *context = NULL;
	Strategy *strategy = NULL;

	strategy = new AES;
//	strategy->SynEncCrypt();
	context = new ConText(strategy);

	context->Operator();

	delete context;
	context = NULL;
	delete strategy;
	strategy = NULL;

	puts("切换算法");

	strategy = new Des;
	context = new ConText(strategy);

	context->Operator();

	delete context;
	context = NULL;
	delete strategy;
	strategy = NULL;
	
	system("pause");
	return ret;
}