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

//�ͻ��˳�ʼ������
// int SocketIMP1::cltSocket_init()
// {
// 	return 0;
// }

//�ͻ��˷�����
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

//�ͻ����ձ���
int SocketIMP1::cltSocket_resvdata(unsigned char *buf, int *buflen)
{
	memcpy(buf, this->Buf, this->BufLen);
	*buflen = this->BufLen;
	return 0;
}

//4 �ͻ������ٻ���
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