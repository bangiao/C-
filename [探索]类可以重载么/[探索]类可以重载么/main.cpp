#include <iostream>
using namespace std;

//������  ���� ģ��������ôʵ�ֵ�???
// class Person
// {
// public:
// 	Person()
// 	{
// 
// 	}
// protected:
// 	int a;
// };
// 
// class Person
// {
// public:
// 	Person()
// 	{
// 
// 	}
// protected:
// 	double a;
// };

template <class T>
class Person
{
public:
	Person(T a)
	{
		this->a = a;
	}
protected:
	T a;
};

int main(int argv, char *args[])
{
	Person<int> a1(1);
	Person<double> a2(1.0001);
	//��ԭ����ʲô???
	system("pause");
	return 0;
}