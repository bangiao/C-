#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//�򵥹���ģʽ���Ǳ�׼�����ģʽ
//��Ϊ�����ϸ��ھ۵�Ҳ���� ����ԭ��
//�����µ�ģ����� Pear ��Ҫ�޸�ĳ���������ڲ� ���ǲ��������ģʽ��ԭ���




//�ӿ�
/////////////////////////////////////////////////////////
//�����Ѿ���Ϊһ���ܹ� �����ٴ��޸�

//���ϵ�һְ��ԭ��(һ����һ������)
//���Ͻӿڸ���ԭ��(һ���ӿ�ֻ�ṩһ�ֹ���)
class AbsFurit
{
public:
	virtual void getFurit() = 0;
};
//�����Ѿ���Ϊһ���ܹ� �����ٴ��޸�
class AbsFactroy
{
public:
		//����ԭ��
	virtual AbsFurit *setFurit() = 0;
};

//�����Ѿ���Ϊһ���ܹ� �����ٴ��޸�
void HowDo(AbsFactroy *&FacBase, AbsFurit *&FurBase)
{
	FurBase = FacBase->setFurit();
	FurBase->getFurit();
}
//�����Ѿ���Ϊһ���ܹ� �����ٴ��޸�
void DelClass(AbsFurit *&FurBase, AbsFactroy *&FacBase)
{
	if (NULL != FurBase)
	{
		delete FurBase;
		FurBase = NULL;
	}
	if (NULL != FacBase)
	{
		delete FacBase;
		FacBase = NULL;
	}
}

/////////////////////////////////////////////////////////

//��������ӿڱ��(��������ԭ��)

//���ϵ�һְ��ԭ��(һ����һ������)

//ˮ������
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

//��������
//�㽶����
class BananaFactroy : public AbsFactroy
{
public:
	virtual Banana *setFurit()
	{
		return new Banana;
	}
};

//ƻ������
class AppleFactroy : public AbsFactroy
{
public:
	virtual Apple *setFurit()
	{
		return new Apple;
	}
};

//���������¼����(����ԭ��)
//����ԭ��û�� ���� �������¼ӵ�������
class Pear : public AbsFurit
{
public:
	virtual void getFurit()
	{
		cout << "I'm Pear" << endl;
	}
};
//����ԭ��û�� ���� �������¼ӵ����ӹ�����
class PearFactroy : public AbsFactroy
{
public:
	virtual Pear *setFurit()
	{
		return new Pear;
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	//�����ط���(��̬����)
	
	//�����滻ԭ��(������Ա��������)(�����)
	AbsFactroy *fac = NULL;
	AbsFurit *FuritBase = NULL;

	fac = new BananaFactroy;
	HowDo(fac, FuritBase);
	DelClass(FuritBase, fac);

	fac = new AppleFactroy;
	HowDo(fac, FuritBase);
	DelClass(FuritBase, fac);

	fac = new PearFactroy;
	HowDo(fac, FuritBase);
	DelClass(FuritBase, fac);

	system("pause");
	return ret;
}