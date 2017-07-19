#include <iostream>
using namespace std;

//证明的步骤
//1. 定义两个类 继承
//2. sizeof两个类的大小	1, 1
//3. 两个类都写上函数 名字相同的函数
//4. sizeof两个类  发现还是  1, 1
//5. 在前面的一个类中函数加入virtual
//6. 再次sizeof  发现是 4, 4
//7. 证明vptr指针的存在

class AA
{
public:
	virtual void print()
	{
		printf("class AA\n");
	}
};

class BB : public AA
{
public:
	void print()
	{
		printf("class BB\n");
	}
};

int main()
{
	printf("sizeof(AA):%d\n", sizeof(AA));
	printf("sizeof(BB):%d\n", sizeof(BB));
	system("pause");
	return 0;
}