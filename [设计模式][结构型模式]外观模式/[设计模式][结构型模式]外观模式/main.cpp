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

//原来的客户端
//繁忙的客户
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

//悠闲的业务员
int main02()
{
	int ret = 0;
	Facade *base = NULL;
	base = new Facade;		//这里会有一个 this 指针的产生
	base->dothing();			//但是在析构函数里面的 this 指针和 这里的this 指针地址不同
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