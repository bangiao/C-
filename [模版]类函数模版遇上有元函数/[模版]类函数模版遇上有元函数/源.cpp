#include <iostream>
using namespace std;

template <class T>
class Complex
{
public:
	Complex(T a = 0, T b = 0);
	void print()const;
	friend Complex<T> operator+<T>(Complex<T> &a, Complex<T> &b);
protected:
private:
	T Real, Image;
};

template <class T>
Complex<T>::Complex(T a = 0, T b = 0)
{
	this->Image = a;
	this->Real = b;
}

template <class T>
void Complex<T>::print()const
{
	cout << this->Real << "   " << this->Image << endl;
}

template <class T>
Complex<T> operator+(Complex<T> &a, Complex<T> &b)
{
	T x, y;
	x = a.Real + b.Image;
	y = a.Image + b.Image;
	return Complex<T>(x, y);
}

template <class T>
void work(Complex<T>a, Complex<T>b)
{
	a.print();
	b.print();
}

int main()
{
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int>c3 = c1 + c2;
	c3.print();
	work(c1, c2);
	system("pause");
	return 0;
}