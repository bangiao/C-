#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <list>
#include <set>
/*
1. 什么是函数对象?
	函数对象就是仿函数 就是 重载了操作符的类叫做函数对象  它拥有了 函数的特性
	重载了 () 操作符之类的
2. 仿函数的意义
	仿函数的意义在于可以将函数调用时的一些东西已变量的方式记录下来
*/

template <class T>
class ShowElem
{
public:
	ShowElem()
	{
		this->n = 0;
	}
	void operator()(T &t)
	{
		n++;
		cout << t << " ";
	}
	void printN()
	{
		cout << "n:" << this->n << endl;
	}
protected:
private:
	int n;
};

template <class T>
void FuncShowElem(T &a)
{
	cout << a << endl;
}
//typedef void(*pFuncShowElem)(int &s);

void main11()
{
	int a = 10;
	ShowElem<int> s;
	s(a);
	FuncShowElem(a);

}

void main12()
{
	vector<int > v;

	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	ShowElem<int> s;
	//这里的参数三涉及到一个重要的问题
	//它是一个形参
	//打开算法  for_each中你会发现这个参数三不是引用和指针
	//这个时候这里的参数三和函数中的 s 是两个不一样的对象
	//但是这个算法 却返回了 函数
	//看算法原型
	/*
		template<class _InIt, class _Fn1> 
		inline _Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
		{	// perform function for each element
			_DEBUG_RANGE(_First, _Last);
			_DEBUG_POINTER(_Func);
			_For_each(_Unchecked(_First), _Unchecked(_Last), _Func);
			return (_STD move(_Func));
		}
	*/
	s = for_each(v.begin(), v.end(), s);
	//结论: 所以分清楚算法的参数 算法名称 放回值  尤为重要
//	pFuncShowElem pFun = for_each(v.begin(), v.end(), FuncShowElem<int>);
	for_each(v.begin(), v.end(), FuncShowElem<int>);
	s.printN();
}

int main(int argv, char *args[])
{
	int ret = 0;
	//main11();
	main12();
	
	system("pause");
	return ret;
}