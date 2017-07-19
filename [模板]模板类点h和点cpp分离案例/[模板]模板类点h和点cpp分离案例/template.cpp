#include <iostream>
#include "template.h"
using namespace std;

template <class T>
ostream &operator<<(ostream &Out, AA<T> &a1)
{
	Out << "a:" << a1.a << "  b:" << a1.b;
	return Out;
}

template <class T>
AA<T>::AA(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <class T>
void AA<T>::printCom()
{
	cout << this->a << endl;
	cout << this->b << endl;
}

template <class T>
AA<T> AA<T>::MySub2(AA<T> a1)
{
	AA<T> tmp(this->a - a1.a, this->b - a1.b);
	return tmp;
}

template <class T>
AA<T> AA<T>::operator+(AA<T> a1)
{
	AA tmp(this->a + a1.a, this->b + a1.b);
	return tmp;
}

template <class T>
AA<T> MySub1(AA<T> a1, AA<T> a2)
{
	AA<T> tmp(a1.a - a2.a, a1.b - a2.b);
	return tmp;
}
