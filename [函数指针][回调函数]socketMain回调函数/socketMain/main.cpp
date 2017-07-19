#include <iostream>
#include "socketDLL.h"
using namespace std;


/*
typedef int(*EncFunc)(char *inBuf, int inBufLen, char *OutBuf, int *OutLen);
typedef int(*DecFunc)(char *inBuf, int inBufLen, char *OutBuf, int *OutLen);
*/
//这个是其他dll中的函数  这里为了简单点 就写在这里
int EncDataFuncM(char *inBuf, int inBufLen, char *OutBuf, int *OutLen)
{
	int ret = 0;
	memcpy(OutBuf, inBuf, inBufLen);
	*OutBuf = inBufLen;
	return ret;
}

int mainOP(SocketIF *pBase)
{
	int ret = 0;
	char inBuf[1024] = "1111111111111111";
	int inBufLen = 10;
	char *OutBuf = NULL;
	int OutLen = 0;

	pBase->SocketSend(inBuf, inBufLen, EncDataFuncM);
	return ret;
}

int main()
{
	SocketIF *pBase = NULL;

	pBase = new SocketIF();
	mainOP(pBase);
	system("pause");
	return 0;
}