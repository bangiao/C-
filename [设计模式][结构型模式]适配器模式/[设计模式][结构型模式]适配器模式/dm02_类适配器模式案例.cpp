#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//Target
//Ŀ��: Target ����ӿ������ Adaptee ���� SpecificRequest 
//���� Target �Ǵ��麯������û��ʵ������(��� Target ���ǳ����൫������ĺ���
//Request�Ѿ���ʵ�������޷�����  Adaptee::SpecificRequest() ���Ա������
//��ʵ�������������е���Ŀ��)
//����ʵ����һ������Ȼ�������麯������ Adaptee �� ���� SpecificRequest
//�ﵽ���� Adaptee::SpecificRequest() Ŀ��
class Target
{
public:
	virtual void Request() = 0;
};

//Adaptee    Ŀ��
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Adaptee::SpecificRequest()" << endl;
	}
};

//Adapter	������
class Adapter : public Target, public Adaptee
{
public:
	virtual void Request()
	{
		Adaptee::SpecificRequest();
	}
};

int main(int argc, char *argv[])
{
	int ret = 0;
	Target *targetObj = new Adapter();
	targetObj->Request();

	delete targetObj;

	
	system("pause");
	return ret;
}