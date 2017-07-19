//第三方:这个是函数的实现
#define  _CRT_SECURE_NO_WARNINGS
#include "SocketFactoryIMP1.h"
#include <iostream>
using namespace std;

int CSocketFactoryIMP1::cltSocketInit()
{
	this->Data = NULL;
	this->DataLen = 0;
	return 0;
}
int CSocketFactoryIMP1::cltSocketSend(void *inbuf, int inlen)
{
	if (NULL == inbuf && 0 <= inlen)
	{
		return -1;
	}
	this->Data = new unsigned char[inlen];
	if (NULL == this->Data)
	{
		return -1;
	}
	memset(this->Data, 0, sizeof(char) * inlen);
	memcpy(this->Data, inbuf, inlen);
	this->DataLen = inlen;
	return 0;
}
int CSocketFactoryIMP1::cltSocketRev(void *outbuf, int *outlen)
{
	if (NULL == outbuf || NULL == outlen)
	{
		return -1;
	}
	memset(outbuf, 0, sizeof(unsigned char) * (*outlen));
	memcpy(outbuf, this->Data, this->DataLen);
	*outlen = this->DataLen;
	return 0;
}
void CSocketFactoryIMP1::cltSocketDestory()
{
	if (NULL != this->Data)
	{
		delete this->Data;
	}
	return;
}
// 
// int CSocketFactoryIMP1::print()
// {
// 	
// }
