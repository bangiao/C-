//��Ϊ���̶��Լ������ʵ��
#define  _CRT_SECURE_NO_WARNINGS
#include "CEncDesProtocol.h"
#include "HwEncDes.h"
#include <iostream>
#include "des.h"
using namespace std;

int HwEncDes::EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen)
{
	int ret = 0;
	//�û�ʹ�õĺ���
	ret = DesEnc(plain, plainlen, cryptdata, cryptlen);
	if (0 != ret)
	{
		return ret;
	}
	return ret;
}
int HwEncDes::DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen)
{
	int ret = 0;
	//�û�ʹ�ú���des����
	ret = DesDec(cryptdata, cryptlen, plain, plainlen);
	if (0 != ret)
	{
		return ret;
	}
	return ret;
}