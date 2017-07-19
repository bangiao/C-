#include "SocketIMP1.h"
#include <iostream>
using namespace std;

SocketIMP1::SocketIMP1()
{
	this->Buf = NULL;
	this->BufLen = 0;
}

SocketIMP1::~SocketIMP1()
{
	this->Buf = NULL;
	this->BufLen = 0;
}

//客户端初始化环境
// int SocketIMP1::cltSocket_init()
// {
// 	return 0;
// }

//客户端发报文
int SocketIMP1::cltSocket_senddata(unsigned char *buf, int buflen)
{
	int ret = 0;
	if (NULL == buf || 0 == buflen)
	{
		ret = -1;
		return ret;
	}
	this->Buf = new unsigned char[1024];
	if (NULL == this->Buf)
	{
		ret = -2;
		return ret;
	}
	memcpy(this->Buf, buf, buflen);
	this->BufLen = buflen;
	return 0;
}

//客户端收报文
int SocketIMP1::cltSocket_resvdata(unsigned char *buf, int *buflen)
{
	memcpy(buf, this->Buf, this->BufLen);
	*buflen = this->BufLen;
	return 0;
}

//4 客户端销毁环境
int SocketIMP1::cltSocket_destory()
{
	if (NULL != this->Buf)
	{
		delete[]this->Buf;
		this->Buf = NULL;
	}
	this->BufLen = 0;
	return 0;
}