#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A 
{
public:
	class B
	{
	public:
		void print()
		{
			cout << "这个是内部类" << endl;
		}
	};

	void inttance()
	{
		B b = B();
		b.print();
	}
	B b;
};

int main(void)
{
	A a = A();
	a.b.print();
	
	
	system("pause");
	return 0;
}