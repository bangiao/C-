#pragma once
#include <iostream>
using namespace std;

template <class T>
class AA
{
public:
	AA(T a, T b);
	void printCom();
	AA operator+(AA a1);
	AA MySub2(AA a1);
	//第二种方法是要分开的最好方法
	template <class T>
	friend AA<T> MySub1(AA<T> a1, AA<T> a2);
	template <class T>
	friend ostream &operator<<(ostream &Out, AA<T> &a1);
private:
	T a;
	T b;
};