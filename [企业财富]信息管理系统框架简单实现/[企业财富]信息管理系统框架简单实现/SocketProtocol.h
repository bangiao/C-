//����ļ�������ʯ�ͷ����Ľӿ���, ����ҵ�����ݷ��ͽӿ��� �����������̽��м̳б�д������
#pragma once
class CSocketProtocol
{
public:
	CSocketProtocol(){}
	virtual ~CSocketProtocol(){};
	virtual int cltSocketInit() = 0;
	virtual int cltSocketSend(void *inbuf, int inlen) = 0;
	virtual int cltSocketRev(void *outbuf, int *outlen) = 0;
	virtual void cltSocketDestory() = 0;
};
