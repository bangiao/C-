#pragma once
class SocketIF
{
public:
	SocketIF()
	{

	}
	virtual ~SocketIF()
	{

	}
	//客户端初始化环境
// 	virtual int cltSocket_init() = 0;

	//客户端发报文
	virtual int cltSocket_senddata(unsigned char *buf, int buflen) = 0;

	//客户端收报文
	virtual int cltSocket_resvdata(unsigned char *buf, int *buflen) = 0;

	//4 客户端销毁环境
	virtual int cltSocket_destory() = 0;
};
