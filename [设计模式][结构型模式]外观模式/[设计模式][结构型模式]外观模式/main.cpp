#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SubSystemA
{
public:
	void dothing()
	{
		cout << "SubSystemA::dothing()" << endl;
	}
protected:
private:
};

class SubSystemB
{
public:
	void dothing()
	{
		cout << "SubSystemB::dothing()" << endl;
	}
protected:
private:
};

class SubSystemC
{
public:
	void dothing()
	{
		cout << "SubSystemC::dothing()" << endl;
	}
protected:
private:
};

class Facade
{
public:
	Facade()
	{
		this->A = new SubSystemA;
		this->B = new SubSystemB;
		this->C = new SubSystemC;
	}

	~Facade()
	{
		if (NULL != this->A)
		{
			delete this->A;
		}
		if (NULL != this->B)
		{
			delete this->B;
		}
		if (NULL != this->C)
		{
			delete this->C;
		}
	}

public :
	void dothing()
	{
		this->A->dothing();
		this->B->dothing();
		this->C->dothing();
	}
protected:
private:
	SubSystemA *A;
	SubSystemB *B;
	SubSystemC *C;
};

//ԭ���Ŀͻ���
//��æ�Ŀͻ�
int main01()
{
	int ret = 0;
	
	SubSystemA *A = new SubSystemA;
	SubSystemB *B = new SubSystemB;
	SubSystemC *C = new SubSystemC;

	delete C;
	delete B;
	delete A;

	return ret;
}

//���е�ҵ��Ա
int main02()
{
	int ret = 0;
	Facade *base = NULL;
	base = new Facade;		//�������һ�� this ָ��Ĳ���
	base->dothing();			//������������������� this ָ��� �����this ָ���ַ��ͬ
	delete base;
	return ret;
}


int main(int argc, char *argv[])
{
	int ret = 0;
//	main01();
	main02();
	system("pause");
	return ret;
}