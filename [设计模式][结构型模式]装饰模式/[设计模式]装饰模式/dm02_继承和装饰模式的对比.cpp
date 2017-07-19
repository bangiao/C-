#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AbsCar
{
public:
	virtual void work() = 0;

};

class RunCar : public AbsCar
{
public:
	virtual void work()
	{
		cout << "Car Run" << endl;
	}
};

class SwimCar : public RunCar
{
public:
	void Swim()
	{
		cout << "the Car Swim" << endl;
	}
	virtual void work()
	{
		this->RunCar::work();
		Swim();
	}
};

class FlyCar : public SwimCar
{
public:
	void Fly()
	{
		cout << "the Car Fly" << endl;
	}
	virtual void work()
	{
		this->SwimCar::work();
		Fly();
	}
};

class BoomCar : public FlyCar
{
public:
	void Boom()
	{
		cout << "the Car Boom" << endl;
	}
	virtual void work()
	{
		this->FlyCar::work();
		Boom();
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsCar *base1 = NULL;
	AbsCar *base2 = NULL;
	AbsCar *base3 = NULL;
	AbsCar *base4 = NULL;

	base1 = new RunCar;
	base1->work();
	puts("==============================\n");

	base2 = new SwimCar;
	base2->work();
	puts("==============================\n");
	
	base3 = new FlyCar;
	base3->work();
	puts("==============================\n");

	base4 = new BoomCar;
	base4->work();
	puts("==============================\n");

	delete base4;
	delete base3;
	delete base2;
	delete base1;

	
	system("pause");
	return ret;
}