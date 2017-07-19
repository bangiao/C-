#include <iostream>
using namespace std;


//这里的static元素的内容是属于不同类型的类家族的共有元素
template <typename T>
class AA
{
public:
	static T a;

	void print()
	{
		cout << (int)this->a << endl;
	}
};
template <typename T>
T AA<T>::a = 0;

int main(int argv, char *args[])
{
	AA<int> a1, a2, a3;
	a1.a++;		//1
	a2.a++;		//2
	a3.a++;		//3
	a1.print();
	AA<char> a4, a5, a6;
	a4.a++;
	a5.a++;
	a6.a++;
	a4.print();
	system("pause");
	return 0;
}