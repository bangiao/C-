#include <iostream>
using namespace std;

class HeroFighter
{
public:
	virtual int HeroPower()		//多态产生的第二个条件 存在重写函数的虚函数
	{
		return 10;
	}
};

class EnmeyFighter
{
public:
	int EnemyPower()
	{
		return 15;
	}
};

class HeroAdvFighter : public HeroFighter
{
public:
	int HeroPower()		//多态的第一个条件 有两个函数名字返回值和参数一样的函数各自在父类和子类中并产生了重写
	{
		return 20;
	}
};

void ObjFighter(HeroFighter &h1, EnmeyFighter &e1)	//多态形成条件3 产生的赋值兼容性原则
{
	if (h1.HeroPower() > e1.EnemyPower())
	{
		cout << "主角赢了" << endl;
	}
	else if (h1.HeroPower() == e1.EnemyPower())
	{
		cout << "平局" << endl;
	}
	else
	{
		cout << "主角输了" << endl;
	}
}

int main()
{
	HeroFighter h1;
	EnmeyFighter e1;
	HeroAdvFighter h2;

	ObjFighter(h1, e1);
	ObjFighter(h2, e1);
	system("pause");
	return 0;
}