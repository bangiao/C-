#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 抽象类
class AbsSubject
{
public:
	// 纯虚函数
	virtual void saleBook() = 0;
};

// 书店, 被代理者
class RealSubject : public AbsSubject
{
public:
	virtual void saleBook()
	{
		cout << "实体店卖书" << endl;
	}
};
// 当当网, 代理者
class DangDangWang : public AbsSubject
{
public:
	virtual void saleBook()
	{
		real = new RealSubject;
		cout << "当当网代理实体店卖书" << endl;
		Double11();
		real->saleBook();
		delete real;
		real = NULL;
	}
	// 搞双 11 活动
	void Double11()
	{
		cout << "双 11 半折卖书" << endl;
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