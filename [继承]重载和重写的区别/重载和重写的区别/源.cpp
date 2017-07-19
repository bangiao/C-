#include <iostream>
using namespace std;

/*
����������
1, ������������ͬ
2, �����ķ���ֵ�������ص�����\
3, ����������˳��
4, ��������������
5, ��������������
6, ���뷢����ͬһ����������  (����һ����, ���߹ۿ� { �������һ��������  }  )
*/

/*
��������д
1, �����ĵ����ֱ�����ͬ
2, �����ķ���ֵ������ͬ
3, �����Ĳ���������ͬ
4, ���뷢���������븸��֮��
5, ������virtual�ؼ���
*/

class Parent
{
public:
	Parent()
	{
		cout << "Parent():printf()...do" << endl;
	}
	void fun()
	{
		cout << "Parent:void fun()" << endl;
	}
	virtual void fun(int i)
	{
		cout << "Parent():void fun(int i)" << endl;
	}

	virtual void fun(int i, int j)
	{
		cout << "Parent():void fun(int i, int j) " << endl; 
	}
};

class Child : public Parent
{
public:
	void fun(int i, int j)
	{
		cout << "Child():void fun(int i, int j) " << endl;
	}

	void fun(int i, int j, int k)
	{
		cout << "Child():void fun(int i, int j, int k)" << endl;
	}
};

void run32(Parent &p)
{
	p.fun(1, 2);
}

int main()
{
	Parent a;

	a.fun();
	a.fun(1);
	a.fun(1, 2);

	Child c;
	//c.fun();		//ע��  �����Ǻ���������
	//c.fun(1);		//����������һ��
	c.Parent::fun();
	c.Parent::fun(1);

	//c.fun(1, 2);	//����Ǻ�������д ������̬
	
// 	int a1 = 0;
// 	int *p1 = &a1;
// 	int *&p = p1;
// 
// 	printf("a1:%d\n", a1);
// 	printf("*p1:%d\n", *p1);
// 	printf("*p:%d\n", *p);
	system("pause");
	return 0;
}