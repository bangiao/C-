#include <iostream>
using namespace std;

class HeroFighter
{
public:
	virtual int HeroPower()		//��̬�����ĵڶ������� ������д�������麯��
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
	int HeroPower()		//��̬�ĵ�һ������ �������������ַ���ֵ�Ͳ���һ���ĺ��������ڸ���������в���������д
	{
		return 20;
	}
};

void ObjFighter(HeroFighter &h1, EnmeyFighter &e1)	//��̬�γ�����3 �����ĸ�ֵ������ԭ��
{
	if (h1.HeroPower() > e1.EnemyPower())
	{
		cout << "����Ӯ��" << endl;
	}
	else if (h1.HeroPower() == e1.EnemyPower())
	{
		cout << "ƽ��" << endl;
	}
	else
	{
		cout << "��������" << endl;
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