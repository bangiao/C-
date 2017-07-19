#pragma once
#include "cltsocket.h"
class SocketIMP1 : public SocketIF
{
public:
	SocketIMP1();
	~SocketIMP1();
	//客户端初始化环境
// 	int cltSocket_init();

	//客户端发报文
	int cltSocket_senddata(unsigned char *buf, int buflen);

	//客户端收报文
	int cltSocket_resvdata(unsigned char *buf, int *buflen);

	//4 客户端销毁环境
	int cltSocket_destory();
private:
	unsigned char *Buf;
	int BufLen;
};

