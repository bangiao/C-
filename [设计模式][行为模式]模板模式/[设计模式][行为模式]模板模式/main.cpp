#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//˵���˾��ǳ������в��������ӿ� ������ ����, ������߼�
//ʵ���� c++ �е����� template ģ��
//���ǽ�����������һ��ĺ�������Ϊģ��
class AbsMakeCar
{
protected:
	virtual void MakeHead() = 0;
	virtual void MakeBoby() = 0;
	virtual void MakeTail() = 0;
public :
	//ģ�庯��(����) (�е�������ģʽ�е����ʦ)
	void MakeClass()
	{
		MakeHead();
		MakeBoby();
		MakeTail();
	}
protected:
private:
};

class MakeJeep : public AbsMakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "MakeJeep::MakeHead()" << endl;
	}
	virtual void MakeBoby()
	{
		cout << "MakeJeep::MakeBoby()" << endl;
	}
	virtual void MakeTail()
	{
		cout << "MakeJeep::MakeTail()" << endl;
	}
protected:
private:
};

class MakeBus : public AbsMakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "MakeBus::MakeHead()" << endl;
	}
	virtual void MakeBoby()
	{
		cout << "MakeBus::MakeBoby()" << endl;
	}
	virtual void MakeTail()
	{
		cout << "MakeBus::MakeTail()" << endl;
	}
protected:
private:
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsMakeCar *base = NULL;
	base = new MakeJeep;
	base->MakeClass();

	delete base;
	
	system("pause");
	return ret;
}