#include <iostream>
using namespace std;

int main(void)
{
	const int num = 5;

	printf("&num = %p\n", &num);

	int *p = const_cast<int *>(&num);

	printf("&num = %p\n", &num);
	printf("p = %p\n", p);

	*p = 5;
	cout << num << endl;

	system("pause");
	return 0;
}