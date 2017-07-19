#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//������� ��������ԭ��
//������
class AbsEngine
{
public:
	//����������
	virtual void installEngine() = 0;
};

class Engine4000cc : public AbsEngine
{
public:
	virtual void installEngine()
	{
		cout << "install Engine4000cc success" << endl;
	}
};

class Engine4500cc : public AbsEngine
{
public:
	virtual void installEngine()
	{
		cout << "install Engine4500cc success" << endl;
	}
};


//����ԭ��:
//����������и���Ĺ��캯����ʼ��
//���������������Ĺ��캯����ʼ��

//������:
//�ǽ��й�ͬ���Ժͷ����ĳ����һ����, �����޷���������Ķ���
class AbsCar
{
public:
	//����������ڹ��캯��
	AbsCar(AbsEngine *engine)
	{
		m_engine = engine;
	}
	virtual void CarinstallEngine()
	{
		m_engine->installEngine();
	}

protected:
	//����
	AbsEngine *m_engine;
};

class BM5 : public AbsCar
{
public:
	BM5(AbsEngine *m_engine) : AbsCar(m_engine){}
};

class BM6 : public AbsCar
{
public:
	BM6(AbsEngine *m_engine) : AbsCar(m_engine){}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsCar *CarBase = NULL;
	AbsEngine *EnBase = NULL;

	EnBase = new Engine4000cc;
	CarBase = new BM5(EnBase);
	CarBase->CarinstallEngine();

	delete CarBase;
	CarBase = NULL;
	delete EnBase;
	EnBase = NULL;

// 	EnBase = new Engine4500cc;
// 	CarBase = new BM5(EnBase);
// 	CarBase->CarinstallEngine();
// 	
// 	
// 	delete CarBase;
// 	CarBase = NULL;
// 	delete EnBase;
// 	EnBase = NULL;

	system("pause");
	return ret;
}