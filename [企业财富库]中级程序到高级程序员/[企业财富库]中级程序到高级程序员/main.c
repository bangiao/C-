#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Socket.h"
#include "des.h"

/*
typedef int(*EncDataFunc)(unsigned char *inData, int inLen, unsigned char *outData, int outLen);
typedef int(*DecDataFunc)(unsigned char *inData, int inLen, unsigned char *outData, int outLen);
*/

int mainOP(void *Handle, unsigned char *inData, int inLen, unsigned char *outData, int *outLen)
{
	int ret = 0;
	if (NULL == inData || inLen <= 0 || NULL == outData || NULL == outLen)
	{
		return -1;
	}
	
	ret = Socket_Init(&Handle);
	if (0 != ret)
	{
		goto End;
	}
	ret = Socket_SetEnc(Handle, DesEnc, DesDec);
	if (0 != ret)
	{
		goto End;
	}

	ret = Socket_Send(Handle, inData, inLen);
	if (0 != ret)
	{
		goto End;
	}

	ret = Socket_Res(Handle, outData, outLen);
	if (0 != ret)
	{
		goto End;
	}

End:
	Socket_Destory(&Handle);
	return 0;
}

int main(int argv, char *args[])
{
	void *Handle = NULL;
	unsigned char inData[4096] = "abcdef";
	int inLen = strlen(inData) + 1;
	unsigned char outData[4096];
	int outLen = 0;
	int ret = 0;
	ret = mainOP(Handle, inData, inLen, outData, &outLen);
	if (0 != ret)
	{
		return -1;
	}
	printf("hello world...\n");
	system("pause");
	return 0;
}