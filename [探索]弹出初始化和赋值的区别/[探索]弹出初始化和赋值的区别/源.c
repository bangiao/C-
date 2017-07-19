#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int a;
	int b[3];
	char buf[8];
}Stypaname;

int main(int argv, char *args[])
{
	int ret = 0;
	Stypaname s1;

	s1 = (Stypaname){ 1, 2, 3, 4 , "zhazha" };
	
	printf("a:%d, b:%d, %d, %d, string:%s\n", s1.a, s1.b[0], s1.b[1], s1.b[2], s1.buf);

	system("pause");
	return ret;
}