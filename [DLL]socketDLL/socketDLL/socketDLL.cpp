#include "socketDLL.h"
#include <iostream>
using namespace std;

SocketIF::SocketIF()
{
	this->m_buf = NULL;
	this->m_buflen = 0;
}
SocketIF::~SocketIF()
{
	if (NULL != this->m_buf)
	{
		delete[]this->m_buf;
		this->m_buf = NULL;
	}
}

// int SocketIF::SocketInit()
// {
// 	return 0;
// }
int SocketIF::SocketSend(char *inBuf, int inBufLen, EncFunc EncDataCallBakFunc)
{
	int ret = 0;

	this->m_buf = new char[(inBufLen + 128) * sizeof(char)];
	if (NULL != EncDataCallBakFunc)
	{
		ret  = EncDataCallBakFunc(inBuf, inBufLen, this->m_buf, &this->m_buflen);
		if (-1 == ret)
		{
			return ret;
		}
	}
	else
	{
		memcpy(this->m_buf, inBuf, inBufLen);
		this->m_buflen = inBufLen;
	}

	return 0;
}
int SocketIF::SocketRev(char *inBuf, int *inBufLen, DecFunc DecDataCallBakFunc)
{
	int ret = 0;

	if (NULL != DecDataCallBakFunc)
	{
		ret = DecDataCallBakFunc(this->m_buf, this->m_buflen, inBuf, inBufLen);
		if (-1 == ret)
		{
			return ret;
		}
	}
	else
	{
		memcpy(inBuf, this->m_buf, this->m_buflen);
		*inBufLen = this->m_buflen;
	}
	return 0;
}
// int SocketIF::SocketDestory()
// {
// 	if (NULL != this->m_buf)
// 	{
// 		delete[]this->m_buf;
// 		this->m_buf = NULL;
// 	}
// 	return 0;
//}