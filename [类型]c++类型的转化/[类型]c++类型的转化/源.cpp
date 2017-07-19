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
	B *tmp = dynamic_cast<B *>(pBase);		// 这个就是为了将父类转化换成子类用的
	// B *tmp = static_cast<B *>(pBase);			// 用这个的话不是很安全
	// B *tmp = reinterpret_cast<B*>(pBase);	// 这个主要是用于指针的转化的
	if (NULL == tmp)
	{
		cout << "传递过来的参数是父类类型的参数, 不能够转换" << endl;
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


	// 这里可以看出, const_cast 是无法真正修改 num 的因为
	// const 的使用机制不是通过内存读取, 而是通过 类似于 key 和value 的
	// const 修饰的变量仍然存在于内存中的
	// 方式存储 const 标记常量, 虽然通过 const_cast 去除 const 属性, 并且在
	// 但是使用 num 默认的还是从 key value 表中优先读取
	// 所以使用的 *p 的话, 修改的确实是内存, 但是没用, 和num的读取没啥关系
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