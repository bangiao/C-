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


//������ҵ����
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

	//����Ǽܹ�
	ret = pMainOP->SocketSendAndRev(inbuf, inlen, outbuf, &outlen);
	if (0 != ret)
	{
		return ret;
	}
	printf("hello world...\n");
	system("pause");
	return 0;
}