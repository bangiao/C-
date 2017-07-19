#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//argc:有Dos指令传送过来的变量个数 默认 1
//argv:由Dos指令传送过来的变量的字符串内容 默认为文件地址
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