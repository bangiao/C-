#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
//ÊµÏÖ×Ö·û´®Ìæ»»
int main(int argv, char *args[])
{
	int ret = 0;
	char *pReplace = "bbb";
	int nRepLen = strlen(pReplace);
	string s1 = "aaa, ccc, ccc";
	int sVal = s1.find("ccc", 0);
	cout << sVal << endl;
	s1.replace(sVal, nRepLen, pReplace);
	cout << s1 << endl;
	system("pause");
	return ret;
}