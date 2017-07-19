#include <iostream>
#include "ChinasocketDLL.h"
#include "SocketIMP.h"
using namespace std;

int main()
{
	socketIF *pBase = new SocketIMP();
	char inBuf[1024] = "4d564f5sadashj";
	int inLen = 10;
	char *OutBuf = NULL;
	int OutLen = 0;
	int ret = 0;

	pBase->mainOP(inBuf, inLen, OutBuf, &OutLen);
	system("pause"); 
	return 0;
}

