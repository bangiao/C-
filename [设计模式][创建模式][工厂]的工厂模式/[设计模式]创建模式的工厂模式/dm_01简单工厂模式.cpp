#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//�򵥹���ģʽ���Ǳ�׼�����ģʽ
//��Ϊ�����ϸ��ھ۵�Ҳ���� ����ԭ��   �����¼�(ϸ��)���
//����������Ҫ�����µ�ˮ�� Pear ���� �����ӵĻ� Ҫ�޸��� Factroy �����ǲ����Ͽ���ԭ���
//��Ϊ�޸���Ļ�������п��ܳ����µ�ҵ����߼�����, �����ǲ��õ�
//�����µ�ģ����� Pear ��Ҫ�޸�ĳ���������ڲ� ���ǲ��������ģʽ��ԭ���
class AbsFurit
{
public:
	virtual void getFurit() = 0;
};

class Banana : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "I'm Banana" << endl;
	}
};

class Apple : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "I'm Apple" << endl;
	}
};

//���ﲻ���Ͽ���ԭ��(�����¼����)
class Factroy
{
public:
	AbsFurit *setFurit(char *name)
	{
		//�¼�
		if ("apple" == name)
		{
			return new Apple;
		}
		//�¼�
		else if ("banana" == name)
		{
			return new Banana;
		}
		//�¼�   - - - - - û�ֿ� ������ �����¼����
		else
		{
			return NULL;
		}
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Factroy *fac = NULL;
	AbsFurit *FuritBase = NULL;
	
	fac = new Factroy;
	FuritBase = fac->setFurit("banana");
	FuritBase->getFurit();

	delete FuritBase;

	FuritBase = fac->setFurit("apple");
	FuritBase->getFurit();

	delete FuritBase;

	delete fac;

	system("pause");
	return ret;
}