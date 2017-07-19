#include <iostream>
using namespace std;

//以下做标记的地方都是使用了 (T a) 的地方 
//也就是说只要遇到属性 a 的地方都要有  参数列表
template <class T>
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
	void setA(T a)
	{
		this->a = a;
	}
	int getA()
	{
		return this->a;
	}
protected:
private:
	T a;		//////////////////////////////////////////////////////////////////////////
};

class BB : public AA<int>	//////////////////////////////////////////////////////////////////////////
{
public:
	BB(int a = 0, int b = 0) : AA<int>(a)	/////////////////////////////////////////////////
	{
		this->b = b;
	}
protected:
private:
	int b;
};
int main()
{
	AA<int> a1(1);	//////////////////////////////////////////////////////////////////////////
	BB b1(2, 3);
	system("pause");
	return 0;
}