#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class person
{
public:
	person(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void print()
	{
		cout << this->a << endl;
		cout << this->b << endl;
	}
protected:
private:
	int a, b;
};

int main(int argv, char *args[])
{
	person pArray[3] = { 0 };
	pArray->print();
	pArray[0].print();
	pArray[1].print();
	pArray[2].print();
	printf("hello world...\n");
	system("pause");
	return 0;
}