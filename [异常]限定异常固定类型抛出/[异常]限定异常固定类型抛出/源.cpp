#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test(int a = 0)
	{
		cout << "���캯��" << endl;
		this->a = a;
	}
	~Test()
	{
		cout << "��������" << endl;
	}
private:
	int a;
};

void Div()
{
	Test t1(1), t2(2);
	cout << "Ҫ�����쳣" << endl;
	throw 1;
}

//���׳��쳣
void Div1()	throw()
{
	Test t1(1), t2(2);
	cout << "Ҫ�����쳣" << endl;
	throw 1;
}

//ֻ�ܷŻ����г���������
void Div2()	throw(char, char *, int, int *)
{
	Test t1(1), t2(2);
	cout << "Ҫ�����쳣" << endl;
	throw 1;
}
//��д, �׳��κ����͵��쳣
void Div3()
{
	Test t1(1), t2(2);
	cout << "Ҫ�����쳣" << endl;
	throw 1;
}

int main(int argv, char *args[])
{
	int ret = 0;
	
	
	system("pause");
	return ret;
}