#pragma once
#include "SocketProtocol.h"	//�ӿ���ͷ�ļ�
//���ͷ�ļ��Ǻ���ĵ��������Ҽӽ�����д����ܹ���ʱ�򲢲�֪���������
#include "SocketFactoryIMP1.h"//���������̵�ͷ�ļ�
//�����ļ�
#include "CEncDesProtocol.h"
#include "HwEncDes.h"

//��ϵķ���д�����
class MainOp
{
public:
	MainOp(CSocketProtocol *pBase, CEncDesProtocol *ed);
	~MainOp();
	int SocketSendAndRev(unsigned char *inbuf, int inlen, unsigned char *outbuf, int *outlen);
private:
	CSocketProtocol *pBase;
	CEncDesProtocol *ed;
};