//这是第三方厂商根据中石油的接口类继承而来的头文件
//这里面要继承后可以写入下层的数据类型 unsigned char *Data 和 int Datalen
#pragma once
#include "SocketProtocol.h"

class CSocketFactoryIMP1 : public CSocketProtocol
{
public:
	int cltSocketInit();
	int cltSocketSend(void *inbuf, int inlen);
	int cltSocketRev(void *outbuf, int *outlen);
	void cltSocketDestory();
//	int print();
protected:
private:
	unsigned char *Data;
	int DataLen;
};
