//这个文件是由中石油发出的接口类, 用于业务数据发送接口类 给第三方厂商进行继承编写的条件
#pragma once
class CSocketProtocol
{
public:
	CSocketProtocol(){}
	virtual ~CSocketProtocol(){};
	virtual int cltSocketInit() = 0;
	virtual int cltSocketSend(void *inbuf, int inlen) = 0;
	virtual int cltSocketRev(void *outbuf, int *outlen) = 0;
	virtual void cltSocketDestory() = 0;
};
