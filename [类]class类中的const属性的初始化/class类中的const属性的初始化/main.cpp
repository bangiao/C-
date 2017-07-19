#include <iostream>
using namespace std;

class person
{
public:
	person(int a = 20) : b(a)
	{
		this->a = a;
	}
private:
	int a;
	const int b;
};

int main()
{
	person p1;
	cout << p1.a << endl;
	cout << p1.b << endl;
	system("pause");
	return 0;
}