#include <iostream>
#include <vector>
using namespace std;

//1. reinterpret_cast<xxxx>();
#if 0
/*
1��reinterpret_cast
reinterpret_cast��һ�����͵�ָ��ת��Ϊ��һ�����͵�ָ�룬��Ҳ�����һ��ָ��ת��Ϊ�������͡�
(1 ����ת�������޸�ָ�����ֵ���ݴ�Ÿ�ʽ�����ı�ָ���������
�����ڱ���ʱ���½���ָ�������(�������ֻ�Ǽ򵥵Ĵ�һ��ָ�뵽���ָ���ֵ�Ķ����ƿ�����
������֮��ָ������ݲ����κ����͵ļ���ת��)��

(2 ���������ڷ�ָ�����͵�ת����

��1��ת��һ��ָ��Ϊ�������͵�ָ�룬�ܹ��ڷ���ص�����֮��ת��

	class A {};
	class B {};
	A * a = new A;
	B * b = reinterpret_cast<B *>(a);

��2�����ܽ�constָ��ת��Ϊ��const

	const int* point =&j;
	dm  =reinterpret_cast<double*>(point);

��3���������ڷ�ָ�����͵�ת��

	int i; 
	double j = 2.1��
	j =reinterpret_cast<int>(j);

��4�����Խ�һ��bufferת��һ����Ķ���ָ�룬���߷�������

	class A;
	A a;
	char* pBuffer = reinterpret_cast<char*> (&a);

*/

template <class T>
class A
{
public:
	A(T ch)
	{
		this->a = ch;
	}
	T getCh()
	{
		return a;
	}
private:
	T a;
};

template <class T>
class B
{
public:
	B(T b)
	{
		this->b = b;
	}
	T getCh()
	{
		return b;
	}
private:
	T b;
};

template <class T>
class C
{
public:
	T m_pBuffer{ 0 };
};

int main(void)
{
//	��1��ת��һ��ָ��Ϊ�������͵�ָ�룬�ܹ��ڷ���ص�����֮��ת��
#if 0
	A<int> *a = new A<int>(97);
	B<char> *b = reinterpret_cast<B<char> *>(a);

	cout << (char)a->getCh() << endl;
	cout << b->getCh() << endl;
#endif
//  ��2�����ܽ�constָ��ת��Ϊ��const
#if 0
	int j = 10;

	const int* point = &j;
	// ��reinterpret_cast��: �޷��ӡ�const int *��ת��Ϊ��double *��
	double dm = reinterpret_cast<double*>(point);
#endif
//	��3���������ڷ�ָ�����͵�ת��
#if 0
	int i;
	double j = 2.1;
	// ��reinterpret_cast��: �޷��ӡ�double��ת��Ϊ��int��
	// note: ת������Ч�ı�׼ת����������ʽִ�л�ͨ��ʹ�� static_cast��C ��ʽת��������ʽת��ִ��
	j = reinterpret_cast<int>(j);
#endif

//	��4�����Խ�һ��bufferת��һ����Ķ���ָ�룬���߷�������
//	char *buffer = "zhazha";
// 	auto c = reinterpret_cast<C<char *> *>(buffer);
// 	for (; '\0' != *c->m_pBuffer; )
// 		cout << *c->m_pBuffer << endl;

	C<char *> c;
	char* pBuffer = reinterpret_cast<char*> (&c);

	system("pause");
	return 0;
}
#endif

// 2��const_cast
#if 0
/*

1) const_cast����constָ������ָͨ�����໥ת��
	����һ��constָ��ת��Ϊ��Ӧָ�����͵���ָͨ�������Ҳ���Խ�һ����ָͨ�����ת��Ϊһ��constָ�룩��

2) ���ܽ��ǳ���ָ�����ת��Ϊ��ͨ��������constתΪ��const������volatileתΪ��volatile����

class C {};
const C *a = new C;
C *b = const_cast<C *>(a);
*/

class A
{
public:
	A(int a)
	{
		this->m_a = a;
	}
	int m_a;
};

int main(void)
{
	A *a = new A(10);
	A *b = const_cast<A *>(a);

	cout << a->m_a << endl;
	cout << b->m_a << endl;
	system("pause");
	return 0;
}
#endif

//3. static_cast
#if 0
/*
3��static_cast
static_cast��Ҫ���ڻ������ͼ���໥ת�����;��м̳й�ϵ�������ת��
�����������͵�ָ��ת��Ϊ�������͵�ָ�룬Ҳ�ܹ�ת���������͵�ָ��Ϊ�����������͵�ָ�룩��

��1���������C������ʽת���͸�������ָ�뵽void*��ת��

long b = (int) a;
long b =static_cast<int>(a);

��2�����ڸ��ൽ����ָ���ת��

��3��������������ת��������static_cast��C��ʽת����ȫ��

float x;
Count<<static_cast<int>(x);//��x��Ϊ����ֵ���
*/

int main(void)
{
	// ��1���������C������ʽת���͸�������ָ�뵽void*��ת��
	
	/* C���Է�������ת�� */
	long a = 1000;
	long b = (int)a;
	cout << a << " " << b << endl;
	/* c++������͵�ת�� */
	long c = 10000;
	long d = static_cast<long>(c);
	cout << c << " " << d << endl;
	system("pause");
	return 0;
}
#endif 

class A
{
public:
};

class Car
{
public :
	virtual void print()
	{
		cout << "Car" << endl;
	}
};

class Cabriolet : public Car
{
public:
	virtual void print()
	{
		cout << "Cabriolet" << endl;
	}
};

class Limousline : public Car
{
public:
	virtual void print()
	{
		cout << "Limousline" << endl;
	}
};

void f(Car *cp)
{
	cp->print();		// ��̬����, ʹ������� print ����
	Cabriolet *p = dynamic_cast<Cabriolet *> (cp);		// �жϻ����ǲ��Ƕ�̬�� ����� Cabriolet
	if (NULL != p)
		p->print();
	Limousline *k = dynamic_cast<Limousline *>(cp);
	if (NULL != k)
		p->print();
}

int main(void)
{
	Car *c = new Cabriolet;
	f(c);
	if (NULL == c)
		delete c;
	c = NULL;
	system("pause");
	return 0;
}