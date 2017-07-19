#include <iostream>
using namespace std;

class person
{
public:
	char *name;
	person()
	{

	}
};

int main()
{
// 	char *p = new char[10];
// 	memset(p, 0, sizeof(char));
// 	strcpy(p, "aaaaaa");
// 	delete[]p;

	person *p = new person();

	p->name = new char[20];
	memset(p->name, 0, sizeof(char));
	strcpy(p->name, "aaaaaaa");

	cout << p->name << endl;

	delete[]p->name;
	delete p;
	system("pause");
	return 0;
}