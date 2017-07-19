//��ʯ�͵�ҵ��
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>		//c++ͷ�ļ�
//��Ϣ�����ļ�
#include "SocketProtocol.h"	//�ӿ���ͷ�ļ�
//���ͷ�ļ��Ǻ���ĵ��������Ҽӽ�����д����ܹ���ʱ�򲢲�֪���������
#include "SocketFactoryIMP1.h"//���������̵�ͷ�ļ�
//�����ļ�
#include "CEncDesProtocol.h"
#include "HwEncDes.h"
#include "mainclass.h"

using namespace std;

MainOp::MainOp(CSocketProtocol *pBase, CEncDesProtocol *ed)
{
	this->pBase = pBase;
	this->ed = ed;
}
MainOp::~MainOp()
{
}
int MainOp::SocketSendAndRev(unsigned char *inbuf, int inlen, unsigned char *outbuf, int *outlen)
{
	int ret = 0;
	unsigned char Data[4096];
	int DataLen = 0;

	ret = pBase->cltSocketInit();
	if (0 != ret)
	{
		goto End;
	}
	ret = ed->EncData(inbuf, inlen, Data, &DataLen);
	if (0 != ret)
	{
		goto End;
	}
	ret = pBase->cltSocketSend(Data, DataLen);
	if (0 != ret)
	{
		goto End;
	}
	ret = pBase->cltSocketRev(Data, &DataLen);
	if (0 != ret)
	{
		goto End;
	}
	ret = ed->DecData(Data, DataLen, outbuf, outlen);
	if (0 != ret)
	{
		goto End;
	}
End:
	pBase->cltSocketDestory();
	return 0;
}