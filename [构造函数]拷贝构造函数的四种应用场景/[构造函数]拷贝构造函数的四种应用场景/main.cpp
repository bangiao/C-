#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class person
{
public:
	person(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	person(person &obj)
	{
		this->a = obj.a;
		this->b = obj.b;
	}
protected:
private:
	int a, b;
};

void print(person p1) // �������캯���ĵ�����Ӧ�ó���
{
	
}


person func()
{
	person a(1, 2);
	return a;
}

int main(int argv, char *args[])
{
	person p1(2, 3);
	person p2(p1);	//�������캯���ĵ�һ��Ӧ�ó���
	person p3 = p1; //�������캯���ĵڶ���Ӧ�ó���
	person p4 = func(); //�������캯���ĵ�����Ӧ�ó���
	printf("hello world...\n");
	system("pause");
	return 0;
}