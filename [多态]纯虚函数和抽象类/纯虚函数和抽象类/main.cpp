#include <iostream>
using namespace std;

//����һ��������:���ڴ��麯������г�����
//���ڼ̳е���  �����Զ������ ������ͨ�Ĳ���
//��������ʵ�ֶ�̬ ���� ����һ���������ָ��������� ���и�ֵ������ԭ��
class figure
{
public:
	virtual void show_area() = 0;
protected:
	double x;
	double y;
private:
};

class triangle : public figure
{
public:
	triangle(double x = 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout << "�����ε����:" << x*y*0.5 << endl;
	}
};

class square : public figure
{
public:
	square(double x = 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout << "�ı��ε����:" << x*y << endl;
	}
};

class circle : public figure
{
public:
	circle(double x = 1)
	{
		this->x = x;
	}
	void show_area()
	{
		cout << "Բ�����:" << 3.14*x*x << endl;
	}
};

class test : public figure
{
public:
	test(double x = 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	//����ע�͵���Ļ� ��ô �൱�� �̳��� virtual void show_area() = 0;
	//�����ͬ���޷��������  ӦΪ��Ҳ�ǳ�����
// 	void show_area()
// 	{
// 		cout << "�ı��ε����:" << x*y << endl;
// 	}
};


void run_show(figure &pBase)
{
	pBase.show_area();
}

int main()
{
	triangle t1;
	square s1;
	circle c1;
	//test t2;

	run_show(t1);
	run_show(s1);
	run_show(c1);
	
	system("pause");
	return 0;
}