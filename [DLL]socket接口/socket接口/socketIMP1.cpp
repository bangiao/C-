#include "socketIMP1.h"
#include <iostream>
using namespace std;


socketIMP1::socketIMP1()
{
	this->m_buf = NULL;
	this->m_buf = 0;
}


socketIMP1::~socketIMP1()
{
	if (NULL != this->m_buf)
	{
		delete[]this->m_buf;
		this->m_buf = NULL;
	}
	this->m_bufLen = 0;
}


//客户端初始化环境
// int socketIMP1::cltSocket_init()
// {
// 	this->buf = NULL;
// 	this->bufLen = 0;
// 	return 0;
// }

//客户端发报文
int socketIMP1::cltSocket_senddata(unsigned char *buf, int buflen)
{
	int ret = 0;
	if (NULL == buf)
	{
		ret = -1;
		return ret;
	}
	this->m_buf = new char[buflen * sizeof(char)];
	if (NULL == this->m_buf)
	{
		ret = -2;
		return ret;
	}
	memcpy(this->m_buf, buf, buflen * sizeof(char));
	this->m_bufLen = buflen;
	return 0;
}

//客户端收报文
int socketIMP1::cltSocket_resvdata(unsigned char *buf, int *buflen)
{
	int ret = 0;
	if (NULL == buf || NULL == buflen)
	{
		ret = -1;
		return ret;
	}
	memcpy(buf, this->m_buf, this->m_bufLen * sizeof(char));
	*buflen = this->m_bufLen;
	return 0;
}

//4 客户端销毁环境
void socketIMP1::cltSocket_destory()
{
	if (NULL != this->m_buf)
	{
		delete[]this->m_buf;
		this->m_buf = NULL;
	}
	this->m_bufLen = 0;
}