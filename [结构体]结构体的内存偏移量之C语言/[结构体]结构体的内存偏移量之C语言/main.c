#include <stdio.h>
#include <stdlib.h>

typedef struct MyStruct
{
	int age;// 4
	char ch;// 1
	float f;// 4
	double dou;// 8
}MyStruct;

int main(void)
{
	printf("sizeof(MyStruct) = %d\n", sizeof(MyStruct));

	printf("Æ«ÒÆÁ¿ÊÇ = %d\n", (int)(&((MyStruct *)(NULL))->ch));

	system("pause");
	return 0;
}