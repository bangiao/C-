#include <iostream>
using namespace std;
//1. �ȹ���ĺ�����
//2. �̳��й��캯�������ȹ������(����)Ȼ��������(������)  û�и������ж���
//���������ʱ, ��Ҫ���ø���Ĺ��캯�����й���
//�����������ʱ, ��Ҫ���ø������ĸ��������������������
class Parent
{
public:
	Parent(const char *s)
	{
		cout << "Parent ()" << endl;
	}
	Parent()
	{
		cout << "Parent ()" << endl;
	}
	~Parent()
	{
		cout << "~Parent()" << endl;
	}
protected:
private:
};

class Child : Parent
{
public:
	Child() : Parent("aaaaaaaaaa")
	{
		cout << "Child()" << endl;
	}
	~Child()
	{
		cout << "~Child()" << endl;
	}
protected:
private:
};

void run32()
{
	Child c1;
}

int main()
{
	run32();
	system("pause");
	return 0;
}