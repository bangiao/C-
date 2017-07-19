#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	virtual void print()
	{
		cout << "print A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B" << endl;
	}
	virtual void print()
	{
		cout << "print B" << endl;
	}
	void helloworld()
	{
		cout << "helloworld" << endl;
		cout << "age = " << age << endl;
	}
public:
	int age{ 10 };
};

void func(A *pBase)
{
	pBase->print();
	B *tmp = dynamic_cast<B *>(pBase);		// �������Ϊ�˽�����ת�����������õ�
	// B *tmp = static_cast<B *>(pBase);			// ������Ļ����Ǻܰ�ȫ
	// B *tmp = reinterpret_cast<B*>(pBase);	// �����Ҫ������ָ���ת����
	if (NULL == tmp)
	{
		cout << "���ݹ����Ĳ����Ǹ������͵Ĳ���, ���ܹ�ת��" << endl;
	}
	tmp->helloworld();
}

class KK
{
public:
	const int a{10};
};

int main(void)
{
	A &a = B();

	func(&a);

	cout << "---------------------------------" << endl;
	cout << "---------------------------------" << endl;
	cout << "---------------------------------" << endl;
	cout << "---------------------------------" << endl;
	cout << "---------------------------------" << endl;


	// ������Կ���, const_cast ���޷������޸� num ����Ϊ
	// const ��ʹ�û��Ʋ���ͨ���ڴ��ȡ, ����ͨ�� ������ key ��value ��
	// const ���εı�����Ȼ�������ڴ��е�
	// ��ʽ�洢 const ��ǳ���, ��Ȼͨ�� const_cast ȥ�� const ����, ������
	// ����ʹ�� num Ĭ�ϵĻ��Ǵ� key value �������ȶ�ȡ
	// ����ʹ�õ� *p �Ļ�, �޸ĵ�ȷʵ���ڴ�, ����û��, ��num�Ķ�ȡûɶ��ϵ
	const int num = 10;
	int *p = const_cast<int *>(&num);
	cout << num << endl;
	cout << *p << endl;
	cout << &num << endl;
	cout << p << endl;

	*p = 20;
	cout << num << endl;
	cout << *p << endl;
	cout << &num << endl;
	cout << p << endl;

	cout << sizeof(KK) << endl;
	KK k;
	cout << sizeof(k) << endl;

	system("pause");
	return 0;
}