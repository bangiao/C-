#include <iostream>
using namespace std;

class test
{
public:
	test()/* : a(10)*/
	{
		
	}
protected:
private:
	static int a;
};

int test::a = 10;

int main()
{

	system("pause");
	return 0;
}