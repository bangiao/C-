#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	// ˵�����ֱ�Ӵӳ���������һ���ڴ���� zhazha �ַ���, �������˶�Ӧ�ĵ�ַ������ָ��
	// 0x009c6b30
	char *str1 = "zhazha";
	// 0x009c6b30
	char *str2 = "zhazha";
	// �ڶ��������ڴ�, ������
	char *str3 = new char[7];
	memcpy(str3, str2, strlen(str2));

	system("pause");
	return 0;
}