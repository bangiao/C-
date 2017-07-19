#include <iostream>
using namespace std;

template <class T, class K>
class AA
{
public:
	AA(T a, K b)
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
	T a;
	K b;
};

int main()
{
	AA<int, float> a1(1, 2.12);

	a1.print();
	system("pause");
	return 0;
}