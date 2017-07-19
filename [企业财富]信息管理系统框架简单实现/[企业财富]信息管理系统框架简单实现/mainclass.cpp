//中石油的业务
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>		//c++头文件
//消息发送文件
#include "SocketProtocol.h"	//接口类头文件
//这个头文件是后面的第三方厂家加进来的写这个架构的时候并不知道这个名字
#include "SocketFactoryIMP1.h"//第三方厂商的头文件
//加密文件
#include "CEncDesProtocol.h"
#include "HwEncDes.h"
#include "mainclass.h"

using namespace std;

MainOp::MainOp(CSocketProtocol *pBase, CEncDesProtocol *ed)
{
	this->pBase = pBase;
	this->ed = ed;
}
MainOp::~MainOp()
{
}
int MainOp::SocketSendAndRev(unsigned char *inbuf, int inlen, unsigned char *outbuf, int *outlen)
{
	int ret = 0;
	unsigned char Data[4096];
	int DataLen = 0;

	ret = pBase->cltSocketInit();
	if (0 != ret)
	{
		goto End;
	}
	ret = ed->EncData(inbuf, inlen, Data, &DataLen);
	if (0 != ret)
	{
		goto End;
	}
	ret = pBase->cltSocketSend(Data, DataLen);
	if (0 != ret)
	{
		goto End;
	}
	ret = pBase->cltSocketRev(Data, &DataLen);
	if (0 != ret)
	{
		goto End;
	}
	ret = ed->DecData(Data, DataLen, outbuf, outlen);
	if (0 != ret)
	{
		goto End;
	}
End:
	pBase->cltSocketDestory();
	return 0;
}