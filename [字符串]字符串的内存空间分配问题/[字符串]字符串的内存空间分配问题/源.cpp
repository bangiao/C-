#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	// 说明这个直接从常量区申请一个内存放入 zhazha 字符串, 并返回了对应的地址回来给指针
	// 0x009c6b30
	char *str1 = "zhazha";
	// 0x009c6b30
	char *str2 = "zhazha";
	// 在堆中申请内存, 并复制
	char *str3 = new char[7];
	memcpy(str3, str2, strlen(str2));

	system("pause");
	return 0;
}