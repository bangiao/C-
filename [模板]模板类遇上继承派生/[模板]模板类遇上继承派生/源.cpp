#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//ͨ�����õ������ĵط�һ�㶼Ҫ����<typename>(���Ͳ����б�)
//Such as:
//���õ�ģ����������� AA �ĵط����м��� <typename>(���Ͳ����б�)
//�����õ�ԭ���� ģ�����Ǹ������໹û��ʵ��

template <class T>
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "printA()" << endl;
		cout << this->a << endl;
	}
protected:
	T a;
};

//Ҫ������һ������Ļ���Ҫ���߱���������������ʲô�������͵���
//�����̽���� c++������Ҫ֪�������ĸ��������ڴ��Ƕ���
//��Ϊֻ�й̶��������ڴ����֪����η����ڴ�
class BB : public AA<int>		//���߱�������ʲô�������Ƽ̳и���AA
{
public:
	BB(int a, int b) : AA<int>(a)
	{
		cout << "printB()" << endl;
		this->b = b;
	}
	void printB()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
protected:
	int b;
};

int main(int argv, char *args[])
{
	AA<int> a(11);
	a.printA();

	BB b(22, 33);
	b.printB();
	printf("hello world...\n");
	system("pause");
	return 0;
}