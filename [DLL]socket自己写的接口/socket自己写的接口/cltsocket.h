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
	//�ͻ��˳�ʼ������
// 	virtual int cltSocket_init() = 0;

	//�ͻ��˷�����
	virtual int cltSocket_senddata(unsigned char *buf, int buflen) = 0;

	//�ͻ����ձ���
	virtual int cltSocket_resvdata(unsigned char *buf, int *buflen) = 0;

	//4 �ͻ������ٻ���
	virtual int cltSocket_destory() = 0;
};
