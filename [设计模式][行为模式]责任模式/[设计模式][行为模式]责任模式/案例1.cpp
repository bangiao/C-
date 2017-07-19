#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����ģʽ: ���ǽ�����һ��һ����������ȥ
//�ͱ��繤������ˮ��һ��, һ�����괫����һ��

class AbsHandleCar
{
public:
	virtual void makeCar() = 0;
	void setHandleCar(AbsHandleCar *basehandlecar)
	{
		_BaseHandleCar = basehandlecar;
	}
protected:
	AbsHandleCar *_BaseHandleCar;
private:
};

class MakeCarHead : public AbsHandleCar
{
public:
	virtual void makeCar()
	{
		cout << "make Car Head" << endl;
		if (NULL != _BaseHandleCar)
		{
			_BaseHandleCar->makeCar();
		}
	}
};

class MakeCarBody : public AbsHandleCar
{
public:
	virtual void makeCar()
	{
		cout << "make Car Body" << endl;
		if (NULL != _BaseHandleCar)
		{
			_BaseHandleCar->makeCar();
		}
	}
};

class MakeCarTail : public AbsHandleCar
{
public:
	virtual void makeCar()
	{
		cout << "make Car Tail" << endl;
		if (NULL != _BaseHandleCar)
		{
			_BaseHandleCar->makeCar();
		}
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsHandleCar *CarHead = NULL;
	AbsHandleCar *CarBody = NULL;
	AbsHandleCar *CarTail = NULL;

	CarHead = new MakeCarHead;
	CarBody = new MakeCarBody;
	CarTail = new MakeCarTail;

	CarHead->setHandleCar(CarBody);
	CarBody->setHandleCar(CarTail);
	CarTail->setHandleCar(NULL);

	CarHead->makeCar();


	delete CarTail;
	CarTail = NULL;
	delete CarBody;
	CarBody = NULL;
	delete CarHead;
	CarHead = NULL;

	system("pause");
	return ret;
}