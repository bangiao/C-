#pragma once
#include "socketprotocol.h"
class socketIMP1 : public SocketIF
{
public:
	socketIMP1();
	virtual ~socketIMP1();
	//�ͻ��˳�ʼ������
// 	int cltSocket_init();
	//�ͻ��˷�����
	int cltSocket_senddata(unsigned char *buf, int buflen);
	//�ͻ����ձ���
	int cltSocket_resvdata(unsigned char *buf, int *buflen);
	//4 �ͻ������ٻ���
	void cltSocket_destory();
private:
	char *m_buf;
	int m_bufLen;
};
