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


//这里是业务区
int main(int argv, char *args[])
{
	unsigned char inbuf[4096] = "abcdef";
	int inlen = strlen((char *)inbuf) + 1;
	unsigned char outbuf[4096];
	int outlen = 0;
	int ret = 0;

	CSocketFactoryIMP1 Head;
	HwEncDes ed;

	MainOp *pMainOP = new MainOp(&Head, &ed);

	//这个是架构
	ret = pMainOP->SocketSendAndRev(inbuf, inlen, outbuf, &outlen);
	if (0 != ret)
	{
		return ret;
	}
	printf("hello world...\n");
	system("pause");
	return 0;
}