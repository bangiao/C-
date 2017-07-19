#include <iostream>
using namespace std;

class Person
{
public:
	Person(int a)
	{

	}
	void malloc_fun(int len)
	{
		this->pString = new char[12];
		if (NULL == this->pString)
		{
			return;
		}
		memcpy(this->pString, "aaadsdsghjdsgfashgxhvc", len);
		delete[]this->pString;
	}
protected:
private:
	char *pString;
};

int main()
{
	char *pString = new char[20];

	strcpy(pString, "aaaaaa");
	delete[]pString;

// 	Person *p1 = new Person(1);
// 
// 	p1->malloc_fun(10);

	system("pause");
	return 0;
}