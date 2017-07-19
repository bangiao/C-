#pragma once
#include "socketprotocol.h"
class socketIMP1 : public SocketIF
{
public:
	socketIMP1();
	virtual ~socketIMP1();
	//客户端初始化环境
// 	int cltSocket_init();
	//客户端发报文
	int cltSocket_senddata(unsigned char *buf, int buflen);
	//客户端收报文
	int cltSocket_resvdata(unsigned char *buf, int *buflen);
	//4 客户端销毁环境
	void cltSocket_destory();
private:
	char *m_buf;
	int m_bufLen;
};
