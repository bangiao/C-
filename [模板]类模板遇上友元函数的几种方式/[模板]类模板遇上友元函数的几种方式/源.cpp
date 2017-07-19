#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//在类内写模板类的时候不用使用<T>类型参数列表
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
	//类中的有元函数实际上不在类中的 它是全局函数 没有 template 效果
	//所以有关Complex的都要加<>
	//解决方法 一
	friend ostream &operator<< <T> (ostream &out, Complex<T> &c1);
	void print();
	//解决方法 二
	template <class T>
	friend Complex<T> MySub(Complex<T> &c1, Complex<T> &c2);
protected:
	T a;
	T b;
};

//成员函数可以这样写
template <class T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

//成员函数可以这样写
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


// C++中模板类使用友元模板函数
//
// 
// 问题始于学习数据结构，自己编写一个单链表，其中用到了重载输出运算符 << ，我写的大约这样：
// template <class T> class List{
// 	friend std::ostream& operator << (std::ostream& os, const List<T>& slist);
// 	//……
// }; 用vs2008可编译，但无法链接：无法解析的外部符号……
// 后来上网查改为template <class T> class List{
// 	friend std::ostream& operator <<  <>(std::ostream& os, const List<T>& slist);
// 	//……
// };
// 就可以了。不知所以然，查了下《C++ Primer》才弄明白。
// 好了，进入正题：
// 在类模板中可以出现三种友元声明：
// （1）普通非模板类或函数的友元声明，将友元关系授予明确指定的类或函数。
// （2）类模板或函数模板的友元声明，授予对友元所有实例的访问权。
// （3）只授予对类模板或函数模板的特定实例的访问权的友元声明。
// 要注意的是，友元函数并非成员函数，是改变了它对类成员的访问权限。
// （1）没有什么好说的，如：
// template<class T>
// class A{
// 	friend void fun();
// 	//...
// };
// 此例中fun可访问A任意类实例中的私有和保护成员
// （2）
// template<class T>
// class A{
// 	template<class T>
// 	friend void fun(T u);
// 	//...
// };
// 这时友元使用与类不同的模板形参，T可以是任意合法标志符，友元函数可以访问A类的任何类实例的数据，即不论A的形参是int，double或其他都可以。
// （3）
// template<class T>
// class A{
// 	friend void fun<T>(T u);
// 	//...
// };
// 此时fun只有访问类中特定实例的数据。换句话说，此时具有相同模板实参的fun函数与A类才是友元关系。即假如调用fun时其模板实参为int，则它只具有A<int>的访问权限。当然friend void fun<T>(T u); 中<>中的T可以是任意类型，比如int，double等
// 回到原问题，按（3）可改为：
// template <class T> class List{
// 	friend std::ostream& operator << <T>(std::ostream& os, const List<T>& slist);
// 	//……
// };
// 按（2）可改为：
// template <class T> class List{
// 	template <class T>
// 	friend std::ostream& operator << (std::ostream& os, const List<T>& slist);
// 	//……
// };
// 在这里其实两者实现的最终效果一样的，因为调用输出运算符时需要访问的类实例的对象是它本身，所以形参T在第一种改法中一定匹配。
// 
// 
// 
// 对类建立友元函数很容易。但是迁移到模板上却容易出现让人摸不着头脑的连接错误。
// 层次不够，不做分析，单纯介绍两种为类模板定义友元函数的方法
// 
// １　封闭型
// C++中模板类使用友元模板函数template< typename T >
// C++中模板类使用友元模板函数class MyClass
// C++中模板类使用友元模板函数{
// 	C++中模板类使用友元模板函数    friend void function(MyClass< T > &arg)
// 	C++中模板类使用友元模板函数{
// 		C++中模板类使用友元模板函数        C++中模板类使用友元模板函数
// 		C++中模板类使用友元模板函数 }
// 	C++中模板类使用友元模板函数 };
// 要点：友元函数定义在模板体内。
// 
// ２　开放型
// C++中模板类使用友元模板函数template< typename T >
// C++中模板类使用友元模板函数class MyClass
// C++中模板类使用友元模板函数{
// 	C++中模板类使用友元模板函数    template< typename C >
// 	C++中模板类使用友元模板函数    friend void function(MyClass< C > &arg);
// 	C++中模板类使用友元模板函数 };
// C++中模板类使用友元模板函数
// C++中模板类使用友元模板函数template< typename C >
// C++中模板类使用友元模板函数void function(MyClass< C > &arg)
// C++中模板类使用友元模板函数{
// 	C++中模板类使用友元模板函数    C++中模板类使用友元模板函数
// 	C++中模板类使用友元模板函数 }
// 	要点：模板体内要另建模板。
// 
// 	3 告诉编译器声明的设个是模板
// 	C++中模板类使用友元模板函数#include <iostream>
// 	C++中模板类使用友元模板函数using namespace std;
// 	C++中模板类使用友元模板函数
// 		C++中模板类使用友元模板函数template < typename T >
// 		C++中模板类使用友元模板函数class A
// 		C++中模板类使用友元模板函数{
// 		C++中模板类使用友元模板函数    friend ostream &operator<< < T >(ostream &, const A< T > &);
// 		C++中模板类使用友元模板函数 };
// 	C++中模板类使用友元模板函数
// 		C++中模板类使用友元模板函数template < typename T >
// 		C++中模板类使用友元模板函数ostream &operator<< (ostream &output, const A< T > &a)
// 		C++中模板类使用友元模板函数{
// 		C++中模板类使用友元模板函数    output << "重载成功" << endl;
// 		C++中模板类使用友元模板函数    return output;
// 		C++中模板类使用友元模板函数 }
// 			C++中模板类使用友元模板函数
// 			C++中模板类使用友元模板函数int main()
// 			C++中模板类使用友元模板函数{
// 			C++中模板类使用友元模板函数    A< int > a;
// 			C++中模板类使用友元模板函数    cout << a;
// 			C++中模板类使用友元模板函数 }
// 				要点：显示地在重载的运算符或者函数后面加上模板声明< T >，告诉编译器友元函数是一个类型一致的模板。
// 
// 				建议：
// 				如果希望使用函数与模板特化的类型相对应，则使用方法3（模板显示声明）
// 				如果希望使用函数与模板特化的类型相独立，则使用方法2（二重模板）
// 				简短的内联函数使用方法1
// 
// 			本文来自CSDN博客，转载请标明出处：http ://blog.csdn.net/squarereal/archive/2009/09/23/4579950.aspx