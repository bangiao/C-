//ջ������һ���﷨����
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	~Test()
	{
		cout << "��������" << endl;
	}
protected:
private:
	int a;
	int b;
};

//���������throw�������������
void devide()
{
	Test t1(1, 2), t2(3, 4);
	throw 1;					//throw�൱��return ������ return  return �ǲ��ܿ亯�����صĵ��� throw����
}


int main(int argv, char *args[])
{
	int ret = 0;
	
	try
	{
		devide();
	}
	catch (int e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "δ֪����" << endl;
	}
	system("pause");
	return ret;
}