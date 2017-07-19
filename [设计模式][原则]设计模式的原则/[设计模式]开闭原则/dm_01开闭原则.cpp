#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����ԭ��:
//�����¼�(ϸ��)���
//��æ������Ա����

//�����ӵ���ʽ�϶�����
//���ڼ����µ�Ԫ�ص�ʱ��Ҫ�� BankWorker ������޸�����������ǲ�����
//��Ϊÿ�ζ�Ҫ�޸ĵĻ��Ƚ��鷳

//�������������:
//��Ա�������ɽӿ��� virtual void dothing() = 0
//����� ����Ա����Ҫ����ʱ����һ��һ���¼���
//���罫ת������һ������ ����Ϊ BankWorker �������������е�Ա��
//��Ҫ���µ������ʱ���ֻҪ���µĹ���д���¼��� ��������
//���м̳о����� �����޸����Ա������ֻҪ������¼��൱������
//���м̳�Ա���������



//��æ������Ա
class BankWorker
{
public:
	void save()			//���
	{
		cout << "save" << endl;
	}
	void transform()	//ת��
	{
		cout << "transform" << endl;
	}
	void business()		//����
	{
		cout << "business" << endl;
	}
};

//�������޸�
//���ɵ�����Ա
//�ӿ�
class AbsBankWorker
{
public:
	virtual void dothing() = 0;
};

class transform : public AbsBankWorker
{
public:
	virtual void dothing()
	{
		cout << "transform" << endl;
	}
};

class advtransform : public transform
{
public:
	virtual void dothing()
	{
		cout << "advtransform" << endl;
	}
};

class business : public AbsBankWorker
{
public:
	virtual void dothing()
	{
		cout << "business" << endl;
	}
};

class save : public AbsBankWorker
{
public:
	virtual void dothing()
	{
		cout << "save" << endl;
	}
};

int main01()
{
	int ret = 0;
	BankWorker *bw = NULL;
	bw = new BankWorker;

	bw->save();
	bw->business();
	bw->transform();

	delete bw;
	return ret;
}

int main02()
{
	AbsBankWorker *wb = NULL;
	wb = new save;
	wb->dothing();
	delete wb;

	wb = new transform;
	wb->dothing();
	delete wb;
	wb = NULL;

	wb = new advtransform;
	wb->dothing();
	delete wb;
	wb = NULL;
	return 0;
}

int main11(int argc, char *argv[])
{
	int ret = 0;
//	main01();
	main02();
	system("pause");
	return ret;
}