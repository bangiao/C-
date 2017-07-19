#pragma once
class __declspec(dllexport) socketIF : public ChinaSocketDLL
{
public:
	socketIF()
	{

	}
	virtual ~socketIF()
	{

	}
	virtual int socket_send(char *inBuf, int inLen, char *OutBuf, int *OutLen) = 0;
	virtual int socket_rev(char *inBuf, int inLen, char *OutBuf, int *OutLen) = 0;
protected:
	char *m_buf;
	int BufLen;
};