#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//开闭原则:
//面向事件(细节)编程
//繁忙的银行员案例

//这样子的形式肯定不好
//它在加入新的元素的时候要将 BankWorker 类进行修改这个很明显是不行了
//因为每次都要修改的话比较麻烦

//所以做如下设计:
//将员工类做成接口类 virtual void dothing() = 0
//将这个 银行员工索要做的时候变成一个一个事件类
//比如将转账做成一个子类 父类为 BankWorker 这样如果这个银行的员工
//需要做新的事情的时候就只要将新的功能写成事件类 做成子类
//进行继承就行了 不用修改这个员工的类只要将这个事件类当成子类
//进行继承员工类就行了



//繁忙的银行员
class BankWorker
{
public:
	void save()			//存款
	{
		cout << "save" << endl;
	}
	void transform()	//转账
	{
		cout << "transform" << endl;
	}
	void business()		//交易
	{
		cout << "business" << endl;
	}
};

//作如下修改
//轻松的银行员
//接口
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