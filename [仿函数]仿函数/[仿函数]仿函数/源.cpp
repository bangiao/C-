#include <iostream>
using namespace std;

class FUNC
{
public:
	int operator()(int &x, int &y)
	{
		return x + y;
	}
};

int main(void)
{
	int gril = 4, boys = 3;
	FUNC f;
	cout << f(gril, boys) << endl;
	system("pause");
	return 0;
}