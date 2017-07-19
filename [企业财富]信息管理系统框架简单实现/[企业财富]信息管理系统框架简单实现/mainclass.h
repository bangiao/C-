#pragma once
#include "SocketProtocol.h"	//接口类头文件
//这个头文件是后面的第三方厂家加进来的写这个架构的时候并不知道这个名字
#include "SocketFactoryIMP1.h"//第三方厂商的头文件
//加密文件
#include "CEncDesProtocol.h"
#include "HwEncDes.h"

//组合的方法写框架类
class MainOp
{
public:
	MainOp(CSocketProtocol *pBase, CEncDesProtocol *ed);
	~MainOp();
	int SocketSendAndRev(unsigned char *inbuf, int inlen, unsigned char *outbuf, int *outlen);
private:
	CSocketProtocol *pBase;
	CEncDesProtocol *ed;
};