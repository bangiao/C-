#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <algorithm>

//字母的全部变写和全部变小写
int main(int argv, char *args[])
{
	int ret = 0;
	string s1 = "aaaBBB";
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << s1.c_str() << endl;
	string s2 = "AAAbbb";
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	cout << s2.data() << endl;
	system("pause");
	return ret;
}