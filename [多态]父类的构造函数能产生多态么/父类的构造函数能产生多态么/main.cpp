#include <iostream>
using namespace std;

//����ֻҪ��virtual�ͻ�����麯��ָ��vptrָ�벢�Ҳ�������vptrָ�� һ���ڸ��� һ��������
//������û�в���ʱvptrָ��δ����ʼ��
//����������캯��ִ��ʱ ����vptrָ�뽫��ͬʱָ����Ĳ����ĵ�ַ
//����������캯��ִ��ʱ�����vptrָ�뽫��ָ�������ַ

class AA
{
public:
	AA(int a = 1)
	{
		//printf("sizeof(a1):%d\n", sizeof(*this));
		this->a = a;
	}
	virtual void print()
	{
		cout << "����a:" << a << endl;
	}
protected:
	int a;
};

class BB : public AA
{
public:
	BB(int a = 2, int b = 3)
	{
		this->a = a;
		this->b = b;
		print();
	}
	void print()
	{
		cout << "����a:" << a << endl;
		cout << "����b:" << b << endl;
	}
protected:
	int b;
};
int main()
{
// 	printf("sizeof(AA):%d\n", sizeof(AA));
// 	printf("sizeof(BB):%d\n", sizeof(BB));

	//AA a1;
	BB b1;
	b1.print();
	system("pause");
	return 0;
}
