//这个是华为(第三方厂商)的对应中石油的接口类写的自己的子类
#pragma once
#include "CEncDesProtocol.h"
class HwEncDes : public CEncDesProtocol
{
public:
	int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);
	int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);
};
