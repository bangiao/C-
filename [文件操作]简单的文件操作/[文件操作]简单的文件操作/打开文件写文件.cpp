#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

int main11(int argv, char *args[])
{
	int ret = 0;
	char *FileAddr = "d:\\1.txt";

	ofstream fp(FileAddr);
	fp << "hello..." << endl;
	fp << "hello......" << endl;
	fp << "hello......." << endl;
	fp.close();

	char ch;
	ifstream fp1(FileAddr);
	while (fp1.get(ch))
	{
		cout << ch;
	}
	fp1.close();
	system("pause");
	return ret;
}