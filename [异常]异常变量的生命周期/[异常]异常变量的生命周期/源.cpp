#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test()
	{
		cout << "���캯��" << endl;
	}
	~Test()
	{
		cout << "��������" << endl;
	}
	Test(const Test &obj)
	{
		cout << "�������캯��" << endl;
	}
};

void dowork(char *from, char *to)
{
	Test t1;							//��һ�ι��캯��
	if ('a' == *from)
	{
		throw Test();					//�ڶ��ι��캯��  �ǹ�����������  Ȼ����п������캯�� 
		//���������󿽱���ȥ
	}
	if ('\b' == *from)
	{
		throw new Test();
	}
	while (*from != '\0')
	{
		*from++ = *to++;
	}
}

int main1()
{
	int ret = 0;
	
	char *from = "abcde";
	char to[6];
	try
	{
		dowork(from, to);
	}
	catch (Test e)
	{
		cout << "typename:Test e" << endl;
	}
// 	catch (Test &e)						//��֪�쳣Ԫ�غ��쳣Ԫ�ص����ò�����ͬʱ����
// 	{//��������������캯��
// 		cout << "typename:Test &e" << endl;
// 	}
	catch (Test *e)
	{
		cout << "typename:Test *e" << endl;
		delete e;
	}
	catch (...)
	{
		cout << "is unknow" << endl;
	}
	return ret;
}

int main(int argv, char *args[])
{
	int ret = 0;
	main1();
	system("pause");
	return ret;
}