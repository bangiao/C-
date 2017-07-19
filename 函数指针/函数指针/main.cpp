#include <iostream>
#include <string>
using namespace std;

bool lengthCompare(const string &str1, const string&str2)
{
	if (str1 == str2)
	{
		return true;
	}
	return false;
}

typedef bool(*FUNCLENGTHCOMPARE)(const string &, const string&);

int main(void)
{
	FUNCLENGTHCOMPARE pf = lengthCompare;
	bool b1 = pf("hello", "goodbye");
	bool b2 = (*pf)("hello", "hello");
	bool b3 = lengthCompare("hello", "goodbye");
	system("pause");
	return 0;
}