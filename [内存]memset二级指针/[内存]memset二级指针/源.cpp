#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <memory>
using namespace std;

int main(void)
{
	HANDLE *newHandle = new HANDLE[10];
	HANDLE *newHandle1 = new LPVOID[10];

	shared_ptr<HANDLE *> ps1(newHandle);
	shared_ptr<HANDLE *> ps2(newHandle1);

	memset(newHandle, 0, sizeof(newHandle));
	memset(newHandle1, 0, sizeof(newHandle1));

	system("pause");
	return 0;
}