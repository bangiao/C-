#include <iostream>
using namespace std;

int main01()
{
	int *p = new int[10];	// 这个是创建数组
	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("*p = %d\t", p[i]);
	}
	delete []p;
	return 0;
}

int main02()
{
	int *p = new int(10);//赋值
	printf("*p = %d\t", *p);
	delete p;
	return 0;
}

int main03()
{
	int *p = (int *)malloc(sizeof(int));
	*p = 10;

	printf("*p = %d\t", *p);

	free(p);
	return 0;
}

int main04()
{
	int a = 360;
	int i = 0;
	int sum = 0;

	for (i = 0; i < 5; i++)
	{
		sum += a;
	}


	printf("%d\n", sum);
	return 0;
}

int main()
{
// 	main01();
// 	main02();
// 	main03();
	main04();
	system("pause");
	return 0;
}