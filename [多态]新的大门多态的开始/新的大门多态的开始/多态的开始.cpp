#include <iostream>
using namespace std;

//��̬�����ĳ���
//1. �̳�
//2. �����˸�ֵ������ԭ��(����ָ��ָ��������� ���� ��������ָ���������)
//3. �麯����д

//Ҫ������̬�Ļ���Ҫ��virtualд�������� ���߾��ǲ��������͵�����

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "����a:" << this->a << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b = 0)
	{
		this->b = b;
	}
	void print()
	{
		cout << "����b:" << this->b << endl;
	}
protected:
private:
	int b;
};

void howtoprint(Parent *base)
{
	base->print();
}

void howtoprint2(Parent &base)
{
	base.print();
}

int main()
{
	Parent p1;
	p1.print();

	Child c1;
	c1.print();

	Parent *pP = NULL;
	pP = &p1;
	pP->print();

// 	Child *pC = NULL;
// 	pC = &c1;
// 	pC->print();

	//�����Ǹ��� - - - - ���� = ���� ? ���� = ���� ?
	//pC = &p1;		//p1�Ǹ���  ������ͼ�����ǲ����ܵ�
	pP = &c1;		// ���� = ���� ��Ϊ���� = (��) ����	��Ϊ ���೤���Ϊ����
	pP->print();

	//����(����)
	Parent &p2 = c1;
	p2.print();		//��ӡ�������Ǹ���ĺ���print()
	//��ʵ��������ϣ���������ิ�Ƹ������ʱ���ӡ������������ĺ���
	//�ɸ��ำֵ��ʱ���ӡ�������Ǹ���ĺ���
	//��ʱ���麯�������� ��Ӧ�Ķ�̬Ҳ������

	howtoprint(&p1);		//��Ϊ����ĺ��������������Ǹ������������������� ���virtualд�������򲻻������̬
	howtoprint(&c1);		//Ҫ������̬�Ļ���Ҫ��virtualд�������� ���߾��ǲ��������͵�����

	//c++Ĭ���Ǿ�̬�������Ը�������ȥ��Ӧ��ĺ���
	//��̬����Ķ����Ǹ���ָ�������ȥ��������ִ����Ӧ�ĳ���
	//����c++�м���virtual�Ļ���ôc++�����������ֽ� = = = = => ��̬������
	//c++�������������ٰ� = = = ͬ����һ�仰�ܳ��ֶ��ֹ���, ������̬  - - - ����Ƕ�̬������
	howtoprint2(p1);
	howtoprint2(c1);

	//c1.Parent::print();	//������ʸ�����д�ĺ��� �����÷�

	system("pause");
	return 0;
}