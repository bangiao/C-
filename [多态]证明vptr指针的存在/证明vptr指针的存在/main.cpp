#include <iostream>
using namespace std;

//֤���Ĳ���
//1. ���������� �̳�
//2. sizeof������Ĵ�С	1, 1
//3. �����඼д�Ϻ��� ������ͬ�ĺ���
//4. sizeof������  ���ֻ���  1, 1
//5. ��ǰ���һ�����к�������virtual
//6. �ٴ�sizeof  ������ 4, 4
//7. ֤��vptrָ��Ĵ���

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