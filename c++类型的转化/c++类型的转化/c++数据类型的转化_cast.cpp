#include <iostream>
#include <vector>
using namespace std;

//1. reinterpret_cast<xxxx>();
#if 0
/*
1、reinterpret_cast
reinterpret_cast将一个类型的指针转换为另一个类型的指针，它也允许从一个指针转换为整数类型。
(1 这种转换不用修改指针变量值数据存放格式（不改变指针变量），
而是在编译时重新解释指针的类型(操作结果只是简单的从一个指针到别的指针的值的二进制拷贝。
在类型之间指向的内容不做任何类型的检查和转换)。

(2 但不能用于非指针类型的转换。

（1）转换一个指针为其它类型的指针，能够在非相关的类型之间转换

	class A {};
	class B {};
	A * a = new A;
	B * b = reinterpret_cast<B *>(a);

（2）不能将const指针转换为非const

	const int* point =&j;
	dm  =reinterpret_cast<double*>(point);

（3）不能用于非指针类型的转换

	int i; 
	double j = 2.1；
	j =reinterpret_cast<int>(j);

（4）可以将一段buffer转成一个类的对象指针，或者反过来。

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
//	（1）转换一个指针为其它类型的指针，能够在非相关的类型之间转换
#if 0
	A<int> *a = new A<int>(97);
	B<char> *b = reinterpret_cast<B<char> *>(a);

	cout << (char)a->getCh() << endl;
	cout << b->getCh() << endl;
#endif
//  （2）不能将const指针转换为非const
#if 0
	int j = 10;

	const int* point = &j;
	// “reinterpret_cast”: 无法从“const int *”转换为“double *”
	double dm = reinterpret_cast<double*>(point);
#endif
//	（3）不能用于非指针类型的转换
#if 0
	int i;
	double j = 2.1;
	// “reinterpret_cast”: 无法从“double”转换为“int”
	// note: 转换是有效的标准转换，可以隐式执行或通过使用 static_cast、C 样式转换或函数样式转换执行
	j = reinterpret_cast<int>(j);
#endif

//	（4）可以将一段buffer转成一个类的对象指针，或者反过来。
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

// 2、const_cast
#if 0
/*

1) const_cast用于const指针与普通指针间的相互转换
	（将一个const指针转换为对应指针类型的普通指针变量，也可以将一个普通指针变量转换为一个const指针）。

2) 不能将非常量指针变量转换为普通变量（从const转为非const，或者volatile转为非volatile）。

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
3、static_cast
static_cast主要用于基本类型间的相互转换，和具有继承关系间的类型转换
（将子类类型的指针转换为父类类型的指针，也能够转换父类类型的指针为它的子类类型的指针）。

（1）用于替代C风格的显式转换和各种类型指针到void*的转换

long b = (int) a;
long b =static_cast<int>(a);

（2）用于父类到子类指针的转换

（3）不能在类层次外转换，所以static_cast比C方式转换安全。

float x;
Count<<static_cast<int>(x);//把x作为整型值输出
*/

int main(void)
{
	// （1）用于替代C风格的显式转换和各种类型指针到void*的转换
	
	/* C语言风格的类型转换 */
	long a = 1000;
	long b = (int)a;
	cout << a << " " << b << endl;
	/* c++风格类型的转换 */
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
	cp->print();		// 多态调用, 使用子类的 print 函数
	Cabriolet *p = dynamic_cast<Cabriolet *> (cp);		// 判断基类是不是多态了 子类的 Cabriolet
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