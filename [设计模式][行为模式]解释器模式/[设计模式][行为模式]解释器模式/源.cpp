#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class ConText
{
public:
	ConText(int num)
	{
		this->num = num;
	}
	int getNum()
	{
		return num;
	}
	int getRes()
	{
		return res;
	}
	void setNum(int num)
	{
		this->num = num;
	}
	void setRes(int res)
	{
		this->res = res;
	}
private:
	int num;
	int res;
};

class Expression
{
public:
	virtual void interpreter(ConText *context) = 0;
	virtual void print() = 0;
protected:
	ConText *context;
};

class PlusExpression : public Expression
{
public:
	virtual void interpreter(ConText *context)
	{
		int num = 0;
		num = context->getNum();
		num++;
		context->setNum(num);
		context->setRes(num);
		this->context = context;
	}
	virtual void print()
	{
		cout << "num:" << this->context->getNum() << " res:" << this->context->getRes() << endl;
	}
};

class MinusExpression : public Expression
{
public:
	virtual void interpreter(ConText *context)
	{
		int num = 0;
		num = context->getNum();
		num--;
		context->setNum(num);
		context->setRes(num);
		this->context = context;
	}
	virtual void print()
	{
		cout << "num:" << this->context->getNum() << " res:" << this->context->getRes() << endl;
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	ConText *context = NULL;
	Expression *expression = NULL;

	context = new ConText(10);

	expression = new PlusExpression;

	expression->interpreter(context);

	expression->print();

	delete expression;
	expression = NULL;
	delete context;
	context = NULL;

	context = new ConText(99);
	expression = new MinusExpression;
	expression->interpreter(context);
	expression->print();

	delete expression;
	expression = NULL;
	delete context;
	context = NULL;

	
	system("pause");
	return ret;
}