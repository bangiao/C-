//���ǵ��������̸�����ʯ�͵Ľӿ���̳ж�����ͷ�ļ�
//������Ҫ�̳к����д���²���������� unsigned char *Data �� int Datalen
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
