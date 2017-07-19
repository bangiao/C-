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
		cout << "AES����" << endl;
	}
protected:
private:
};

class Des : public Strategy
{
public:
	virtual void SynEncCrypt()
	{
		cout << "Des����" << endl;
	}
protected:
private:
};

//��Ϲ�ϵ: ���ǹ�������������Ϊ��ϻ��߾ۼ�
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

	puts("�л��㷨");

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