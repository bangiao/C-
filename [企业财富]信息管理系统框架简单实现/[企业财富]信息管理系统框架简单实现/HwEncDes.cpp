//华为厂商对自己的类的实现
#define  _CRT_SECURE_NO_WARNINGS
#include "CEncDesProtocol.h"
#include "HwEncDes.h"
#include <iostream>
#include "des.h"
using namespace std;

int HwEncDes::EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen)
{
	int ret = 0;
	//用户使用的函数
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
	//用户使用函数des解密
	ret = DesDec(cryptdata, cryptlen, plain, plainlen);
	if (0 != ret)
	{
		return ret;
	}
	return ret;
}