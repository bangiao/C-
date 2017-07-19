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

class SwimCar : public AbsCar
{
public:
	SwimCar(AbsCar *Car)
	{
		this->m_Car = Car;
	}
	void Swim()
	{
		cout << "the Car Swim" << endl;
	}
	virtual void work()
	{
		m_Car->work();
		Swim();
	}
private:
	AbsCar *m_Car;//关联
};

class FlyCar : public AbsCar
{
public:
	FlyCar(AbsCar *Car)
	{
		this->m_Car = Car;
	}
	void Fly()
	{
		cout << "the Car Fly" << endl;
	}

	virtual void work()
	{
		m_Car->work();
		Fly();
	}
protected:
private:
	AbsCar *m_Car;//关联
};

class BoomCar : public AbsCar
{
public:
	BoomCar(AbsCar *Car)
	{
		this->m_Car = Car;
	}
	void Boom()
	{
		cout << "the Car Boom" << endl;
	}

	virtual void work()
	{
		m_Car->work();
		Boom();
	}
protected:
private:
	AbsCar *m_Car;//关联
};

int main01()
{
	int ret = 0;
	AbsCar *CarBase1 = NULL;
	AbsCar *CarBase2 = NULL;
	AbsCar *CarBase3 = NULL;
	AbsCar *CarBase4 = NULL;

	CarBase1 = new RunCar;

	CarBase1->work();

	puts("====================\n");

	CarBase2 = new SwimCar(CarBase1);
	CarBase2->work();

	puts("====================\n");

	CarBase3 = new FlyCar(CarBase2);
	CarBase3->work();

	puts("====================\n");

	CarBase4 = new BoomCar(CarBase3);
	CarBase4->work();

	puts("====================\n");

	delete CarBase4;
	delete CarBase3;
	delete CarBase2;
	delete CarBase1;
	
	return ret;
}


//无效的
int main02()
{
	//这个函数需要个子类编写复制构造函数
	int ret = 0;
	AbsCar &base1 = RunCar();		//AbsCar = RunCar;   产生多态
	base1.work();
	puts("====================\n");
	AbsCar &base2 = base1;			//AbsCar = RunCar;   产生多态
	base2.work();
	puts("====================\n");

	AbsCar &base3 = base2;			//AbsCar = RunCar;   产生多态
	base3.work();
	puts("====================\n");
	
	return ret;
}

int main03()
{
	int ret = 0;
	AbsCar &base1 = RunCar();
	base1.work();
	puts("====================\n");

	AbsCar &base2 = SwimCar(&base1);
	base2.work();
	puts("====================\n");

	AbsCar &base3 = FlyCar(&base2);
	base3.work();
	puts("====================\n");

	AbsCar &CarBase4 = BoomCar(&base3);
	CarBase4.work();
	puts("====================\n");

	return ret;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main01();
//	main02();
//	main03();
	system("pause");
	return ret;
}