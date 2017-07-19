#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//������дģ�����ʱ����ʹ��<T>���Ͳ����б�
// template <class T>
// class Complex
// {
// public:
// 	Complex(T a, T b)
// 	{
// 		this->a = a;
// 		this->b = b;
// 	}
// 	Complex operator+(Complex &c1)
// 	{
// 		Complex tmp(c1.a + a, b + c1.b);
// 		return tmp;
// 	}
// 
// 	friend ostream &operator<<(ostream &out, Complex &c1)
// 	{
// 		out << c1.a << c1.b << endl;
// 		return out;
// 	}
// 	void print()
// 	{
// 		cout << this->a << endl;
// 		cout << this->b << endl;
// 	}
// 	friend Complex MySub(Complex &c1, Complex &c2)
// 	{
// 		Complex tmp(c1.a - c2.a, c1.b - c2.b);
// 		return tmp;
// 	}
// protected:
// 	T a;
// 	T b;
// };

template <class T>
class Complex
{
public:
	Complex(T a, T b);
	Complex operator+(Complex &c1);
	Complex operator-(Complex &c1);
// 	template <class T>
// 	friend ostream &operator<<(ostream &out, Complex<T> &c1);
	//���е���Ԫ����ʵ���ϲ������е� ����ȫ�ֺ��� û�� template Ч��
	//�����й�Complex�Ķ�Ҫ��<>
	//������� һ
	friend ostream &operator<< <T> (ostream &out, Complex<T> &c1);
	void print();
	//������� ��
	template <class T>
	friend Complex<T> MySub(Complex<T> &c1, Complex<T> &c2);
protected:
	T a;
	T b;
};

//��Ա������������д
template <class T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

//��Ա������������д
template <class T>
Complex<T> Complex<T>::operator+(Complex<T> &c1)
{
	Complex tmp(c1.a + a, b + c1.b);
	return tmp;
}

template <class T>
void Complex<T>::print()
{
	cout << this->a << endl;
	cout << this->b;
}

template <class T>
ostream &operator<<(ostream &out, Complex<T> &c1)
{
	out << c1.a << endl << c1.b;
	return out;
}

template <class T>
Complex<T> MySub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}

template <class T>
Complex<T> Complex<T>::operator-(Complex<T> &c1)
{
	Complex tmp(this->a - c1.a, this->b - c1.b);
	return tmp;
}

// template <class T>
// Complex<T> Complex<T>::operator-(Complex<T> &c1)
// {
// 	Complex tmp(c1.a - a, b - c1.b);
// 	return tmp;
// }

int main(int argv, char *args[])
{
	Complex<int> c1(1, 2);
	Complex<int> c2(2, 3);
	Complex<int> c3 = c1 + c2;
	cout << "c3: \n" << c3 << endl;
	Complex<int> c4 = MySub(c2, c1);
	cout << "c4: \n" << c4 << endl;
	Complex<int> c5 = c2 - c1;
	cout << "c5: " << c5 << endl;
	system("pause");
	return 0;
}


// C++��ģ����ʹ����Ԫģ�庯��
//
// 
// ����ʼ��ѧϰ���ݽṹ���Լ���дһ�������������õ��������������� << ����д�Ĵ�Լ������
// template <class T> class List{
// 	friend std::ostream& operator << (std::ostream& os, const List<T>& slist);
// 	//����
// }; ��vs2008�ɱ��룬���޷����ӣ��޷��������ⲿ���š���
// �����������Ϊtemplate <class T> class List{
// 	friend std::ostream& operator <<  <>(std::ostream& os, const List<T>& slist);
// 	//����
// };
// �Ϳ����ˡ���֪����Ȼ�������¡�C++ Primer����Ū���ס�
// ���ˣ��������⣺
// ����ģ���п��Գ���������Ԫ������
// ��1����ͨ��ģ�����������Ԫ����������Ԫ��ϵ������ȷָ�����������
// ��2����ģ�����ģ�����Ԫ�������������Ԫ����ʵ���ķ���Ȩ��
// ��3��ֻ�������ģ�����ģ����ض�ʵ���ķ���Ȩ����Ԫ������
// Ҫע����ǣ���Ԫ�������ǳ�Ա�������Ǹı����������Ա�ķ���Ȩ�ޡ�
// ��1��û��ʲô��˵�ģ��磺
// template<class T>
// class A{
// 	friend void fun();
// 	//...
// };
// ������fun�ɷ���A������ʵ���е�˽�кͱ�����Ա
// ��2��
// template<class T>
// class A{
// 	template<class T>
// 	friend void fun(T u);
// 	//...
// };
// ��ʱ��Ԫʹ�����಻ͬ��ģ���βΣ�T����������Ϸ���־������Ԫ�������Է���A����κ���ʵ�������ݣ�������A���β���int��double�����������ԡ�
// ��3��
// template<class T>
// class A{
// 	friend void fun<T>(T u);
// 	//...
// };
// ��ʱfunֻ�з��������ض�ʵ�������ݡ����仰˵����ʱ������ͬģ��ʵ�ε�fun������A�������Ԫ��ϵ�����������funʱ��ģ��ʵ��Ϊint������ֻ����A<int>�ķ���Ȩ�ޡ���Ȼfriend void fun<T>(T u); ��<>�е�T�������������ͣ�����int��double��
// �ص�ԭ���⣬����3���ɸ�Ϊ��
// template <class T> class List{
// 	friend std::ostream& operator << <T>(std::ostream& os, const List<T>& slist);
// 	//����
// };
// ����2���ɸ�Ϊ��
// template <class T> class List{
// 	template <class T>
// 	friend std::ostream& operator << (std::ostream& os, const List<T>& slist);
// 	//����
// };
// ��������ʵ����ʵ�ֵ�����Ч��һ���ģ���Ϊ������������ʱ��Ҫ���ʵ���ʵ���Ķ����������������β�T�ڵ�һ�ָķ���һ��ƥ�䡣
// 
// 
// 
// ���ཨ����Ԫ���������ס�����Ǩ�Ƶ�ģ����ȴ���׳�������������ͷ�Ե����Ӵ���
// ��β���������������������������Ϊ��ģ�嶨����Ԫ�����ķ���
// 
// ���������
// C++��ģ����ʹ����Ԫģ�庯��template< typename T >
// C++��ģ����ʹ����Ԫģ�庯��class MyClass
// C++��ģ����ʹ����Ԫģ�庯��{
// 	C++��ģ����ʹ����Ԫģ�庯��    friend void function(MyClass< T > &arg)
// 	C++��ģ����ʹ����Ԫģ�庯��{
// 		C++��ģ����ʹ����Ԫģ�庯��        C++��ģ����ʹ����Ԫģ�庯��
// 		C++��ģ����ʹ����Ԫģ�庯�� }
// 	C++��ģ����ʹ����Ԫģ�庯�� };
// Ҫ�㣺��Ԫ����������ģ�����ڡ�
// 
// ����������
// C++��ģ����ʹ����Ԫģ�庯��template< typename T >
// C++��ģ����ʹ����Ԫģ�庯��class MyClass
// C++��ģ����ʹ����Ԫģ�庯��{
// 	C++��ģ����ʹ����Ԫģ�庯��    template< typename C >
// 	C++��ģ����ʹ����Ԫģ�庯��    friend void function(MyClass< C > &arg);
// 	C++��ģ����ʹ����Ԫģ�庯�� };
// C++��ģ����ʹ����Ԫģ�庯��
// C++��ģ����ʹ����Ԫģ�庯��template< typename C >
// C++��ģ����ʹ����Ԫģ�庯��void function(MyClass< C > &arg)
// C++��ģ����ʹ����Ԫģ�庯��{
// 	C++��ģ����ʹ����Ԫģ�庯��    C++��ģ����ʹ����Ԫģ�庯��
// 	C++��ģ����ʹ����Ԫģ�庯�� }
// 	Ҫ�㣺ģ������Ҫ��ģ�塣
// 
// 	3 ���߱����������������ģ��
// 	C++��ģ����ʹ����Ԫģ�庯��#include <iostream>
// 	C++��ģ����ʹ����Ԫģ�庯��using namespace std;
// 	C++��ģ����ʹ����Ԫģ�庯��
// 		C++��ģ����ʹ����Ԫģ�庯��template < typename T >
// 		C++��ģ����ʹ����Ԫģ�庯��class A
// 		C++��ģ����ʹ����Ԫģ�庯��{
// 		C++��ģ����ʹ����Ԫģ�庯��    friend ostream &operator<< < T >(ostream &, const A< T > &);
// 		C++��ģ����ʹ����Ԫģ�庯�� };
// 	C++��ģ����ʹ����Ԫģ�庯��
// 		C++��ģ����ʹ����Ԫģ�庯��template < typename T >
// 		C++��ģ����ʹ����Ԫģ�庯��ostream &operator<< (ostream &output, const A< T > &a)
// 		C++��ģ����ʹ����Ԫģ�庯��{
// 		C++��ģ����ʹ����Ԫģ�庯��    output << "���سɹ�" << endl;
// 		C++��ģ����ʹ����Ԫģ�庯��    return output;
// 		C++��ģ����ʹ����Ԫģ�庯�� }
// 			C++��ģ����ʹ����Ԫģ�庯��
// 			C++��ģ����ʹ����Ԫģ�庯��int main()
// 			C++��ģ����ʹ����Ԫģ�庯��{
// 			C++��ģ����ʹ����Ԫģ�庯��    A< int > a;
// 			C++��ģ����ʹ����Ԫģ�庯��    cout << a;
// 			C++��ģ����ʹ����Ԫģ�庯�� }
// 				Ҫ�㣺��ʾ�������ص���������ߺ����������ģ������< T >�����߱�������Ԫ������һ������һ�µ�ģ�塣
// 
// 				���飺
// 				���ϣ��ʹ�ú�����ģ���ػ����������Ӧ����ʹ�÷���3��ģ����ʾ������
// 				���ϣ��ʹ�ú�����ģ���ػ����������������ʹ�÷���2������ģ�壩
// 				��̵���������ʹ�÷���1
// 
// 			��������CSDN���ͣ�ת�������������http ://blog.csdn.net/squarereal/archive/2009/09/23/4579950.aspx