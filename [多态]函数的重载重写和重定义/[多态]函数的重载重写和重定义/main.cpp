#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//��������: ������ͬһ���������в��ܲ�������������
//��������д: ��������д�����ڲ�ͬ������  �����virtual�Ļ��������̬û�еĻ�����  �������ض��� 
class Parent
{
public:
	virtual void func()
	{

	}
	virtual void func(int i)
	{

	}
	virtual void func(int i, int j)
	{

	}
protected:
private:
};

class Child : public Parent
{
public:
	void func(int i, int j)
	{

	}
	void func(int i, int j, int k)
	{

	}//�������Ǻ�������
protected:
private:
};

int main(int argv, char *args[])
{
	Child c1;
//	c1.func(1);	
	//c++��������������������غ�������ֻ���������в��Һ���
	//�������func(int i) ���ڸ����еĺ�������������û���������   û�����غ������� 1 ������
	//���ʱ�����������û����ͬ���ֵĺ�����ʱ�������ǿ��Ե��õĵ��Ǵ�ʱ�����д���funcͬ������
	//�����������ض��� ���Դ�ʱc++��ʾ
	c1.Parent::func(1);
	c1.func(1, 2);//�����麯����д������̬
	printf("hello world...\n");
	system("pause");
	return 0;
}