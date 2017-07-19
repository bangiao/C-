#pragma once
//提前定义好协议
typedef int(*EncFunc)(char *inBuf, int inBufLen, char *OutBuf, int *OutLen);
typedef int(*DecFunc)(char *inBuf, int inBufLen, char *OutBuf, int *OutLen);

class SocketIF
{
public:
	__declspec(dllexport)
	SocketIF();
	
	__declspec(dllexport)
	~SocketIF();
	
	__declspec(dllexport)
		int SocketSend(char *inBuf, int inBufLen, EncFunc EncDataCallBakFunc);
		
	__declspec(dllexport)
		int SocketRev(char *inBuf, int *inBufLen, DecFunc DecDataCallBakFunc);
		
protected:
	char *m_buf;
	int m_buflen;

	EncFunc EncCallBack;

	DecFunc DecCallBack;
};