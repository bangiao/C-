#include <iostream>
using namespace std;
//��̳�
//��̳���������Ӧ�ó������ǲ��������õ�
//��̳еķ����Ѿ�������
//��̳еĶ������ǽ��׸���������

class base					//����
{
public:
	int k;
protected:
private:
};

class base1 : virtual public base		//����1
{
public:
protected:
private:
};

class base2 : virtual public base		//����2
{
public:
protected:
private:
};

class C : public base1, public base2	//����� ����˸�����
{
public:
protected:
private:
};
//�������׼̳��� ���ڵĻ��� K �����ڸ������ֵĶ��ӷ��ֲ�֪��ѡ���ĸ�K����ʹ��
//��Ϊ����1�͸���2������K

int main()
{
	C c1;

	c1.k = 2;  //error C2385: �ԡ�k���ķ��ʲ���ȷ  ����ʹ������

	system("pause");
	return 0;
}