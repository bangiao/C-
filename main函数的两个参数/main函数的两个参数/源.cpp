#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//argc:��Dosָ��͹����ı������� Ĭ�� 1
//argv:��Dosָ��͹����ı������ַ������� Ĭ��Ϊ�ļ���ַ
int main(int argc, char *argv[])
{
	int ret = 0;
	int bkk = 1;
	char *array = "aaa";
	printf("argc:%d, argv:%s\n", argc, argv[0]);
	printf("argc:%d, argv:%s\n", argc, argv[1]);

	system("pause");
	return ret;
}