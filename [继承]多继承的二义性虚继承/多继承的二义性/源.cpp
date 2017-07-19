#include <iostream>
using namespace std;
//虚继承
//多继承在真正的应用场景中是不是这样用的
//多继承的方法已经被遗弃
//多继承的二义性是近亲搞基搞出来的

class base					//祖宗
{
public:
	int k;
protected:
private:
};

class base1 : virtual public base		//父亲1
{
public:
protected:
private:
};

class base2 : virtual public base		//父亲2
{
public:
protected:
private:
};

class C : public base1, public base2	//搞基了 搞出了个儿子
{
public:
protected:
private:
};
//两个父亲继承了 祖宗的基因 K 但是在搞基后出现的儿子发现不知道选择哪个K进行使用
//因为父亲1和父亲2都存在K

int main()
{
	C c1;

	c1.k = 2;  //error C2385: 对“k”的访问不明确  必须使用虚类

	system("pause");
	return 0;
}