#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct KK
{
	string str1;
	double db;
	int num;
	char ch;
	string str2;
};

int main(void)
{
	KK k;
	string str("zhazha 66.66   32  A  BB");
	istringstream input(str);

	input >> k.str1 >> k.db >> k.num >> k.ch >> k.str2;


	cout << k.str1 << endl;
	cout << k.db << endl;
	cout << k.num << endl;
	cout << k.ch << endl;
	cout << k.str2 << endl;
	

	system("pause");
	return 0;
}