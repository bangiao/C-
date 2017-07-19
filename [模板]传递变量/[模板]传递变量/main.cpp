#include <iostream>
using namespace std;

template <class T, int num>
class Person
{
public:
	Person(T age = 0)
	{
		this->age = age;
		cout << "this->age:" << this->age << endl;
		cout << "num:" << num << endl;
	}
private:
	T age;
};

int main(int atgv, char *args[])
{
	Person<int, 5> p1(15);
	system("pause");
	return 0;
}