#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ������
class AbsSubject
{
public:
	// ���麯��
	virtual void saleBook() = 0;
};

// ���, ��������
class RealSubject : public AbsSubject
{
public:
	virtual void saleBook()
	{
		cout << "ʵ�������" << endl;
	}
};
// ������, ������
class DangDangWang : public AbsSubject
{
public:
	virtual void saleBook()
	{
		real = new RealSubject;
		cout << "����������ʵ�������" << endl;
		Double11();
		real->saleBook();
		delete real;
		real = NULL;
	}
	// ��˫ 11 �
	void Double11()
	{
		cout << "˫ 11 ��������" << endl;
	}
private:
	RealSubject *real;
};

int main(int argc, char *argv[])
{
	int ret = 0;
	AbsSubject *ddw = NULL;
	ddw = new DangDangWang;

	ddw->saleBook();

	delete ddw;
	ddw = NULL;
	
	system("pause");
	return ret;
}