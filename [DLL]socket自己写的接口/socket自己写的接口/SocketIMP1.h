#pragma once
#include "cltsocket.h"
class SocketIMP1 : public SocketIF
{
public:
	SocketIMP1();
	~SocketIMP1();
	//�ͻ��˳�ʼ������
// 	int cltSocket_init();

	//�ͻ��˷�����
	int cltSocket_senddata(unsigned char *buf, int buflen);

	//�ͻ����ձ���
	int cltSocket_resvdata(unsigned char *buf, int *buflen);

	//4 �ͻ������ٻ���
	int cltSocket_destory();
private:
	unsigned char *Buf;
	int BufLen;
};

